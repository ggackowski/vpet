//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_GAMESTATE_H
#define VPET_GAMESTATE_H

#include "../pet-data/PetData.h"
#include "../datetime/Datetime.h"
#include "../../pet-db/PetDb.h"
#include "../pet-texture/PetTexture.h"
#include "../../../time/time-monitor/TimeMonitor.h"

namespace tama
{
    class GameState
    {
    public:
        GameState();

        PetData & getPetData();
        Datetime & getDateTime();
        PetDb & getPetDb();
        TextureAsset & getPetTextureAsset(PetTextureVariant petTextureVariant);
        int getPoopsCount();
        void removePoops();
        void addPoop();
        bool isLightsOn() const;
        void setLightsOn(bool lightsOn);
        void setTimeTimer(std::shared_ptr<TimeMonitor> tm);
        void updateTime();

    private:
        PetData pet;
        Datetime datetime;
        PetDb petDb;
        PetTexture petTexture;
        int poopsCount = 2;
        int moneyCount = 0;
        bool lightsOn = true;
        void selectPet();
        std::shared_ptr<TimeMonitor> timeTimer;

    };
}



#endif //VPET_GAMESTATE_H
