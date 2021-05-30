//
// Created by grzegorz on 5/26/21.
//

#include "TimeSelection.h"
#include "../../main/Home.h"

void tama::TimeSelection::onInput(tama::Button button)
{
	datetimeText.updateChar(charUnderCursor, cursorToTextPosition());
    if (button == tama::Button::B)
    {
        cursorPosition++;   // @todo edge conditions
        if (cursorPosition == LAST_STEP + 1)
        {
            context->switchStage(std::make_shared<NameSelection>(context));
        }
    }
    if (button == tama::Button::C)
    {
        cursorPosition--;   // @todo edge conditions
    }
    else if (button == tama::Button::A)
    {
        incrementOnCursorPosition();
        updateText();
    }
    charUnderCursor = datetimeText.getText()[cursorToTextPosition()];
}

void tama::TimeSelection::incrementOnCursorPosition()
{
    Datetime & datetime = context->getGameState().getDateTime();
    switch (cursorPosition)
    {
        case 0: datetime.getTime().incrementHours(); lastChangedValue = datetime.getTime().getHours(); return;
        case 1: datetime.getTime().incrementMinutes(); lastChangedValue = datetime.getTime().getMinutes(); return;
        case 2: datetime.getDate().incrementMonth(); lastChangedValue = datetime.getDate().getMonth(); return;
        case 3: datetime.getDate().incrementDay(); lastChangedValue = datetime.getDate().getDay(); return;
    }
}

void tama::TimeSelection::onInit()
{

}

void tama::TimeSelection::onFrame()
{
  if (everySecondBlink->getElapsedTime() > second)
  {
      everySecondBlink->startTimer();
      displayColon ? datetimeText.updateChar(':', COLON_POS) : datetimeText.updateChar(' ', COLON_POS);
      displayColon = !displayColon;
  }
  if (everyHalfSecondBlink->getElapsedTime() > halfSecond)
  {
      everyHalfSecondBlink->startTimer();
      displayCursor ? datetimeText.updateChar('_', cursorToTextPosition()) : datetimeText.updateChar(charUnderCursor, cursorToTextPosition());
      displayCursor = !displayCursor;
  }
}

void tama::TimeSelection::updateText()
{
    if (lastChangedValue <= 9)
    {
        setTwoChars('0', '0' + lastChangedValue, cursorToTextPosition() - 1);
    }
    else
    {
        int valueUnits = lastChangedValue % 10;
        int valueTens = lastChangedValue / 10;
        setTwoChars('0' + valueTens, '0' + valueUnits, cursorToTextPosition() - 1);
    }
}

void tama::TimeSelection::setTwoChars(char c1, char c2, int position)
{
    datetimeText.updateChar(c1, position);
    datetimeText.updateChar(c2, position + 1);
}

unsigned tama::TimeSelection::cursorToTextPosition()
{
    switch (cursorPosition)
    {
        case 0: return 1;
        case 1: return 4;
        case 2: return 7;
        case 3: return 10;
    }
    return 0;
}

tama::TimeSelection::TimeSelection(const std::shared_ptr<Context> &context) : Stage(context)
{
    everyHalfSecondBlink = context->getTimeMonitorCreator()->createTimeMonitor();
    everySecondBlink = context->getTimeMonitorCreator()->createTimeMonitor();
    datetimeText.setText(std::string(
            "12:00\n01-01"
            ));
    scene->addDrawable(std::shared_ptr<Text>(&datetimeText));
    scene->addDrawable(std::shared_ptr<Text>(&explanationText));
}


/*  TIME:
 *  21:48
 *  26-05
 *
 */
