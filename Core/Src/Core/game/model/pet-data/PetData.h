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
        int happiness = 0;
        int health = 0;
        bool isSleepy = false;
        int food = 0;
        PetIdentifier petIdentifier;
        int age = 0;

    public:
        PetIdentifier &getPetIdentifier();
        int getAge() const;
        int getHealth() const;
        void setPetIdentifier(const PetIdentifier &petIdentifier);
        void increaseAge();
        void updateHappiness(int h);
        void updateHealth(int h);
        void makeSleepy();
        void makeAwake();
        int getFood() const;
        const std::string &getName() const;
        void setName(const std::string &name);
        int getHappiness() const;

        void increaseFood(int f);
    };
}


#endif //VPET_PETDATA_H
