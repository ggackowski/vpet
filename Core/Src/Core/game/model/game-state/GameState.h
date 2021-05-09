//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_GAMESTATE_H
#define VPET_GAMESTATE_H

#include "../pet-data/PetData.h"
#include "../datetime/Datetime.h"

namespace tama
{
    class GameState
    {
    private:
        PetData pet;
        Datetime datetime;
        int poopsCount;
        int moneyCount;
    };
}



#endif //VPET_GAMESTATE_H
