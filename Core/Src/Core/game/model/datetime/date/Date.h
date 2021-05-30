//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_DATE_H
#define VPET_DATE_H

namespace tama
{
    class Date
    {
    public:
        Date();
        void incrementDay();
        void incrementMonth();
        int getDay();
        int getMonth();
        void updateByDay();
    private:
        const int MAX_MONTH = 12;
        static int maxDayForMonth(int month);
        int day;
        int month;
    };
}



#endif //VPET_DATE_H
