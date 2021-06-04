//
// Created by grzegorz on 5/8/21.
//

#include "Datetime.h"

tama::Time &tama::Datetime::getTime()
{
    return time;
}

tama::Date &tama::Datetime::getDate()
{
    return date;
}

void tama::Datetime::updateBySeconds(int seconds)
{
    int currentHours = time.getHours();
    time.updateBySeconds(seconds);
    if (currentHours == 23 && time.getHours() == 0)
    {
        date.updateByDay();
    }
}

std::string tama::Datetime::toString()
{
    return std::string(
            std::to_string(date.getDay()) + "-" +
            std::to_string(date.getMonth()) + "\n" +
            std::to_string(time.getHours()) + ":" +
            std::to_string(time.getMinutes())
            );
}
