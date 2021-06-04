//
// Created by grzegorz on 6/4/21.
//

#include "TimeView.h"
#include "../main/Home.h"

tama::TimeView::TimeView(const std::shared_ptr<Context> &context) : Stage(context)
{
    context->getGameState().updateTime();
    timeText.setText(context->getGameState().getDateTime().toString());
    scene->addDrawable(std::shared_ptr<Text>(&timeText));
}

void tama::TimeView::onInput(tama::Button button)
{
    if (button == Button::B)
    {
        context->switchStage(std::make_shared<Home>(context));
    }
}

void tama::TimeView::onInit()
{

}

void tama::TimeView::onFrame()
{

}
