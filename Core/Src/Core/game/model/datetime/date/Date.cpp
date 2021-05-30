//
// Created by grzegorz on 5/8/21.
//

#include "Date.h"

tama::Date::Date()
{
    day = 1;
    month = 1;
}

int tama::Date::maxDayForMonth(int month)
{
    switch(month)
    {
        case 1: return 31;
        case 2: return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
    return 31;
}

void tama::Date::incrementDay()
{
    const int maxDay = maxDayForMonth(month);
    day++;
    if (day == maxDay + 1)
    {
        day = 1;
    }
}

void tama::Date::incrementMonth()
{
    month++;
    if (month == MAX_MONTH + 1)
    {
        month = 1;
    }
}

int tama::Date::getDay()
{
    return day;
}

int tama::Date::getMonth()
{
    return month;
}

void tama::Date::updateByDay()
{
    const int maxDay = maxDayForMonth(month);
    day++;
    if (day == maxDay + 1)
    {
        day = 1;
        incrementMonth();
    }
}
