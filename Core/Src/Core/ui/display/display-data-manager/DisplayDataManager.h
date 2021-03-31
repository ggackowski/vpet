//
// Created by grzegorz on 3/31/21.
//

#ifndef VPET_DISPLAYDATAMANAGER_H
#define VPET_DISPLAYDATAMANAGER_H

#include "../display-data/DisplayData.h"

namespace tama
{
    class DisplayDataManager
    {
    public:
        virtual DisplayData getActiveSceneDisplayData(std::shared_ptr<Texture>) = 0;

    };
}

#endif //VPET_DISPLAYDATAMANAGER_H
