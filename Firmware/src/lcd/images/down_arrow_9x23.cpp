// This file is generated using convert.py script
// Editing it by hand would not be the best idea if you value your time

#include "lcd/ImageMono.h"

namespace lcd
{
namespace image
{

static const etl::array<uint8_t, 27> data = {
    0x00, 0x80, 0x00, 0x00, 0x80, 0x03, 0x00, 0x80, 0x0F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x3F, 0x00,
    0x80, 0x0F, 0x00, 0x80, 0x03, 0x00, 0x80, 0x00
};

static const ImageMono img( ImageMono::DataView( data ), 9, 23 );

const ImageMono& down_arrow_9x23 = img;

}  // namespace image
}  // namespace lcd