//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_STM32TIMEMONITOR_H
#define VPET_STM32TIMEMONITOR_H

#include "../../Core/time/time-monitor/TimeMonitor.h"
#include <stm32f4xx_hal.h>

namespace tama
{
    class Stm32TimeMonitor : public TimeMonitor
    {
        void startTimer() override;

        unsigned int getElapsedTime() override;

    private:
        uint32_t timestamp;
    };
}



#endif //VPET_STM32TIMEMONITOR_H
