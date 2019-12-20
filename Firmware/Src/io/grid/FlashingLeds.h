#pragma once

#include "io/grid/GridInterface.h"

#include "types/Color.h"
#include "types/Coordinates.h"

#include <freertos/thread.hpp>
#include <etl/array.h>
#include <etl/vector.h>

namespace grid
{

class LedOutputInterface;

static const uint8_t NUMBER_OF_FLASHING_COLORS = 2;
typedef etl::array<Color, NUMBER_OF_FLASHING_COLORS> FlashingColors;

class FlashingLeds: private freertos::Thread
{
public:
    FlashingLeds( LedOutputInterface& ledOutput );

    void add( const Coordinates& coordinates, const FlashingColors& color );
    void remove( const Coordinates& coordinates );
    void removeAll();

private:
    virtual void Run();

    void setOutputValues();

    struct FlashingLed
    {
        Coordinates coordinates;
        FlashingColors color;
    };

    LedOutputInterface& ledOutput_;
    etl::vector<FlashingLed, grid::NUMBER_OF_LEDS> led_;
};

}
