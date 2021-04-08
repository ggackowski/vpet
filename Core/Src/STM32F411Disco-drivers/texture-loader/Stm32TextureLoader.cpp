//
// Created by grzegorz on 4/6/21.
//

#include "Stm32TextureLoader.h"

std::shared_ptr<tama::Texture> tama::Stm32TextureLoader::load(TextureAsset & textureAsset)
{
    std::shared_ptr<Texture> texture = std::make_shared<Texture>(textureAsset.width, textureAsset.height);
    PixelColor ** textureData = createEmptyTextureData(textureAsset.width, textureAsset.height);

    for (unsigned i = 0; i < textureAsset.height; ++i)
    {
        for (unsigned j = 0; j < textureAsset.width; ++j)
        {
            textureData[i][j] = colorFromData(textureAsset.data[i * textureAsset.width + j]);
        }
    }

    texture->data = textureData;

    return texture;
}

tama::PixelColor tama::Stm32TextureLoader::colorFromData(short data)
{
    if (data == 15)
    {
        return PixelColor::WHITE;
    } else if (data == 0)
    {
        return PixelColor::BLACK;
    }
    return PixelColor::TRANSPARENT;
}

tama::PixelColor **tama::Stm32TextureLoader::createEmptyTextureData(unsigned int width, unsigned int height)
{
    PixelColor ** textureData = new PixelColor*[height];
    for (unsigned i = 0; i < height; ++i)
    {
        textureData[i] = new PixelColor[width];
    }
    return textureData;
}
