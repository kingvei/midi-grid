#include "application/grid_test/GridTest.hpp"

#include "grid/GridInterface.h"
#include "types/Color.h"
#include "usb/UsbMidi.hpp"
#include "lcd/LcdInterface.h"
#include "application/images.h"

#include <freertos/ticks.hpp>

#include <cstdlib>
#include <etl/array.h>

namespace application
{

static const lcd::ImageLegacy usbLogo = { &usbLogoArray[0], 60, 24 };

GridTest::GridTest( ApplicationController& applicationController, grid::GridInterface& grid, lcd::LcdInterface& lcd, midi::UsbMidi& usbMidi ):
    Application( applicationController ),
    grid_( grid ),
    lcd_( lcd )
{
    std::srand( static_cast<uint16_t>(freertos::Ticks::GetTicks()) ); // change seed for that extra randomness
}

void GridTest::run( ApplicationThread& thread )
{
    static bool introAnimationDisplayed = false;
    if (!introAnimationDisplayed)
    {
        displayIntroAnimation( thread );
        introAnimationDisplayed = true;
    }

    displayWaitingForMidi();
    grid_.turnAllLedsOff();

    enableGridInputHandler();
    enableAdditionalButtonInputHandler();
    enableMidiInputAvailableHandler();
}

void GridTest::handleAdditionalButtonEvent( const additional_buttons::Event& event )
{
    if ((additional_buttons::Button::internalMenu == event.button) && (ButtonAction::PRESSED == event.action))
    {
        switchApplication( ApplicationIndex_INTERNAL_MENU );
    }
}

void GridTest::handleGridButtonEvent( const grid::ButtonEvent& event )
{
    Color color( 0, 0, 0 );
    if (ButtonAction::PRESSED == event.action)
    {
        color = getRandomColor();
    }
    grid_.setLed( event.coordinates, color );
}

void GridTest::handleMidiPacketAvailable()
{
    switchApplication( ApplicationIndex_LAUNCHPAD );
}

void GridTest::displayIntroAnimation( ApplicationThread& thread )
{
    static const uint8_t totalNumberOfSteps = 8;
    static const TickType_t delayPeriod = freertos::Ticks::MsToTicks( 70 );

    grid_.turnAllLedsOff();

    for (uint8_t currentStepNumber = 0; currentStepNumber < totalNumberOfSteps; currentStepNumber++)
    {
        for (uint8_t x = 0; x <= currentStepNumber; x++)
        {
            const uint8_t y = currentStepNumber;
            grid_.setLed( {x, y}, getIntroAnimationColor( x, y ) );
            grid_.setLed( {static_cast<uint8_t>(7U - x), static_cast<uint8_t>(7U - y)},
                getIntroAnimationColor( static_cast<uint8_t>(7U - x), static_cast<uint8_t>(7U - y) ) );
        }

        for (uint8_t y = 0; y <= currentStepNumber; y++)
        {
            const uint8_t x = currentStepNumber;
            grid_.setLed( {x, y}, getIntroAnimationColor( x, y ) );
            grid_.setLed( {static_cast<uint8_t>(7U - x), static_cast<uint8_t>(7U - y)},
                getIntroAnimationColor( static_cast<uint8_t>(7U - x), static_cast<uint8_t>(7U - y) ) );
        }
        
        thread.delay( delayPeriod );
        grid_.turnAllLedsOff();
    }
}

/* calculates color value according to led position */
Color GridTest::getIntroAnimationColor( const uint8_t ledPositionX, const uint8_t ledPositionY ) const
{
    const Color color(
        ((7 - std::max( ledPositionY, static_cast<uint8_t>(7U - ledPositionX) )) * 64) / 7,
        (abs( 7 - ledPositionX - ledPositionY ) * 64) / 7,
        ((7 - std::max( ledPositionX, static_cast<uint8_t>(7U - ledPositionY) )) * 64) / 7 );

    return color;
}

Color GridTest::getRandomColor()
{
    const etl::array<Color, 13> color = {
    color::RED,
    color::GREEN,
    color::BLUE,
    color::YELLOW,
    color::MAGENTA,
    color::CYAN,
    color::WHITE,
    color::ORANGE,
    color::SPRING_GREEN,
    color::TURQUOISE,
    color::OCEAN,
    color::VIOLET,
    color::RASPBERRY };

    return color[std::rand() % color.size()];
}

void GridTest::displayWaitingForMidi()
{
    lcd_.image().createNew( color::BLACK );
    lcd_.text().print( "Awaiting MIDI", 40, lcd::Format().justification( lcd::Justification::CENTER ) );
    lcd_.image().display();
}

}  // namespace application
