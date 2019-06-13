#ifndef APPLICATION_GRID_TEST_H_
#define APPLICATION_GRID_TEST_H_

#include "application/Application.h"
#include "Types.h"
#include "thread.hpp"

namespace grid
{
    class Grid;
    class AdditionalButtons;
}

namespace midi
{
    class UsbMidi;
}

namespace lcd
{
    class Gui;
}

namespace application
{

class GridTest : public Application
{
public:
    GridTest( ApplicationController& applicationController, grid::Grid& grid, midi::UsbMidi& usbMidi, lcd::Gui& gui );

private:
    void run( ApplicationThread& thread );

    void displayIntroAnimation( ApplicationThread& thread );

    Color getIntroAnimationColor( const uint8_t ledPositionX, const uint8_t ledPositionY );
    Color getRandomColor();

    void handleAdditionalButtonEvent( const grid::AdditionalButtons::Event event );
    void handleGridButtonEvent( const grid::Grid::ButtonEvent event );
    void handleMidiPacketAvailable();

    grid::Grid& grid_;
    lcd::Gui& gui_;
};

} // namespace

#endif // APPLICATION_GRID_TEST_H_