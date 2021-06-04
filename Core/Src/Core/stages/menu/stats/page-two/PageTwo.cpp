//
// Created by grzegorz on 6/3/21.
//

#include "PageTwo.h"
#include "../../../main/Home.h"

tama::PageTwo::PageTwo(const std::shared_ptr<Context> &context) : Stage(context)
{
    scene->addDrawable(std::shared_ptr<Text>(&actualPetHappy));
    scene->addDrawable(std::shared_ptr<Text>(&actualPetHungry));
    scene->addDrawable(std::shared_ptr<Text>(&happyText));
    scene->addDrawable(std::shared_ptr<Text>(&hungryText));
    int food = context->getGameState().getPetData().getFood();
    int happy = context->getGameState().getPetData().getHappiness();
    actualPetHungry.setText(getIndicationStr(food));
    actualPetHappy.setText(getIndicationStr(happy));

}

std::string tama::PageTwo::getIndicationStr(int data)
{
    std::string str = ":";
    for (int i = 0; i < data; ++i)
    {
        str.append("_");
    }
    for (int i = data; i < 5; ++i)
    {
        str.append(" ");
    }
    str.append(":");
    return str;
}

void tama::PageTwo::onInput(tama::Button button)
{
    if (button == Button::A)
    {

    }
    else if (button == Button::B)
    {

    }
    else if (button == Button::C)
    {
        context->switchStage(std::make_shared<Home>(context));
    }
}

void tama::PageTwo::onInit()
{

}

void tama::PageTwo::onFrame()
{

}
