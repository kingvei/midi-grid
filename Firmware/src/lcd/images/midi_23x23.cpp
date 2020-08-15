// This file is generated using convert.py script
// Editing it by hand would not be the best idea if you value your time

#include "lcd/ImageMono.h"

namespace lcd
{
namespace image
{

static const etl::array<uint8_t, 69> data = {
    0x00, 0x7F, 0x00, 0xC0, 0xFF, 0x01, 0xF0, 0xF7, 0x07, 0xF8, 0xE3, 0x0F, 0xFC, 0xE3, 0x1F, 0x9C, 0xE3, 0x1F, 0x1E,
    0xF7, 0x3F, 0x3E, 0xFF, 0x3F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x0F, 0xC7, 0xFF, 0x0F, 0x83, 0xFF, 0x0F, 0xC7, 0xFF,
    0x0F, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0x7F, 0x3E, 0xFF, 0x3F, 0x1E, 0xF7, 0x3F, 0x9C, 0xE3, 0x1F, 0xFC, 0xE3, 0x1F,
    0xF8, 0xE3, 0x0F, 0xF0, 0xF7, 0x07, 0xC0, 0xFF, 0x01, 0x00, 0x7F, 0x00
};

static const ImageMono img( ImageMono::DataView( data ), 23, 23 );

const ImageMono& midi_23x23 = img;

}  // namespace image
}  // namespace lcd