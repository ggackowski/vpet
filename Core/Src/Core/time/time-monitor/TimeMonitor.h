//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_TIMEMONITOR_H
#define VPET_TIMEMONITOR_H

namespace tama
{
    class TimeMonitor
    {
    public:
        virtual void startTimer() = 0;
        virtual unsigned getElapsedTime() = 0;
    };
}



#endif //VPET_TIMEMONITOR_H
