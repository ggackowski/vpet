//
// Created by grzegorz on 6/2/21.
//

#include "PetTexture.h"

tama::PetTexture::PetTexture(tama::PetIdentifier &petIdentifier, tama::PetDb &petDb) : petIdentifier(petIdentifier),
                                                                                       petDb(petDb)
{}

tama::TextureAsset * tama::PetTexture::getTextureAsset(tama::PetTextureVariant petTextureVariant)
{
    PetTextures textures = petDb.getPetTextures(petIdentifier);
    return variantToTexture(textures, petTextureVariant);
}

tama::TextureAsset * tama::PetTexture::variantToTexture(tama::PetTextures &petTextures, tama::PetTextureVariant & petTextureVariant)
{
    switch (petTextureVariant)
    {
        case frontStandard:
            return petTextures.frontStandard;
        case frontHappy:
            return petTextures.frontHappy;
        case sideEat:
            return petTextures.sideEat;
        case sideStandard:
            return petTextures.sideStandard;
        default:
            return petTextures.frontStandard;
    }
}


