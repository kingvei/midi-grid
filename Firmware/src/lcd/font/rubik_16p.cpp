// This file is generated using convert.py script
// Editing it by hand would not be the best idea if you value your time

#include "lcd/Font.h"

namespace lcd
{
namespace font
{

static const etl::array<uint8_t, 1190> data = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1B, 0xF0, 0x1B, 0x10, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00, 0xF0,
    0x00, 0xC0, 0x06, 0xE0, 0x1F, 0xF0, 0x07, 0xC0, 0x1E, 0xF0, 0x1F, 0xF0, 0x07, 0xC0, 0x06, 0x00, 0x04, 0xF0, 0x0C,
    0xF8, 0x1D, 0xDC, 0x39, 0x9C, 0x39, 0xB8, 0x1B, 0xB0, 0x0F, 0x20, 0x0F, 0x60, 0x00, 0xF0, 0x10, 0x90, 0x18, 0xF0,
    0x0E, 0x00, 0x03, 0x80, 0x01, 0xE0, 0x1F, 0x30, 0x11, 0x10, 0x1F, 0x00, 0x0E, 0x60, 0x0F, 0xF0, 0x1F, 0xB0, 0x19,
    0xB0, 0x1B, 0xF0, 0x1E, 0x60, 0x1C, 0x00, 0x1F, 0x00, 0x13, 0x10, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x3F, 0xF8,
    0x7F, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0xF0, 0x3F, 0xE0, 0x1F, 0x40, 0x00, 0xE0, 0x01, 0xF0, 0x00,
    0xD0, 0x01, 0xE0, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0xC0, 0x1F, 0xC0, 0x1F, 0x00, 0x03, 0x00, 0x03, 0x00,
    0x20, 0x00, 0x38, 0x00, 0x18, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x18, 0x00, 0x18, 0x00, 0x20,
    0x00, 0x38, 0x00, 0x1F, 0xE0, 0x03, 0xF8, 0x00, 0x1C, 0x00, 0xE0, 0x0F, 0xF0, 0x1F, 0x30, 0x18, 0x30, 0x18, 0xF0,
    0x1F, 0xE0, 0x0F, 0xC0, 0x07, 0x40, 0x00, 0xE0, 0x00, 0x60, 0x00, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0x60, 0x1C,
    0x70, 0x1E, 0x30, 0x1E, 0x30, 0x1F, 0xF0, 0x1B, 0xE0, 0x19, 0x00, 0x18, 0x00, 0x04, 0x30, 0x0C, 0x30, 0x1D, 0xB0,
    0x19, 0xF0, 0x19, 0x70, 0x1F, 0x30, 0x0F, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0xC0, 0x07, 0xE0, 0x06, 0x30, 0x06,
    0xF0, 0x1F, 0xF0, 0x1F, 0x00, 0x06, 0x00, 0x04, 0xF0, 0x0D, 0xF0, 0x1D, 0xB0, 0x19, 0xB0, 0x19, 0xB0, 0x1F, 0x30,
    0x0F, 0x00, 0x06, 0x00, 0x06, 0x80, 0x0F, 0xC0, 0x1F, 0xF0, 0x18, 0xF0, 0x18, 0xD0, 0x1F, 0x80, 0x0F, 0x00, 0x07,
    0x30, 0x00, 0x30, 0x10, 0x30, 0x1C, 0x30, 0x1F, 0xF0, 0x07, 0xF0, 0x01, 0x70, 0x00, 0xE0, 0x0F, 0xF0, 0x1F, 0xB0,
    0x19, 0xB0, 0x19, 0xF0, 0x1B, 0xF0, 0x1F, 0x40, 0x0E, 0xC0, 0x00, 0xE0, 0x01, 0xF0, 0x13, 0x30, 0x1F, 0x30, 0x1F,
    0xF0, 0x07, 0xE0, 0x03, 0xC0, 0x00, 0xC0, 0x18, 0xC0, 0x18, 0x00, 0x20, 0xC0, 0x38, 0xC0, 0x18, 0x00, 0x03, 0x00,
    0x03, 0x80, 0x07, 0xC0, 0x0D, 0xC0, 0x0C, 0x60, 0x18, 0x80, 0x0D, 0x80, 0x0D, 0x80, 0x0D, 0x80, 0x0D, 0x80, 0x0D,
    0xE0, 0x18, 0xC0, 0x0C, 0x80, 0x07, 0x80, 0x07, 0x00, 0x03, 0x40, 0x00, 0x60, 0x00, 0x70, 0x00, 0x30, 0x1F, 0xB0,
    0x1F, 0xF0, 0x03, 0xE0, 0x00, 0xC0, 0x1F, 0x60, 0x20, 0x30, 0x4F, 0xB0, 0x59, 0xB0, 0x59, 0xB0, 0x4F, 0x30, 0x48,
    0x60, 0x38, 0xC0, 0x0F, 0x00, 0x10, 0x00, 0x1E, 0xC0, 0x0F, 0xF0, 0x07, 0x30, 0x06, 0xF0, 0x07, 0xC0, 0x0F, 0x00,
    0x1E, 0x00, 0x10, 0xF0, 0x1F, 0xF0, 0x1F, 0xB0, 0x19, 0xB0, 0x19, 0xB0, 0x19, 0xF0, 0x1F, 0xE0, 0x0F, 0xE0, 0x0F,
    0xF0, 0x1F, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x70, 0x1C, 0x60, 0x0C, 0xF0, 0x1F, 0xF0, 0x1F, 0x30, 0x18, 0x30,
    0x18, 0x30, 0x18, 0xF0, 0x1F, 0xE0, 0x0F, 0xF0, 0x1F, 0xF0, 0x1F, 0xB0, 0x19, 0xB0, 0x19, 0xB0, 0x19, 0xB0, 0x19,
    0xF0, 0x1F, 0xF0, 0x1F, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0xE0, 0x0F, 0xF0, 0x1F, 0x30, 0x18, 0x30,
    0x18, 0xB0, 0x19, 0xF0, 0x1F, 0xE0, 0x0F, 0x00, 0x01, 0xF0, 0x1F, 0xF0, 0x1F, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
    0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0x00, 0x04, 0x30, 0x0C, 0x30, 0x1C, 0x30, 0x18, 0x30,
    0x18, 0xF0, 0x1F, 0xF0, 0x0F, 0xF0, 0x07, 0xF0, 0x1F, 0xF0, 0x1F, 0x80, 0x03, 0xE0, 0x07, 0xF0, 0x1E, 0x30, 0x1C,
    0x10, 0x10, 0xF0, 0x1F, 0xF0, 0x1F, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0xF0, 0x1F, 0xF0, 0x1F, 0xE0,
    0x01, 0x80, 0x07, 0x00, 0x07, 0xC0, 0x03, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xE0, 0x01,
    0x80, 0x03, 0x00, 0x0F, 0xF0, 0x1F, 0xF0, 0x1F, 0xE0, 0x0F, 0xF0, 0x1F, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0xF0,
    0x1F, 0xE0, 0x0F, 0xF0, 0x1F, 0xF0, 0x1F, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0xF0, 0x01, 0xE0, 0x01, 0xE0, 0x0F,
    0xF0, 0x1F, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0xF0, 0x1F, 0xE0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0x30, 0x03, 0x30,
    0x03, 0x30, 0x0F, 0xF0, 0x1F, 0xE0, 0x19, 0x00, 0x04, 0xE0, 0x0D, 0xF0, 0x1D, 0xB0, 0x19, 0xB0, 0x1B, 0x70, 0x1B,
    0x60, 0x0F, 0x40, 0x0E, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0xF0, 0x1F, 0xF0, 0x1F, 0x30, 0x00, 0x30, 0x00, 0x30,
    0x00, 0xF0, 0x0F, 0xF0, 0x1F, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0xF0, 0x1F, 0xF0, 0x0F, 0x10, 0x00, 0xF0, 0x00,
    0xF0, 0x0F, 0x80, 0x1F, 0x00, 0x1C, 0xC0, 0x1F, 0xF0, 0x07, 0x70, 0x00, 0x10, 0x00, 0xF0, 0x07, 0xF0, 0x1F, 0x00,
    0x1E, 0xC0, 0x07, 0xC0, 0x03, 0x00, 0x1F, 0xC0, 0x1F, 0xF0, 0x1F, 0xF0, 0x00, 0x10, 0x10, 0x30, 0x18, 0xF0, 0x1E,
    0xE0, 0x0F, 0xC0, 0x07, 0xE0, 0x0F, 0x70, 0x1E, 0x30, 0x18, 0x00, 0x10, 0x10, 0x00, 0x70, 0x00, 0xF0, 0x01, 0xC0,
    0x1F, 0x80, 0x1F, 0xE0, 0x03, 0xF0, 0x00, 0x30, 0x00, 0x00, 0x18, 0x30, 0x1C, 0x30, 0x1F, 0xB0, 0x1F, 0xF0, 0x1B,
    0xF0, 0x19, 0x70, 0x18, 0x30, 0x18, 0xF8, 0x7F, 0xF8, 0x7F, 0x18, 0x60, 0x08, 0x60, 0x04, 0x00, 0x3C, 0x00, 0xF0,
    0x00, 0xC0, 0x07, 0x00, 0x3E, 0x00, 0x38, 0x18, 0x60, 0x18, 0x60, 0xF8, 0x7F, 0xF8, 0x7F, 0x10, 0x00, 0x18, 0x00,
    0x18, 0x00, 0x10, 0x00, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00,
    0x30, 0x08, 0x00, 0x18, 0x00, 0x10, 0x00, 0x00, 0x0C, 0x80, 0x1E, 0xC0, 0x1E, 0xC0, 0x1A, 0xC0, 0x0E, 0xC0, 0x1F,
    0x80, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xC0, 0x18, 0xC0, 0x18, 0xC0, 0x1F, 0x80, 0x0F, 0x00, 0x02, 0x80, 0x0F, 0xC0,
    0x1F, 0xC0, 0x18, 0xC0, 0x18, 0xC0, 0x1D, 0x80, 0x0D, 0x00, 0x02, 0x80, 0x0F, 0xC0, 0x1F, 0xC0, 0x18, 0xC0, 0x18,
    0xF0, 0x1F, 0xF0, 0x1F, 0x00, 0x02, 0x80, 0x0F, 0xC0, 0x1F, 0xC0, 0x1B, 0xC0, 0x1B, 0xC0, 0x1B, 0x80, 0x0B, 0xC0,
    0x00, 0xE0, 0x1F, 0xF0, 0x1F, 0xF8, 0x1F, 0xD8, 0x00, 0x18, 0x00, 0x00, 0x02, 0x80, 0x6F, 0xC0, 0xFF, 0xC0, 0xD8,
    0xC0, 0xD8, 0xC0, 0xFF, 0xC0, 0x7F, 0xF0, 0x1F, 0xF0, 0x1F, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x1F, 0xC0, 0x1F, 0x00,
    0x1F, 0xD8, 0x1F, 0xD8, 0x1F, 0x00, 0x60, 0x00, 0x60, 0xD8, 0x7F, 0xD8, 0x3F, 0xF0, 0x1F, 0xF0, 0x1F, 0x00, 0x07,
    0xC0, 0x0F, 0xC0, 0x1C, 0x40, 0x10, 0xF0, 0x1F, 0xF0, 0x1F, 0xC0, 0x1F, 0xC0, 0x1F, 0xC0, 0x00, 0xC0, 0x00, 0xC0,
    0x1F, 0x80, 0x1F, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x1F, 0x80, 0x1F, 0xC0, 0x1F, 0xC0, 0x1F, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x1F, 0x80, 0x1F, 0x00, 0x02, 0x80, 0x0F, 0xC0, 0x1F, 0xC0, 0x18, 0xC0, 0x18, 0xC0, 0x1F, 0x80, 0x0F, 0xC0,
    0x7F, 0xC0, 0x7F, 0xC0, 0x18, 0xC0, 0x18, 0xC0, 0x1F, 0x80, 0x0F, 0x00, 0x02, 0x80, 0x0F, 0xC0, 0x1F, 0xC0, 0x18,
    0xC0, 0x18, 0xC0, 0x7F, 0xC0, 0x7F, 0xC0, 0x1F, 0xC0, 0x1F, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0x00, 0x08, 0xC0,
    0x1B, 0xC0, 0x1B, 0xC0, 0x1A, 0xC0, 0x1E, 0x80, 0x1E, 0x00, 0x0C, 0xC0, 0x00, 0xF0, 0x07, 0xF0, 0x1F, 0xF0, 0x1F,
    0xC0, 0x18, 0x40, 0x18, 0xC0, 0x0F, 0xC0, 0x1F, 0x00, 0x18, 0x00, 0x18, 0xC0, 0x1F, 0xC0, 0x1F, 0x40, 0x00, 0xC0,
    0x03, 0x80, 0x0F, 0x00, 0x1C, 0x00, 0x1F, 0xC0, 0x07, 0xC0, 0x00, 0x40, 0x00, 0xC0, 0x07, 0x80, 0x1F, 0x00, 0x1E,
    0xC0, 0x0F, 0xC0, 0x03, 0x00, 0x1F, 0x00, 0x1E, 0xC0, 0x0F, 0xC0, 0x01, 0x40, 0x10, 0xC0, 0x18, 0xC0, 0x1F, 0x00,
    0x07, 0x80, 0x0F, 0xC0, 0x1D, 0x40, 0x10, 0x40, 0x00, 0xC0, 0x01, 0x80, 0x6F, 0x00, 0x7E, 0x00, 0x1F, 0xC0, 0x07,
    0xC0, 0x00, 0x00, 0x18, 0xC0, 0x1C, 0xC0, 0x1E, 0xC0, 0x1F, 0xC0, 0x1B, 0xC0, 0x19, 0x00, 0x18, 0x00, 0x03, 0xE0,
    0x1F, 0xF0, 0x3F, 0x38, 0x70, 0x18, 0x60, 0xFF, 0x7F, 0xFF, 0x7F, 0x18, 0x60, 0x18, 0x60, 0xF8, 0x7D, 0xF0, 0x3F,
    0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03
};

static const etl::array<uint16_t, 96> map = {
    0, 6, 10, 20, 34, 50, 70, 86, 92, 100, 108, 118, 132, 138, 146, 150, 162, 176, 188, 202, 218, 234, 250, 266, 280,
    294, 310, 314, 320, 332, 342, 352, 366, 384, 402, 416, 430, 444, 456, 468, 484, 500, 504, 520, 534, 546, 564, 578,
    592, 606, 620, 634, 650, 666, 680, 696, 716, 734, 750, 766, 774, 786, 794, 802, 818, 824, 838, 850, 864, 878, 892,
    904, 918, 932, 936, 944, 956, 960, 980, 992, 1006, 1018, 1032, 1042, 1056, 1068, 1080, 1094, 1114, 1128, 1142, 1156,
    1166, 1170, 1180, 1190
};

static const Font fnt( 95, 32, Font::GlyphView( data ), Font::MapView( map ), 16, 12, 2 );

const Font& rubik_16p = fnt;

}  // namespace font
}  // namespace lcd
