//
// Created by grzegorz on 5/17/21.
//

#include "NameSelection.h"
#include "../initial/time-selection/TimeSelection.h"
#include "../initial-loading/InitialLoading.h"
#include "../main/Home.h"

void tama::NameSelection::onInput(tama::Button button)
{
    if (button == tama::Button::A)
    {
        if (currentLetter == ' ')
        {
            currentLetter = 'A';
        }
        else if (currentLetter == 'Z')
        {
            currentLetter = ' ';
        }
        else
        {
            currentLetter++;
        }
        nameText[currentIndex] = currentLetter;
        name.setText(nameText);
    }
    if (button == tama::Button::B)
    {
        if (currentIndex == MAX_INDEX)
        {
            context->switchStage(std::make_shared<Home>(context));
            return;
        }
    	name.updateChar(currentLetter, currentIndex);
        currentIndex++;
        currentLetter = ' ';
    }
}

void tama::NameSelection::onInit()
{

}

void tama::NameSelection::onFrame()
{
    if (blinkingTimer->getElapsedTime() >= blinkingTime)
    {
        blinkingTimer->startTimer();
        if (displayBlink)
        {
            name.updateChar(currentLetter, currentIndex);
        }
        else
        {
//            charUnderCursor = nameText[currentIndex];
            name.updateChar('_', currentIndex);
        }
        displayBlink = !displayBlink;
    }
}

tama::NameSelection::NameSelection(const std::shared_ptr<Context> &context) : Stage(context)
{
    blinkingTimer = context->getTimeMonitorCreator()->createTimeMonitor();
    blinkingTimer->startTimer();
    currentIndex = 0;
    nameText = "     ";
    name = Text(tama::util::toContentArea(Vec2d(0, 20)));
    nameInfo = Text(tama::util::toContentArea(Vec2d(0, 0)));
    nameInfo.setText("NAME");
    name.setText(nameText);
    scene->addDrawable(std::shared_ptr<Text>(&nameInfo));
    scene->addDrawable(std::shared_ptr<Text>(&name));

}
