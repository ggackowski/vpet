//
// Created by grzegorz on 5/8/21.
//

#include "GameState.h"

tama::PetData &tama::GameState::getPetData()
{
    return pet;
}

tama::Datetime &tama::GameState::getDateTime()
{
    return datetime;
}

tama::PetDb &tama::GameState::getPetDb()
{
    return petDb;
}

tama::GameState::GameState() : petTexture(pet.getPetIdentifier(), petDb)
{
    selectPet();
}

void tama::GameState::selectPet()
{
    pet.setPetIdentifier({first, BABY, MASCULINE});
}

tama::TextureAsset & tama::GameState::getPetTextureAsset(tama::PetTextureVariant petTextureVariant)
{
    return *petTexture.getTextureAsset(petTextureVariant);
}

int tama::GameState::getPoopsCount()
{
    return poopsCount;
}

void tama::GameState::removePoops()
{
    poopsCount = 0;
}

void tama::GameState::addPoop()
{
    poopsCount++;
}

bool tama::GameState::isLightsOn() const
{
    return lightsOn;
}

void tama::GameState::setLightsOn(bool lightsOn)
{
    GameState::lightsOn = lightsOn;
}

void tama::GameState::setTimeTimer(std::shared_ptr<TimeMonitor> tm)
{
    timeTimer = tm;
}

void tama::GameState::updateTime()
{
    int timePassedInSeconds = timeTimer->getElapsedTime();
    timeTimer->startTimer();
    datetime.updateBySeconds(timePassedInSeconds / 1000);
}
