//
// Created by grzegorz on 5/17/21.
//

#ifndef VPET_NAMESELECTION_H
#define VPET_NAMESELECTION_H

#include "../../runtime/stage/Stage.h"
#include "../../ui/display/drawable/text/Text.h"
#include "../../common/util/displayPlacementUtils.h"

namespace tama
{
    class NameSelection : public Stage
    {
    public:
        NameSelection(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        // temp
        //int delay = 0;
        Text name;
        Text nameInfo;
        std::string nameText;
       // char charUnderCursor = ' ';
        int currentIndex;
        char currentLetter = ' ';
        int MAX_INDEX = 4;
        std::shared_ptr<TimeMonitor> blinkingTimer;
        unsigned blinkingTime = 1000;
        bool displayBlink = false;
    };
}



#endif //VPET_NAMESELECTION_H
