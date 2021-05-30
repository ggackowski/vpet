//
// Created by grzegorz on 5/30/21.
//

#ifndef VPET_STM32TIMEMONITORCREATOR_H
#define VPET_STM32TIMEMONITORCREATOR_H

#include "../../Core/time/time-monitor/time-monitor-creator/TimeMonitorCreator.h"
#include "Stm32TimeMonitor.h"

namespace tama
{
    class Stm32TimeMonitorCreator : public TimeMonitorCreator
    {
    public:
        std::shared_ptr<TimeMonitor> createTimeMonitor() override;

    };
}



#endif //VPET_STM32TIMEMONITORCREATOR_H
