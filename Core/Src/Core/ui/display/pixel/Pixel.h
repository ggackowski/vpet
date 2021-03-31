//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_PIXEL_H
#define VPET_PIXEL_H

#include "../drawable/Drawable.h"
#include "../../../common/Vec2d/Vec2d.h"

namespace tama
{
    class Pixel : public Drawable
    {
    public:
        Pixel(const Vec2d &position, PixelColor & color);

    public:
        std::shared_ptr<Texture> getTexture() override;

        Vec2d getPosition() override;

        virtual ~Pixel();

    private:
        Vec2d position;
        PixelColor * color;
    };
}




#endif //VPET_PIXEL_H
