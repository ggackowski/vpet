//
// Created by grzegorz on 4/7/21.
//

#include <algorithm>
#include "Text.h"
#include "../../../../../STM32F411Disco-drivers/texture-loader/Stm32TextureLoader.h"
#include "../../../../assets/text/standard-font.texture.h"

void tama::Text::setTexture(std::shared_ptr<Texture> ptr)
{

}

void tama::Text::setPosition(tama::Vec2d d)
{
    this->position = d;
    notifyObserver();
}

std::shared_ptr<tama::Texture> tama::Text::getTexture()
{
    return texture;
}

tama::Vec2d tama::Text::getPosition()
{
    return position;
}

std::string & tama::Text::getText()
{
    return text;
}

void tama::Text::move(tama::Vec2d delta)
{
    position = position + delta;
    notifyObserver();
}

void tama::Text::hide()
{
    visible = false;
    notifyObserver();
}

void tama::Text::show()
{
    visible = true;
    notifyObserver();
}

void tama::Text::setChangeObserver(std::shared_ptr<ChangeObserver> ptr)
{
    this->observer = observer;
}

bool tama::Text::isVisible()
{
    return visible;
}

void tama::Text::afterUpdate()
{
    recalculateDimensions();
    updateTexture();
    notifyObserver();
}

void tama::Text::updateChar(char c, int pos)
{
    this->text[pos] = c;
    afterUpdate();

}

void tama::Text::setText(std::string text)
{
    this->text = text;
    afterUpdate();

}

void tama::Text::notifyObserver()
{
    if (observer != nullptr)
    {
        observer->onChange();
    }
}

tama::Text::Text(const tama::Vec2d &position) :
                                                position(position)
{
    textureLoader = std::make_unique<tama::Stm32TextureLoader>();
    observer = nullptr;
    visible = true;
    text = "";
    recalculateDimensions();
    updateTexture();
}

void tama::Text::updateTexture()
{
    texture = std::make_shared<Texture>(dimensions.x, dimensions.y);
    unsigned line = 0;
    unsigned letterInLine = 0;

    for (unsigned i = 0; i < text.size(); ++i)
    {
        if (text[i] == '\n')
        {
            line++;
            letterInLine = 0;
            continue;
        }

        auto letter = getTextureForLetter(text[i]);
        texture->insertAt(Vec2d(letterInLine++ * (size + 1), line * (size + 1)), letter);
        //texture->insertAt(Vec2d(0, 0), letter);
    }
}

std::shared_ptr<tama::Texture> tama::Text::getTextureForLetter(char letter)
{
    switch (letter)
    {
        case 'J': return textureLoader->load(tama::asset::font::standard::J);
        case 'U': return textureLoader->load(tama::asset::font::standard::U);
        case 'D': return textureLoader->load(tama::asset::font::standard::D);
        case 'S': return textureLoader->load(tama::asset::font::standard::S);
        case 'T': return textureLoader->load(tama::asset::font::standard::T);
        case 'I': return textureLoader->load(tama::asset::font::standard::I);
        case 'A': return textureLoader->load(tama::asset::font::standard::A);
        case 'B': return textureLoader->load(tama::asset::font::standard::B);
        case 'C': return textureLoader->load(tama::asset::font::standard::C);
        case 'E': return textureLoader->load(tama::asset::font::standard::E);
        case 'F': return textureLoader->load(tama::asset::font::standard::F);
        case 'G': return textureLoader->load(tama::asset::font::standard::G);
        case 'H': return textureLoader->load(tama::asset::font::standard::H);
        case 'K': return textureLoader->load(tama::asset::font::standard::K);
        case 'L': return textureLoader->load(tama::asset::font::standard::L);
        case 'M': return textureLoader->load(tama::asset::font::standard::M);
        case 'N': return textureLoader->load(tama::asset::font::standard::N);
        case 'O': return textureLoader->load(tama::asset::font::standard::O);
        case 'P': return textureLoader->load(tama::asset::font::standard::P);
        case 'Q': return textureLoader->load(tama::asset::font::standard::Q);
        case 'R': return textureLoader->load(tama::asset::font::standard::R);
        case 'W': return textureLoader->load(tama::asset::font::standard::W);
        case 'X': return textureLoader->load(tama::asset::font::standard::X);
        case 'V': return textureLoader->load(tama::asset::font::standard::V);
        case 'Y': return textureLoader->load(tama::asset::font::standard::Y);
        case 'Z': return textureLoader->load(tama::asset::font::standard::Z);
        case ' ': return textureLoader->load(tama::asset::font::standard::SPC);
        case '0': return textureLoader->load(tama::asset::font::standard::Zero);
        case '1': return textureLoader->load(tama::asset::font::standard::One);
        case '2': return textureLoader->load(tama::asset::font::standard::Two);
        case '3': return textureLoader->load(tama::asset::font::standard::Three);
        case '4': return textureLoader->load(tama::asset::font::standard::Four);
        case '5': return textureLoader->load(tama::asset::font::standard::Five);
        case '6': return textureLoader->load(tama::asset::font::standard::Six);
        case '7': return textureLoader->load(tama::asset::font::standard::Seven);
        case '8': return textureLoader->load(tama::asset::font::standard::Eight);
        case '9': return textureLoader->load(tama::asset::font::standard::Nine);
        case ':': return textureLoader->load(tama::asset::font::standard::Colon);
        case '-': return textureLoader->load(tama::asset::font::standard::Dash);
        case '_': return textureLoader->load(tama::asset::font::standard::Underscore);
    }
    return std::make_shared<tama::Texture>(0, 0);
}

void tama::Text::recalculateDimensions()
{
    dimensions.x = (size + 1) * text.size();
    dimensions.y = (size + 1) * (std::count(text.begin(), text.end(), '\n') + 1) ;

}

tama::Text::Text(std::string text, Vec2d position):
        position(position), text(text)
{
    textureLoader = std::make_unique<tama::Stm32TextureLoader>();
    observer = nullptr;
    visible = true;
    recalculateDimensions();
    updateTexture();
}

tama::Text::Text()
{
    tama::Text(Vec2d(0,0));
}
