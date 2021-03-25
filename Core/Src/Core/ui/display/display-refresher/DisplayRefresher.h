//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_DISPLAYREFRESHER_H
#define VPET_DISPLAYREFRESHER_H

#include <memory>
#include "../Display.h"
#include "../display-data/DisplayData.h"

namespace tama
{
    class DisplayRefresher
    {
    public:
        DisplayRefresher(const std::shared_ptr<Display> &display, const std::shared_ptr<DisplayData> &displayData);

        void refresh();

    private:
        std::shared_ptr<Display> display;

        std::shared_ptr<DisplayData> displayData;
    };

}



#endif //VPET_DISPLAYREFRESHER_H
