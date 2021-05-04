//
// Created by grzegorz on 4/6/21.
//

#ifndef VPET_STM32TEXTURELOADER_H
#define VPET_STM32TEXTURELOADER_H

#include "../../Core/ui/display/drawable/texture-loader/TextureLoader.h"
#include "../nokia5110-display-data-manager/Nokia5110DisplayDataManager.h"

namespace tama
{
    class Stm32TextureLoader : public TextureLoader
    {
    public:
        std::shared_ptr<Texture> load(const TextureAsset &) override;

    private:
        PixelColor colorFromData(short data);
        PixelColor ** createEmptyTextureData(unsigned width, unsigned height);
    };
}



#endif //VPET_STM32TEXTURELOADER_H
