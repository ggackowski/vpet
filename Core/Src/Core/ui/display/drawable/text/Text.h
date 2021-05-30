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

        Text();

        Text(const Vec2d &position);

        Text(std::string text, Vec2d position);

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

        void updateChar(char c, int pos);

        std::string &getText();

    private:

        void notifyObserver();

        std::shared_ptr<Texture> getTextureForLetter(char);

        void recalculateDimensions();

        void updateTexture();

        void afterUpdate();

        std::unique_ptr<tama::TextureLoader> textureLoader;
        std::shared_ptr<ChangeObserver> observer;
        std::string text;
        std::shared_ptr<Texture> texture;
        unsigned size = 7;
        bool visible{};
        Vec2d position;
        Vec2d dimensions;


    };
}



#endif //VPET_TEXT_H
