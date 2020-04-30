
#include "application/launchpad/LcdGui.hpp"
#include "application/launchpad/Launchpad.hpp"
#include "application/launchpad/Images.hpp"

#include "lcd/LcdInterface.h"
#include "lcd/Font.h"
#include <freertos/ticks.hpp>

#include <etl/cstring.h>
#include <etl/to_string.h>

namespace application
{
namespace launchpad
{

static const lcd::ImageLegacy usbSymbolSmall = { &usbSymbolSmallArray[0], 9, 8 };
static const lcd::ImageLegacy midiSymbolSmall = { &midiSymbolSmallArray[0], 8, 8 };
static const lcd::ImageLegacy arrowSmallUp = { &arrowSmallUpArray[0], 5, 8 };
static const lcd::ImageLegacy arrowSmallDown = { &arrowSmallDownArray[0], 5, 8 };
static const lcd::ImageLegacy play = { &playArray[0], 16, 16 };
static const lcd::ImageLegacy recordingOn = { &recordingOnArray[0], 16, 16 };
static const lcd::ImageLegacy sessionRecordingOn = { &sessionRecordingOnArray[0], 16, 16 };
static const lcd::ImageLegacy nudgeDownInactive = { &nudgeDownInactiveArray[0], 10, 8};
static const lcd::ImageLegacy nudgeDownActive = { &nudgeDownActiveArray[0], 10, 8};
static const lcd::ImageLegacy nudgeUpInactive = { &nudgeUpInactiveArray[0], 10, 8};
static const lcd::ImageLegacy nudgeUpActive = { &nudgeUpActiveArray[0], 10, 8};

static const etl::array<etl::string<16>, 8> launchpad95ModeString = {
    "Session",
    "Instrument",
    "Device control",
    "User 1",
    "Drum step seq.",
    "Melodic seq.",
    "User 2",
    "Mixer"
};

static const etl::array<etl::string<16>, 9> launchpad95SubmodeString = {
    " ",
    "Scale",
    "Volume",
    "Pan",
    "Send A",
    "Send B",
    "MSS: Length",
    "MSS: Octave",
    "MSS: Velocity"
};

static const uint32_t kMidiActivityTimeoutMs = 1000;
static const uint32_t kRotaryControlTimeoutMs = 1000;

static const lcd::Pixel background = {110, 110, 110};
static const lcd::Pixel playActive = {10, 255, 128};
static const lcd::Pixel recordingActive = {255, 54, 64};
static const lcd::Pixel midiActive = {255, 181, 50};
static const lcd::Pixel inactive = lcd::color::BLACK;
static const lcd::Pixel tempo = lcd::color::YELLOW;

static const lcd::Font& smallFont = lcd::font::rubik_24p;
static const lcd::Font& bigFont = lcd::font::monoton_80p;

static const uint16_t leftX = 5;
static const uint16_t rightX = 234;
static const uint16_t topY = 5;
static const uint16_t bottomY = 314;

LcdGui::LcdGui( Launchpad* launchpad, lcd::LcdInterface* lcd ):
    launchpad_( *launchpad ),
    lcd_( *lcd )
{
}

void LcdGui::initialize()
{
    lcd_.setBackgroundColor( background );
    lcd_.clear();
    // displayLaunchpad95Info();
}

void LcdGui::refresh()
{
    refreshTimedItemsStatus();
    refreshStatusBar();
    // refreshTimingArea();
}

void LcdGui::refreshStatusBar()
{
    lcd_.displayImage( {leftX, topY}, lcd::image::triangle_21x23, (launchpad_.isPlaying_ ? playActive : inactive) );
    lcd_.displayImage( {42, topY}, lcd::image::circle_23x23, (launchpad_.isRecording_ ? recordingActive : inactive) );
    lcd_.displayImage( {81, topY}, lcd::image::circle_empty_23x23, (launchpad_.isSessionRecording_ ? recordingActive : inactive) );

    lcd_.displayImage( {174, topY}, lcd::image::usb_41x23,
        ((usbMidiInputActivityIcon_.enabled || usbMidiOutputActivityIcon_.enabled) ? midiActive : inactive) );
    lcd_.displayImage( {217, topY}, lcd::image::down_arrow_9x23, (usbMidiInputActivityIcon_.enabled ? midiActive : inactive) );
    lcd_.displayImage( {226, topY}, lcd::image::up_arrow_9x23, (usbMidiOutputActivityIcon_.enabled ? midiActive : inactive) );
}

void LcdGui::refreshTimingArea()
{
    if (0 != launchpad_.tempo_)
    {
        lcd_.print( "bpm", {rightX, 64}, lcd::Format().font( smallFont ).textColor( tempo ).justification( lcd::Justification::RIGHT ));

        etl::string<3> tempoString = {};
        etl::to_string( launchpad_.tempo_, tempoString );
        lcd_.print( tempoString, {200, 64}, lcd::Format().font( bigFont ).textColor( tempo ).justification( lcd::Justification::RIGHT ));
    }
    else
    {
        lcd_.clearArea( {leftX, 64}, {rightX, 144} );
    }
}

void LcdGui::refreshMainArea()
{

    displayLaunchpad95Info();
}

void LcdGui::refreshTimedItemsStatus()
{
    if (usbMidiInputActivityIcon_.enabled)
    {
        if (freertos::Ticks::GetTicks() >= usbMidiInputActivityIcon_.timeToDisable)
        {
            usbMidiInputActivityIcon_.enabled = false;
        }
    }

    if (usbMidiOutputActivityIcon_.enabled)
    {
        if (freertos::Ticks::GetTicks() >= usbMidiOutputActivityIcon_.timeToDisable)
        {
            usbMidiOutputActivityIcon_.enabled = false;
        }
    }
}

void LcdGui::registerMidiInputActivity()
{
    usbMidiInputActivityIcon_.enabled = true;
    usbMidiInputActivityIcon_.timeToDisable = freertos::Ticks::GetTicks() + kMidiActivityTimeoutMs;
}


void LcdGui::registerMidiOutputActivity()
{
    usbMidiOutputActivityIcon_.enabled = true;
    usbMidiOutputActivityIcon_.timeToDisable = freertos::Ticks::GetTicks() + kMidiActivityTimeoutMs;
}

void LcdGui::displayLaunchpad95Info()
{
    if (Launchpad95Submode_DEFAULT == launchpad_.submode_)
    {
        displayMode();
    }
    else
    {
        displaySubmode();
    }

    // only display other info when rotary control display timer runs out
        lcd_.clearArea( {0, 16}, {83, 31} );
        displayStatus();

        lcd_.clearArea( {0, 32}, {83, 47} );
        switch (launchpad_.mode_)
        {
            case Launchpad95Mode_INSTRUMENT:
            case Launchpad95Mode_DRUM_STEP_SEQUENCER:
            case Launchpad95Mode_MELODIC_SEQUENCER:
                displayTrackName();
                displayClipName();
                break;
            case Launchpad95Mode_DEVICE_CONTROLLER:
                displayTrackName();
                displayDeviceName();
                break;
            case Launchpad95Mode_SESSION:
            case Launchpad95Mode_MIXER:
            case Launchpad95Mode_USER1:
            case Launchpad95Mode_USER2:
            default:
                displayTimingStatus();
                break;
        }
}

void LcdGui::displayClipName()
{
    lcd_.print( &launchpad_.clipName_[0], lcd_.line( 5 ), lcd::Justification::CENTER );
}

void LcdGui::displayDeviceName()
{
    lcd_.print( &launchpad_.deviceName_[0], lcd_.line( 5 ), lcd::Justification::CENTER );
}

void LcdGui::displayTrackName()
{
    lcd_.print( &launchpad_.trackName_[0], lcd_.line( 4 ), lcd::Justification::CENTER );
}

void LcdGui::displayMode()
{
    lcd_.clearArea( {0, 8}, {83, 15} );
    if (Launchpad95Mode_UNKNOWN != launchpad_.mode_)
    {
        lcd_.print( &launchpad95ModeString.at(launchpad_.mode_)[0], lcd_.line( 1 ), lcd::Justification::CENTER );
    }
}

void LcdGui::displaySubmode()
{
    lcd_.clearArea( {0, 8}, {83, 15} );
    lcd_.print( &launchpad95SubmodeString.at(launchpad_.submode_)[0], lcd_.line( 1 ), lcd::Justification::CENTER );
}

void LcdGui::displayStatus()
{
    uint8_t numberOfDisplayedSymbols = (launchpad_.isPlaying_) ? 1 : 0;
    numberOfDisplayedSymbols += (launchpad_.isRecording_) ? 1 : 0;
    numberOfDisplayedSymbols += (launchpad_.isSessionRecording_) ? 1 : 0;

    switch (numberOfDisplayedSymbols)
    {
        case 1:
            lcd_.displayImage( 32, 16, play );
            break;
        case 2:
            lcd_.displayImage( 23, 16, play );
            lcd_.displayImage( 43, 16, (launchpad_.isRecording_ ? recordingOn : sessionRecordingOn) );
            break;
        case 3:
            lcd_.displayImage( 12, 16, play );
            lcd_.displayImage( 32, 16, recordingOn );
            lcd_.displayImage( 52, 16, sessionRecordingOn );
            break;
        default:
            break;
    }
}

void LcdGui::displayTimingStatus()
{
    if (0 != launchpad_.tempo_) // tempo of 0 means there's no info, so no need to display it
    {
        lcd_.displayImage( 0, 40, (launchpad_.nudgeDownActive_ ? nudgeDownActive : nudgeDownInactive) );
        lcd_.displayImage( 10, 40, (launchpad_.nudgeUpActive_ ? nudgeUpActive : nudgeUpInactive) );

        lcd_.printNumberInBigDigits( launchpad_.tempo_, 65, 32, lcd::Justification::RIGHT );
        lcd_.print( "bpm", 66, 32 );

        etl::string<6> signatureString;
        etl::to_string( launchpad_.signatureNumerator_, signatureString );
        signatureString += "/";
        etl::to_string( launchpad_.signatureDenominator_, signatureString, true );
        lcd_.print( &signatureString[0], 0, 32 );
    }
}

void LcdGui::displayRotaryControlValues()
{
    const uint8_t numberOfProgressArcPositions = 51;
    etl::string<4> str;
    lcd_.clearArea( {0, 16}, {83, 47} );

    lcd_.displayProgressArc( 0, 20, (launchpad_.rotaryControlValue_.at( 0 ) * (numberOfProgressArcPositions - 1)) / 127 );
    etl::to_string( launchpad_.rotaryControlValue_.at( 0 ), str );
    lcd_.print( &str[0], 18, 32, lcd::Justification::CENTER );

    lcd_.displayProgressArc( 45, 20, (launchpad_.rotaryControlValue_.at( 1 ) * (numberOfProgressArcPositions - 1)) / 127 );
    etl::to_string( launchpad_.rotaryControlValue_.at( 1 ), str );
    lcd_.print( &str[0], 63, 32, lcd::Justification::CENTER );
}

}  // namespace launchpad
}  // namespace application

