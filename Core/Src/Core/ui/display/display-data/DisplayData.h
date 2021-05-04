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
        void * data;
        unsigned size;
        unsigned elementSize;

        ~DisplayData() {
            delete[] ((short *)data);
        }
    };
}




#endif //VPET_DISPLAYDATA_H
