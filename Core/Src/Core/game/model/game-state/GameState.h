//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_GAMESTATE_H
#define VPET_GAMESTATE_H

#include "../pet-data/PetData.h"
#include "../datetime/Datetime.h"
#include "../../pet-db/PetDb.h"

namespace tama
{
    class GameState
    {
    public:
        PetData & getPetData();
        Datetime & getDateTime();
        PetDb & getPetDb();
    private:
        PetData pet;
        Datetime datetime;
        PetDb petDb;
        int poopsCount;
        int moneyCount;
    };
}



#endif //VPET_GAMESTATE_H
