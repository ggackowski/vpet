//
// Created by grzegorz on 4/6/21.
//

#ifndef VPET_TEXTURELOADER_H
#define VPET_TEXTURELOADER_H

#include "../texture.h"
#include "../../../../assets/texture-asset.h"
#include <memory>

namespace tama
{
    class TextureLoader
    {
    public:
        virtual std::shared_ptr<Texture> load(const TextureAsset &) = 0;
    };
}

#endif //VPET_TEXTURELOADER_H
