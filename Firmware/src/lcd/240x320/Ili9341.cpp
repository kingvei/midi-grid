#include "lcd/240x320/Ili9341.h"
#include "hardware/lcd/SpiInterface.h"
#include "lcd/Format.h"
#include "lcd/LcdInterface.h"
#include "lcd/ImageMono.h"
#include "ThreadConfigurations.h"

#include "lcd/Font.h"

#include <freertos/ticks.hpp>
#include <etl/algorithm.h>
#include <etl/absolute.h>

#include "system/System.hpp" // TODO(unknown): remove
#include "types/Coordinates.h"

namespace lcd
{

enum class Command : uint8_t
{
    NOP = 0x00,
    SWRESET = 0x01,
    RDDID = 0x04,
    RDDST = 0x09,
    SLPIN = 0x10,
    SLPOUT = 0x11,
    PTLON = 0x12,
    NORON = 0x13,
    RDMODE = 0x0A,
    RDMADCTL = 0x0B,
    RDPIXFMT = 0x0C,
    RDIMGFMT = 0x0A,
    RDSELFDIAG = 0x0F,
    INVOFF = 0x20,
    INVON = 0x21,
    GAMMASET = 0x26,
    DISPOFF = 0x28,
    DISPON = 0x29,
    CASET = 0x2A,
    PASET = 0x2B,
    RAMWR = 0x2C,
    RAMRD = 0x2E,
    PTLAR = 0x30,
    VSCRDEF = 0x33,
    MADCTL = 0x36,
    VSCRSADD = 0x37,
    PIXFMT = 0x3A,
    FRMCTR1 = 0xB1,
    FRMCTR2 = 0xB2,
    FRMCTR3 = 0xB3,
    INVCTR = 0xB4,
    DFUNCTR = 0xB6,
    PWCTR1 = 0xC0,
    PWCTR2 = 0xC1,
    PWCTR3 = 0xC2,
    PWCTR4 = 0xC3,
    PWCTR5 = 0xC4,
    VMCTR1 = 0xC5,
    VMCTR2 = 0xC7,
    RDID1 = 0xDA,
    RDID2 = 0xDB,
    RDID3 = 0xDC,
    RDID4 = 0xDD,
    GMCTRP1 = 0xE0,
    GMCTRN1 = 0xE1
};

Ili9341::Ili9341( hardware::lcd::SpiInterface* spi ):
    spi_( *spi ),
    pixelBuffer_(),
    pixelBufferIndex_( 0 ),
    dataBuffer_(),
    dataBufferIndex_( 0 ),
    imageData_(),
    zeros_()
{
}

Ili9341::~Ili9341() = default;

void Ili9341::initialize()
{
    spi_.initialize();
    spi_.reset();

    spi_.writeCommand( 0xEF );
    DataBuffer& buffer = assignDataBuffer();
    buffer = {0x03, 0x80, 0x02};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xCF );
    buffer = assignDataBuffer();
    buffer = {0x00, 0xC1, 0x30};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xED );
    buffer = assignDataBuffer();
    buffer = {0x64, 0x03, 0x12, 0x81};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xE8 );
    buffer = assignDataBuffer();
    buffer = {0x85, 0x00, 0x78};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xCB );
    buffer = assignDataBuffer();
    buffer = {0x39, 0x2C, 0x00, 0x34, 0x02};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xF7 );
    buffer = assignDataBuffer();
    buffer = {0x20};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xEA );
    buffer = assignDataBuffer();
    buffer = {0x00, 0x00};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::PWCTR1) );
    buffer = assignDataBuffer();
    buffer = {0x23};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::PWCTR2) );
    buffer = assignDataBuffer();
    buffer = {0x10};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::VMCTR1) );
    buffer = assignDataBuffer();
    buffer = {0x3e, 0x28};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::VMCTR2) );
    buffer = assignDataBuffer();
    buffer = {0x86};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::MADCTL) );
    buffer = assignDataBuffer();
    buffer = {0x08}; // ILI9341_MADCTL_BGR
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::PIXFMT) );
    buffer = assignDataBuffer();
    buffer = {0x66};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::FRMCTR1) );
    buffer = assignDataBuffer();
    buffer = {0x00, 0x18};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::DFUNCTR) );
    buffer = assignDataBuffer();
    buffer = {0x08, 0x82, 0x27};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( 0xF2 );
    buffer = assignDataBuffer();
    buffer = {0x00};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::GAMMASET) );
    buffer = assignDataBuffer();
    buffer = {0x01};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::GMCTRP1) );
    buffer = assignDataBuffer();
    buffer = {0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::GMCTRN1) );
    buffer = assignDataBuffer();
    buffer = {0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F};
    spi_.writeData( hardware::lcd::RawDataView(buffer) );

    spi_.writeCommand( static_cast<uint8_t>(Command::SLPOUT) );
    
    mcu::System::delayDirty( 150 ); // TODO(unknown): remove

    spi_.writeCommand( static_cast<uint8_t>(Command::DISPON) );

    mcu::System::delayDirty( 500 ); // TODO(unknown): remove

    spi_.writeCommand( static_cast<uint8_t>(Command::MADCTL) );
    buffer = assignDataBuffer();
    buffer = {0xA8}; // ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR
    spi_.writeData( hardware::lcd::RawDataView(buffer) );
}

void Ili9341::fill( const Color& color )
{
    fillArea( {0, 0}, {width_-1, height_-1}, color );
}

void Ili9341::fillArea( const Coordinates& corner1, const Coordinates& corner2, const Color& color )
{
    const Coordinates topLeft = {std::min(corner1.x, corner2.x), std::min(corner1.y, corner2.y)};
    const Coordinates bottomRight = {std::max(corner1.x, corner2.x), std::max(corner1.y, corner2.y)};

    const uint16_t width = bottomRight.x - topLeft.x + 1;
    const uint16_t height = bottomRight.y - topLeft.y + 1;
    const uint16_t bytesPerColumn = (height + 7) / 8;
    const uint16_t dataSize = width * bytesPerColumn;

    imageData_.clear();
    if (dataSize <= imageData_.capacity())
    {
        imageData_.assign( dataSize, 0U );
    }

    const ImageMono fillImage( ImageMono::DataView(imageData_), width, height );
    putImage( topLeft, fillImage, {color::RED, color} );
}

void Ili9341::displayImage( const uint8_t x, const uint8_t y, const ImageLegacy& image )
{
}

void Ili9341::putImage( const Coordinates& coords, const ImageMono& image, const ImageColors& colors )
{
    const uint16_t width = std::min( image.getWidth(), static_cast<uint16_t>(width_ - coords.x) );
    const uint16_t height = std::min( image.getHeight(), static_cast<uint16_t>(height_ - coords.y) );

    const ImageMono imageClipped( image.getData(), width, image.getHeight() );

    PixelBuffer& buffer = assignPixelBuffer();
    const uint16_t scanlineHeight = buffer.capacity() / width;

    for (uint8_t i = 0; i < 2; i++)  // loop twice
    {
        for (uint16_t topY = i * scanlineHeight; topY < height; topY += 2 * scanlineHeight)
        {
            uint16_t bottomY = topY + scanlineHeight - 1;
            bottomY = std::min( bottomY, static_cast<uint16_t>(height - 1U) );  // clamp value if it's too high
            fillPixelBuffer( &buffer, imageClipped, colors, topY, bottomY );

            setWorkingArea( {coords.x, static_cast<uint16_t>(coords.y + topY)},
                {static_cast<uint16_t>(coords.x + width), static_cast<uint16_t>(coords.y + bottomY)} );
            spi_.writeCommand( static_cast<uint8_t>(Command::RAMWR) );
            spi_.writeData( PixelView(buffer) );

            buffer = assignPixelBuffer();
        }
    }
}

uint16_t Ili9341::putString( const etl::string_view& string, const Coordinates& coords )
{
    return putString( string, coords, Format() );
}

uint16_t Ili9341::putString( const etl::string_view& string, const Coordinates& coords, const Format& format )
{
    const uint16_t height = format.font().getHeight();
    const uint16_t bytesPerColumn = (height + 7) / 8;

    imageData_.clear();
    zeros_.assign( format.font().getLetterSpacingWidth() * bytesPerColumn, 0U );

    appendToImageData( format.font().getGlyph( string.at(0) ) ); // copy first glyph

    for (uint32_t c = 1; c < string.length(); c++)
    {
        appendToImageData( etl::array_view<const uint8_t>(zeros_) );  // copy space between characters
        appendToImageData( format.font().getGlyph( string.at(c) ) );  // copy glyph
    }

    const ImageMono stringImage( ImageMono::DataView(imageData_), imageData_.size() / bytesPerColumn, height );
    putImage( coords, stringImage, {format.textColor(), format.backgroundColor()} );

    return stringImage.getWidth();
}

uint16_t Ili9341::width() const
{
    return width_;
}

uint16_t Ili9341::height() const
{
    return height_;
}

uint16_t Ili9341::numberOfTextLines() const
{
    return numberOfTextLines_;
}

void Ili9341::setWorkingArea( const Coordinates& topLeft, const Coordinates& bottomRight )
{
    if (topLeft <= bottomRight)
    {
        spi_.writeCommand( static_cast<uint8_t>(Command::CASET) );
        DataBuffer& buffer = assignDataBuffer();
        buffer = {
            static_cast<uint8_t>(topLeft.y / 0x100U),
            static_cast<uint8_t>(topLeft.y % 0x100U),
            static_cast<uint8_t>(bottomRight.y / 0x100U),
            static_cast<uint8_t>(bottomRight.y % 0x100U) };
        spi_.writeData( hardware::lcd::RawDataView(buffer) );

        spi_.writeCommand( static_cast<uint8_t>(Command::PASET) );
        buffer = assignDataBuffer();
        buffer = {
            static_cast<uint8_t>(topLeft.x / 0x100U),
            static_cast<uint8_t>(topLeft.x % 0x100U),
            static_cast<uint8_t>(bottomRight.x / 0x100U),
            static_cast<uint8_t>(bottomRight.x % 0x100U) };
        spi_.writeData( hardware::lcd::RawDataView(buffer) );
    }
}

Ili9341::PixelBuffer& Ili9341::assignPixelBuffer()
{
    pixelBufferIndex_ = (pixelBufferIndex_ + 1) % pixelBuffer_.size();
    pixelBuffer_.at( pixelBufferIndex_ ).clear();
    return pixelBuffer_.at( pixelBufferIndex_ );
}

Ili9341::DataBuffer& Ili9341::assignDataBuffer()
{
    dataBufferIndex_ = (dataBufferIndex_ + 1) % dataBuffer_.size();
    dataBuffer_.at( dataBufferIndex_ ).clear();
    return dataBuffer_.at( dataBufferIndex_ );
}

void Ili9341::fillPixelBuffer( PixelBuffer* const buffer, const ImageMono& image, const ImageColors& colors,
    const uint16_t firstLine, const uint16_t lastLine )
{
    const uint16_t width = image.getWidth();
    const uint8_t bytesPerColumn = (image.getHeight() + 7) / 8;

    for (uint16_t x = 0; x < width; x++)
    {
        for (uint16_t y = firstLine; y <= lastLine; y++)
        {
            const uint8_t byte = image.getData().at( x * bytesPerColumn + y / 8U );
            const bool pixelActive = ((static_cast<uint8_t>(byte >> (y % 8U)) & 0x01U) != 0U);
            buffer->emplace_back( (pixelActive) ? colors.image : colors.background );
        }
    }
}

void Ili9341::appendToImageData( const etl::array_view<const uint8_t>& source )
{
    for (uint8_t i : source)
    {
        if (false == imageData_.full())
        {
            imageData_.emplace_back( i );
        }
        else
        {
            break;
        }
    }
}

} // namespace lcd
