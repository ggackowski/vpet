//
// Created by grzegorz on 5/8/21.
//

#include "Time.h"

tama::Time::Time()
{
    seconds = 0;
    minutes = 0;
    hours = 12;
}

int tama::Time::getSeconds()
{
    return seconds;
}

int tama::Time::getMinutes()
{
    return minutes;
}

int tama::Time::getHours()
{
    return hours;
}

void tama::Time::incrementSeconds()
{
    seconds++;
    seconds %= (MAX_SECONDS + 1);
}

void tama::Time::incrementMinutes()
{
    minutes++;
    minutes %= (MAX_MINUTES + 1);
}

void tama::Time::incrementHours()
{
    hours++;
    hours %= (MAX_HOURS + 1);
}

void tama::Time::updateBySeconds(int seconds)
{
    int minutesDiff = seconds / 60;
    int hoursDiff = seconds / 60 / 60;
    this->seconds += seconds;
    this->seconds %= (MAX_SECONDS + 1);
    this->minutes += minutesDiff;
    this->minutes %= (MAX_MINUTES + 1);
    this->hours += hoursDiff;
    this->hours %= (MAX_HOURS + 1);
}
