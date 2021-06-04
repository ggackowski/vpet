//
// Created by grzegorz on 6/2/21.
//

#ifndef VPET_PETTEXTURE_H
#define VPET_PETTEXTURE_H

#include <memory>
#include "../../pet-db/PetDb.h"
#include "../../pet-db/pet-texture-variant.h"
#include "../../../ui/display/drawable/texture.h"

namespace tama
{
    class PetTexture
    {
    public:
        PetTexture(PetIdentifier &petIdentifier, PetDb &petDb);

        TextureAsset * getTextureAsset(PetTextureVariant petTextureVariant);
    private:
        PetIdentifier & petIdentifier;
        PetDb & petDb;

        TextureAsset * variantToTexture(PetTextures & petTextures, tama::PetTextureVariant & petTextureVariant);
    };
}

#endif //VPET_PETTEXTURE_H
