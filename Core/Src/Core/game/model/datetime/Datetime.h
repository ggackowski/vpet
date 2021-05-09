//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_DATETIME_H
#define VPET_DATETIME_H

#include "time/Time.h"
#include "date/Date.h"

namespace tama
{
    class Datetime
    {
    private:
        Time time;
        Date date;
    };
}



#endif //VPET_DATETIME_H
