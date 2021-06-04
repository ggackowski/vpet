//
// Created by grzegorz on 5/8/21.
//

#include "PetData.h"

tama::PetIdentifier &tama::PetData::getPetIdentifier()
{
    return petIdentifier;
}

void tama::PetData::setPetIdentifier(const tama::PetIdentifier &petIdentifier)
{
    PetData::petIdentifier = petIdentifier;
}

void tama::PetData::increaseAge()
{
    age++;
}

void tama::PetData::updateHappiness(int h)
{
    happiness += h;
}

void tama::PetData::updateHealth(int h)
{
    health += h;
}

void tama::PetData::makeSleepy()
{
    isSleepy = true;
}

void tama::PetData::makeAwake()
{
    isSleepy = false;
}

const std::string &tama::PetData::getName() const
{
    return name;
}

void tama::PetData::setName(const std::string &name)
{
    PetData::name = name;
}

int tama::PetData::getAge() const
{
    return age;
}

int tama::PetData::getFood() const
{
    return food;
}

int tama::PetData::getHappiness() const
{
    return happiness;
}

int tama::PetData::getHealth() const
{
    return health;
}

void tama::PetData::increaseFood(int f)
{
    PetData::food = std::min(food + f, 5);
}
