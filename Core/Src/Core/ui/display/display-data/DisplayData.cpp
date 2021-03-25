//
// Created by grzegorz on 3/25/21.
//

#include "DisplayData.h"

tama::PixelColor *tama::DisplayData::getDrawingData()
{

}

void tama::DisplayData::addDrawable(std::shared_ptr<Drawable> drawable)
{
    elements.push_back(drawable);
}

tama::DisplayData::DisplayData()
{
    data = new PixelColor[84 * 48];
    for (int i = 0; i < 48 * 84; ++i) {
        data[i] = PixelColor::WHITE;
    }
}
