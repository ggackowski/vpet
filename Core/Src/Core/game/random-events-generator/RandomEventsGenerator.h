//
// Created by grzegorz on 6/3/21.
//

#ifndef VPET_RANDOMEVENTSGENERATOR_H
#define VPET_RANDOMEVENTSGENERATOR_H

#include "../model/game-state/GameState.h"
#include <cstdlib>
#include <ctime>

namespace tama
{
    class RandomEventsGenerator
    {
    public:
        RandomEventsGenerator(tama::GameState &gameState);
        void generateRandomEvents();
    private:
        GameState & gameState;
    };
}



#endif //VPET_RANDOMEVENTSGENERATOR_H
