//
// Created by grzegorz on 5/26/21.
//

#ifndef VPET_TIMESELECTION_H
#define VPET_TIMESELECTION_H

#include "../../../runtime/stage/Stage.h"
#include "../../../ui/display/drawable/text/Text.h"

namespace tama
{
    class TimeSelection : public Stage
    {
    public:
        TimeSelection(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        Text datetimeText = Text(Vec2d(3, 11));
        bool displayColon = false;
        bool displayCursor = false;
        const unsigned COLON_POS = 2;
        const unsigned LAST_STEP = 3;
        const unsigned ENTER_POS = 5;
        unsigned cursorPosition = 0;
        int lastChangedValue;
        char charUnderCursor = '2';
        Text explanationText = Text(std::string("DATE"), Vec2d(3, 3));
        // temp
        int delay = 0;
        std::shared_ptr<TimeMonitor> everySecondBlink;
        unsigned second = 1000;
        unsigned halfSecond = 500;
        std::shared_ptr<TimeMonitor> everyHalfSecondBlink;

        unsigned cursorToTextPosition();

        void incrementOnCursorPosition();

        void setTwoChars(char c1, char c2, int position);

        void updateText();
    };
}



#endif //VPET_TIMESELECTION_H
