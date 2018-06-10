#include "lcd/Backlight.h"

#include <string.h>

namespace lcd
{

namespace backlight
{

Backlight::Backlight()
{
}

Backlight::~Backlight()
{
}

void Backlight::initialize()
{
    initializeGpio();
    initializeSpi();
    initializeDma();

    // start SPI transmission
    __HAL_SPI_ENABLE( &spiConfiguration_ );
}

void Backlight::setIntensity( uint8_t intensity )
{
    uint8_t wordIndex = 0;

    if (intensity >= NUMBER_OF_INTENSITY_LEVELS)
    {
        intensity = NUMBER_OF_INTENSITY_LEVELS - 1;
    }

    const uint16_t numberOfFullySetWords = INTENSITY[intensity] / 32;

    while (wordIndex < numberOfFullySetWords)
    {
        //fill fully set words with ones
        outputBuffer_[wordIndex++] = 0xFFFFFFFF;
    }

    if (wordIndex < OUTPUT_BUFFER_SIZE)
    {
        outputBuffer_[wordIndex++] = 0xFFFFFFFF >> (32 - (INTENSITY[intensity] % 32));
    }

    while (wordIndex < OUTPUT_BUFFER_SIZE)
    {
        // fill rest of the buffer with zeros
        outputBuffer_[wordIndex++] = 0x00000000;
    }
}

void Backlight::initializeDma()
{
    __HAL_RCC_DMA1_CLK_ENABLE();

    dmaConfiguration_.Instance = DMA1_Stream5;
    dmaConfiguration_.Init.Channel = DMA_CHANNEL_0;
    dmaConfiguration_.Init.Direction = DMA_MEMORY_TO_PERIPH;
    dmaConfiguration_.Init.PeriphInc = DMA_PINC_DISABLE;
    dmaConfiguration_.Init.MemInc = DMA_MINC_ENABLE;
    dmaConfiguration_.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    dmaConfiguration_.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    dmaConfiguration_.Init.Mode = DMA_CIRCULAR;
    dmaConfiguration_.Init.Priority = DMA_PRIORITY_MEDIUM;
    dmaConfiguration_.Init.PeriphBurst = DMA_PBURST_SINGLE;
    HAL_DMA_Init( &dmaConfiguration_ );
    __HAL_LINKDMA( &spiConfiguration_, hdmatx, dmaConfiguration_ );

    HAL_DMA_Start( &dmaConfiguration_,
            reinterpret_cast<uint32_t>(&outputBuffer_[0]),
            reinterpret_cast<uint32_t>(&spiConfiguration_.Instance->DR),
            OUTPUT_BUFFER_SIZE * sizeof(outputBuffer_[0]) );
}

void Backlight::initializeGpio()
{
    GPIO_InitTypeDef gpioConfiguration;

    __HAL_RCC_GPIOB_CLK_ENABLE();

    gpioConfiguration.Pin = LIGHT_Pin;
    gpioConfiguration.Mode = GPIO_MODE_AF_PP;
    gpioConfiguration.Pull = GPIO_NOPULL;
    gpioConfiguration.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    gpioConfiguration.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init( LCD_GPIO_Port, &gpioConfiguration );
}

void Backlight::initializeSpi()
{
    __HAL_RCC_SPI3_CLK_ENABLE();

    spiConfiguration_.Instance = SPI3;
    spiConfiguration_.Init.Mode = SPI_MODE_MASTER;
    spiConfiguration_.Init.Direction = SPI_DIRECTION_2LINES;
    spiConfiguration_.Init.DataSize = SPI_DATASIZE_8BIT;
    spiConfiguration_.Init.CLKPolarity = SPI_POLARITY_LOW;
    spiConfiguration_.Init.CLKPhase = SPI_PHASE_1EDGE;
    spiConfiguration_.Init.NSS = SPI_NSS_SOFT;
    spiConfiguration_.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256; // 100Mhz / (4*32)[BACKLIGHT_OUTPUT_BUFFER_SIZE] / 256 = ~3kHz
    spiConfiguration_.Init.FirstBit = SPI_FIRSTBIT_LSB;
    spiConfiguration_.Init.TIMode = SPI_TIMODE_DISABLE;
    spiConfiguration_.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    HAL_SPI_Init( &spiConfiguration_ );
    SET_BIT( spiConfiguration_.Instance->CR2, SPI_CR2_TXDMAEN ); // enable TX dma control bit
}

} // namespace backlight
} // namespace lcd
