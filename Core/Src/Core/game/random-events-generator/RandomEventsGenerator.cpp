//
// Created by grzegorz on 6/3/21.
//


#include "RandomEventsGenerator.h"

void tama::RandomEventsGenerator::generateRandomEvents()
{
    int shouldPoop = rand() % 10;
    if (shouldPoop == 0)
    {
        gameState.addPoop();
    }
//    int shouldBecomeIll = rand() % (gameState.getPetData().getHealth() * 10);
//    if (shouldBecomeIll == 0)
//    {
//        gameState.
//    }
}

tama::RandomEventsGenerator::RandomEventsGenerator(tama::GameState &gameState) : gameState(gameState)
{
    srand(time(nullptr));
}
