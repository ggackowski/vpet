//
// Created by grzegorz on 3/25/21.
//

#include <memory>
#include "Pixel.h"

std::shared_ptr<tama::Texture> tama::Pixel::getTexture()
{
    return nullptr;
}

tama::Pixel::Pixel(const tama::Vec2d &position, tama::PixelColor & color) : position(position)
{
    this->color = new PixelColor(color);
}

tama::Vec2d tama::Pixel::getPosition()
{
    return position;
}

tama::Pixel::~Pixel()
{
    delete color;
}
