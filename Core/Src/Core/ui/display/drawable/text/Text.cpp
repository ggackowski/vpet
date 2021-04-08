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
    this->position = position;
    notifyObserver();
}

std::shared_ptr<tama::Texture> tama::Text::getTexture()
{
    unsigned width = (size + 1) * text.size();
    unsigned height = (size + 1) * (std::count(text.begin(), text.end(), '\n') + 1) ;
    auto texture = std::make_shared<Texture>(width, height);

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
    }

    return texture;
}

tama::Vec2d tama::Text::getPosition()
{
    return position;
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

void tama::Text::setText(std::string text)
{
    this->text = text;
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
    }
    return std::make_shared<tama::Texture>(0, 0);
}
