//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_DRAWABLE_H
#define VPET_DRAWABLE_H

#include "../PixelColor.h"
#include "../../../common/Vec2d/Vec2d.h"
#include "../../../common/observers/ChangeObserver.h"
#include "texture.h"

namespace tama
{
    class Drawable
    {

    public:
        virtual void setTexture(std::shared_ptr<Texture>) = 0;
        virtual void setPosition(Vec2d) = 0;
        virtual std::shared_ptr<Texture> getTexture() = 0;
        virtual Vec2d getPosition() = 0;
        virtual void move(Vec2d) = 0;
        virtual void hide() = 0;
        virtual void show() = 0;
        virtual void setChangeObserver(std::shared_ptr<ChangeObserver>) = 0;
        virtual bool isVisible() = 0;

    private:

    };
}




#endif //VPET_DRAWABLE_H
