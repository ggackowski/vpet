//
// Created by grzegorz on 4/7/21.
//

#ifndef VPET_TEXT_H
#define VPET_TEXT_H

#include "../Drawable.h"
#include "../texture-loader/TextureLoader.h"

namespace tama
{
    class Text : public Drawable
    {
    public:
        Text(const Vec2d &position);

        void setTexture(std::shared_ptr<Texture> ptr) override;

        void setPosition(Vec2d d) override;

        std::shared_ptr<Texture> getTexture() override;

        Vec2d getPosition() override;

        void move(Vec2d d) override;

        void hide() override;

        void show() override;

        void setChangeObserver(std::shared_ptr<ChangeObserver> ptr) override;

        bool isVisible() override;

        void setText(std::string);

    private:
        void notifyObserver();
        std::shared_ptr<Texture> getTextureForLetter(char);
        std::unique_ptr<tama::TextureLoader> textureLoader;
        std::shared_ptr<ChangeObserver> observer;
        std::string text;
        std::shared_ptr<Texture> texture;
        unsigned size = 7;
        bool visible;
        Vec2d position;

    };
}



#endif //VPET_TEXT_H
