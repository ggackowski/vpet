//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_TIME_H
#define VPET_TIME_H
#include <string>

namespace tama
{
    class Time
    {
    public:
        Time();
        void updateBySeconds(int seconds);
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        int getSeconds();
        int getMinutes();
        int getHours();
    private:
        const int MAX_SECONDS = 59;
        const int MAX_MINUTES = 59;
        const int MAX_HOURS = 23;
        int seconds;
        int minutes;
        int hours;
    };
}



#endif //VPET_TIME_H
