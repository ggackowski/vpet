//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_STM32SOUNDPLAYINGSTRATEGY_H
#define VPET_STM32SOUNDPLAYINGSTRATEGY_H
#include "../../Core/sound/SoundPlayingStrategy.h"
#include <tim.h>

namespace tama
{
    class Stm32SoundPlayingStrategy : public SoundPlayingStrategy
    {
    public:
        void play(Tone tone) override
        {
            if (tone.value == 0)
            {
                __HAL_TIM_SET_PRESCALER(&htim3, 0);
            }
            else
            {
                __HAL_TIM_SET_PRESCALER(&htim3, 175 - 5 * (tone.value - 1));
            }

        }

        void stop() override
        {
            __HAL_TIM_SET_PRESCALER(&htim3, 0);
        }
    };
}

#endif //VPET_STM32SOUNDPLAYINGSTRATEGY_H
