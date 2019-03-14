#include "main.h"

#include <math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef USE_SEMIHOSTING
extern void initialise_monitor_handles(void);
#endif

int main(void)
{
    ApplicationMain& applicationMain = ApplicationMain::getInstance();
    applicationMain.initialize();
    applicationMain.Start(); // doesn't return
    cpp_freertos::Thread::StartScheduler();
}

ApplicationMain::ApplicationMain() :
        Thread("main", 500, 1),
        system_( mcu::System() ),
        globalInterrupts_( mcu::GlobalInterrupts() ),
        time_( mcu::Time() ),
        gridDriver_( grid::GridDriver() ),
        grid_( grid::Grid( gridDriver_, globalInterrupts_, time_ ) ),
        switches_( grid::Switches( gridDriver_, time_ ) ),
        usbMidi_( midi::UsbMidi() ),
        lcd_( lcd::Lcd( time_ ) ),
        gui_( lcd::Gui( lcd_, time_ ) ),
        launchpad_( launchpad::Launchpad( grid_, switches_, gui_, usbMidi_ ) )
{}

ApplicationMain::~ApplicationMain()
{}

void ApplicationMain::initialize()
{
    globalInterrupts_.disable();
    system_.initialize();
}

void ApplicationMain::Run()
{
    lcd_.initialize();
    lcd_.setBacklightIntensity( 55 );

    gridDriver_.initialize();
    gridDriver_.start();

    gui_.displayConnectingImage();

    while (!system_.isUsbConnected())
    {
        gui_.refresh();
    }

    gui_.displayWaitingForMidi();

    while(!displayBootAnimation())
    {
    }

	while (!usbMidi_.isPacketAvailable())
	{
		uint8_t button;
		ButtonEvent event;
		if (switches_.getButtonEvent( button, event ))
		{
			if ((switches_.internalMenuButton == button) && (ButtonEvent_PRESSED == event))
			{
				runInternalMenu();

				// clear LEDs and display USB logo at the return from internal menu
				grid_.turnAllLedsOff();
				gui_.displayWaitingForMidi();
			}
		}
		//randomLightAnimation();
		runGridInputTest();
		gui_.refresh();
	}

    while (1)
    {
        launchpad_.runProgram();
        // program only returns here when red button is pressed
        if (switches_.isButtonPressed( switches_.internalMenuButton ))
        {
            runInternalMenu();
        }
    }
}

void ApplicationMain::randomLightAnimation()
{
    static uint32_t newLightTime = 0;

    if (time_.getSystemTick() >= newLightTime)
    {
        static uint8_t ledsChanged = 0;

        const uint8_t ledPositionX = rand() % 8;
        const uint8_t ledPositionY = rand() % 8;

        grid_.setLed(ledPositionX, ledPositionY, getRandomColor());
        newLightTime = time_.getSystemTick() + 500 + rand() % 1000;
        ledsChanged++;
        if (ledsChanged > 63)
        {
            grid_.turnAllLedsOff();
            ledsChanged = 0;
        }
    }
}

bool ApplicationMain::displayBootAnimation()
{
    bool animationEnded = false;

    static uint32_t stepChangeTime = 0;
    static uint8_t currentStepNumber = 0;
    const uint8_t totalNumberOfSteps = 8;

    if (time_.getSystemTick() >= stepChangeTime)
    {
        grid_.turnAllLedsOff();

        if (currentStepNumber < totalNumberOfSteps)
        {
            for (uint8_t x = 0; x <= currentStepNumber; x++)
            {
                const uint8_t y = currentStepNumber;
                grid_.setLed( x, y, getBootAnimationColor(x, y));
                grid_.setLed( 7-x, 7-y, getBootAnimationColor(7-x, 7-y));
            }

            for (uint8_t y = 0; y < currentStepNumber; y++)
            {
                const uint8_t x = currentStepNumber;
                grid_.setLed( x, y, getBootAnimationColor(x, y));
                grid_.setLed( 7-x, 7-y, getBootAnimationColor(7-x, 7-y));
            }

            currentStepNumber++;
        }
        else
        {
            animationEnded = true;
        }

        stepChangeTime = time_.getSystemTick() + 70; // step each 70ms
    }

    return animationEnded;
}

/* calculates color value according to led position */
Color ApplicationMain::getBootAnimationColor( const uint8_t ledPositionX, const uint8_t ledPositionY )
{
    Color color = {0, 0, 0};

    color.Red = ((7 - MAX( ledPositionY, 7 - ledPositionX )) * 64) / 7;
    color.Green = (abs( 7 - ledPositionX - ledPositionY ) * 64) / 7;
    color.Blue = ((7 - MAX( ledPositionX, 7 - ledPositionY )) * 64) / 7;

    return color;
}

void ApplicationMain::runGridInputTest()
{
    uint8_t buttonX, buttonY;
    ButtonEvent event;

    if (grid_.getButtonEvent( buttonX, buttonY, event ))
    {
        Color color = { 0, 0, 0 };
        if (ButtonEvent_PRESSED == event)
        {
            color = grid_.getRandomColor();
        }
        grid_.setLed( buttonX, buttonY, color );
    }
}

void ApplicationMain::runInternalMenu()
{
    uint8_t buttonX, buttonY;
    ButtonEvent event;
    midi::MidiPacket unusedInputPacket;

    grid_.discardAllPendingButtonEvents();
    switches_.discardAllPendingEvents();
    grid_.turnAllLedsOff();
    gui_.enterInternalMenu();

    const Color red = {64U, 0U, 0U};
    const uint8_t bootloaderButtonX = 7;
    const uint8_t bootloaderButtonY = 0;
    grid_.setLed( bootloaderButtonX, bootloaderButtonY, red );

    while (1)
    {
        usbMidi_.getPacket( unusedInputPacket ); // check for incoming packets and discard them

        if (grid_.getButtonEvent( buttonX, buttonY, event ))
        {
            if ((bootloaderButtonX == buttonX) && (bootloaderButtonY == buttonY))
            {
                // reset into DFU bootloader
                system_.resetIntoBootloader();
            }
        }

        if (switches_.getButtonEvent( buttonX,  event ))
        {
            if ((switches_.internalMenuButton == buttonX) && (ButtonEvent_RELEASED == event))
            {
                break; // break internal menu loop, get back to launchpad mode
            }
        }

        gui_.refresh();
    }
}

extern "C" void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
    volatile uint8_t i;
    while(1)
    {
        i++;
    }
}
