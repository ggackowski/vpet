//
// Created by grzegorz on 5/4/21.
//

#include "Stm32TimeMonitor.h"

void tama::Stm32TimeMonitor::startTimer()
{
    timestamp = HAL_GetTick();
}

unsigned int tama::Stm32TimeMonitor::getElapsedTime()
{
    return HAL_GetTick() - timestamp;
}
