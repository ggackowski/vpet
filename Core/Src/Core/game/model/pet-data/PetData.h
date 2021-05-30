//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_PETDATA_H
#define VPET_PETDATA_H

#include <string>
#include "gender/gender.enum.h"
#include "pet-phase/pet-phase.enum.h"
#include "breed/breed.enum.h"
#include "../../pet-db/pet-identifier.h"

namespace tama
{
    class PetData
    {
    private:
        std::string name;
//        Gender gender;
//        PetPhase phase;
//        Breed breed;
        PetIdentifier petIdentifier;
        int age;
        int food;
        int happiness;
        int health;
        bool isSleepy;
    };
}


#endif //VPET_PETDATA_H
