//
// Created by grzegorz on 5/30/21.
//

#include "Stm32TimeMonitorCreator.h"

std::shared_ptr<tama::TimeMonitor> tama::Stm32TimeMonitorCreator::createTimeMonitor()
{
    return std::make_shared<Stm32TimeMonitor>();
}
