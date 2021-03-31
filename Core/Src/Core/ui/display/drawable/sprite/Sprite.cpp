//
// Created by grzegorz on 3/28/21.
//

#include "Sprite.h"

void tama::Sprite::setTexture(std::shared_ptr<tama::Texture> texture)
{
    this->texture = texture;
}

void tama::Sprite::setPosition(tama::Vec2d position)
{
    this->position = position;
    notifyObserver();
}

std::shared_ptr<tama::Texture> tama::Sprite::getTexture()
{
    return texture;
}

tama::Vec2d tama::Sprite::getPosition()
{
    return position;
}

void tama::Sprite::move(tama::Vec2d delta)
{
    position = position + delta;
    notifyObserver();
}

void tama::Sprite::hide()
{
    visible = false;
    notifyObserver();
}

void tama::Sprite::show()
{
    visible = true;
    notifyObserver();
}

void tama::Sprite::setChangeObserver(std::shared_ptr<tama::ChangeObserver> observer)
{
    this->observer = observer;
}

bool tama::Sprite::isVisible()
{
    return visible;
}

void tama::Sprite::notifyObserver()
{
    if (observer != nullptr)
    {
        observer->onChange();
    }
}

tama::Sprite::Sprite(const std::shared_ptr<Texture> &texture, const tama::Vec2d &position) : texture(texture),
                                                                                             position(position)
{
    observer = nullptr;
    visible = true;
}
