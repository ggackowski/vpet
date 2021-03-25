//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_DRAWABLE_H
#define VPET_DRAWABLE_H

#include "../PixelColor.h"
#include "../../../common/Vec2d/Vec2d.h"

namespace tama
{
    class Drawable
    {

    public:
        virtual PixelColor * getTexture() = 0;
        virtual Vec2d getPosition() = 0;

    private:

    };
}




#endif //VPET_DRAWABLE_H
