//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_MAIN_H
#define VPET_MAIN_H

#include <memory>
#include "../STM32F411Disco-drivers/display/DisplayConfig.h"
#include "../STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.h"

namespace tama
{
    class Main
    {
    public:
        void run();


    private:
        DisplayConfig getDefaultNokia5110DisplayConfig();
        std::shared_ptr<Texture> makeSampleTexture();
    };
}



#endif //VPET_MAIN_H
