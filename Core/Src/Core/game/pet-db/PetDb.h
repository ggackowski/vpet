//
// Created by grzegorz on 5/30/21.
//

#ifndef VPET_PETDB_H
#define VPET_PETDB_H

#include <unordered_map>
#include "pet-textures.h"
#include "pet-identifier.h"

#include "../../assets/pet/first-male/baby/fir.st-male-baby.texture.h"


namespace tama
{
    using namespace tama::asset;

    class PetDb
    {
    public:
        PetDb();

        PetTextures getPetTextures(PetIdentifier petIdentifier);

    private:
        void initDb();

        struct hash_fn
        {
            std::size_t operator() (const PetIdentifier &node) const
            {
                std::size_t h1 = std::hash<int>()(node.breed);
                std::size_t h2 = std::hash<int>()(node.gender);
                std::size_t h3 = std::hash<int>()(node.breed);

                return h1 ^ h2 ^ h3;
            }
        };

        std::unordered_map<PetIdentifier, PetTextures, hash_fn> db;
    };

}


#endif //VPET_PETDB_H
