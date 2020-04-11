#pragma once

#include "hardware/lcd/SpiInterface.h"

#include <gmock/gmock.h>

namespace hardware
{

namespace lcd
{

class MockSpi : public SpiInterface
{
public:
    MOCK_METHOD( void, initialize, (), (const, override) );

    MOCK_METHOD( void, reset, (), (const, override) );
    MOCK_METHOD( void, writeCommand, (const uint8_t command), (const, override) );
    MOCK_METHOD( void, writeData, (const uint8_t& data, const uint32_t size), (const, override) );
    MOCK_METHOD( void, writeData, (const etl::array_view<uint8_t>& data), (const, override) );
};

}

}
