//
// Created by grzegorz on 3/25/21.
//

#include "DisplayRefresher.h"

#include <utility>

tama::DisplayRefresher::DisplayRefresher(const std::shared_ptr<Display> &display,
                                         const std::shared_ptr<DisplayData> &displayData) : display(display),
                                                                                            displayData(displayData)
{}

void tama::DisplayRefresher::refresh()
{
//    display->setData(displayData->getDrawingData());
//    display->displayData();
}


