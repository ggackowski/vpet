//
// Created by grzegorz on 5/30/21.
//

#ifndef VPET_PET_IDENTIFIER_H
#define VPET_PET_IDENTIFIER_H

#include "../model/pet-data/breed/breed.enum.h"
#include "../model/pet-data/pet-phase/pet-phase.enum.h"
#include "../model/pet-data/gender//gender.enum.h"

namespace tama
{
    struct PetIdentifier
    {
        Breed breed;
        PetPhase phase;
        Gender gender;

        bool operator==(const PetIdentifier & Right) const
        {
            bool x = (breed == Right.breed && phase == Right.phase && gender == Right.gender);
            return x;
        }
    };

    struct PetIdentifierComparer
    {

    };
}

#endif //VPET_PET_IDENTIFIER_H
