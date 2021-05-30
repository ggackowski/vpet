//
// Created by grzegorz on 5/30/21.
//

#ifndef VPET_TIMEMONITORCREATOR_H
#define VPET_TIMEMONITORCREATOR_H

#include "../TimeMonitor.h"
#include <memory>

namespace tama
{
    class TimeMonitorCreator
    {
    public:
        virtual std::shared_ptr<TimeMonitor> createTimeMonitor() = 0;
    };
}

#endif //VPET_TIMEMONITORCREATOR_H
