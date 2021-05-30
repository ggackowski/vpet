//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_STM32INPUT_H
#define VPET_STM32INPUT_H

#include "../../Core/input/Input.h"

namespace tama
{
    class Stm32Input : public Input
    {
        void update() override;
        Button button = tama::Button::NONE;
        int delay = 0;
    };
}



#endif //VPET_STM32INPUT_H
