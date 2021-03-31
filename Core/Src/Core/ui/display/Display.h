//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_DISPLAY_H
#define VPET_DISPLAY_H

#include "PixelColor.h"
#include "display-data/DisplayData.h"

namespace tama
{
    class Display
    {

    public:
        virtual void displayData() = 0;

        virtual void setData(DisplayData &) = 0;

    };
}



#endif //VPET_DISPLAY_H
