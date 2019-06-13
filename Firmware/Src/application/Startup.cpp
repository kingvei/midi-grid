#include "application/Startup.h"

#include "grid/GridDriver.h"
#include "lcd/Gui.h"
#include "lcd/Lcd.h"
#include "system/System.h"

namespace application
{

Startup::Startup( ApplicationController& applicationController, grid::GridDriver& gridDriver,
    lcd::Gui& gui, lcd::Lcd& lcd, mcu::System& system ):
        Application( applicationController ),
        gridDriver_( gridDriver ),
        gui_( gui ),
        lcd_( lcd ),
        system_( system )
{
}

void Startup::run( ApplicationThread& thread )
{
    lcd_.initialize();
    lcd_.setBacklightIntensity( 60 );

    gridDriver_.initialize();
    gridDriver_.start();

    gui_.displayConnectingImage();

    while (!system_.isUsbConnected())
    {
    }

    switchApplication( ApplicationIndex_GRID_TEST );
}

} // namespace