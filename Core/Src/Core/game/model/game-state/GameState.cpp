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
