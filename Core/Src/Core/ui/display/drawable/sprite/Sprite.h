//
// Created by grzegorz on 3/28/21.
//

#ifndef VPET_SPRITE_H
#define VPET_SPRITE_H

#include <memory>
#include "../Drawable.h"

namespace tama
{
    class Sprite : public Drawable
    {
    public:

        Sprite();

        Sprite(const std::shared_ptr<Texture> &texture, const Vec2d &position);

        void setTexture(std::shared_ptr <Texture> ptr) override;

        void setPosition(Vec2d d) override;

        std::shared_ptr <Texture> getTexture() override;

        Vec2d getPosition() override;

        void move(Vec2d d) override;

        void hide() override;

        void show() override;

        void setChangeObserver(std::shared_ptr<ChangeObserver> ptr) override;

        bool isVisible() override;

    private:
        std::shared_ptr<Texture> texture;
        Vec2d position;
        bool visible;
        std::shared_ptr<ChangeObserver> observer;
        void notifyObserver();
    };

}


#endif //VPET_SPRITE_H
