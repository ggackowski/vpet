//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_DISPLAYDATA_H
#define VPET_DISPLAYDATA_H

#include <vector>
#include <memory>
#include "../PixelColor.h"
#include "../drawable/Drawable.h"

namespace tama
{
    class DisplayData
    {

    public:
        DisplayData();

        PixelColor * getDrawingData();

        void addDrawable(std::shared_ptr<Drawable>);

    private:

        std::vector<std::shared_ptr<Drawable>> elements;

        PixelColor * data;
    };
}




#endif //VPET_DISPLAYDATA_H
