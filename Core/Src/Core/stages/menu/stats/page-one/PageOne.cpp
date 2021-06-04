//
// Created by grzegorz on 6/3/21.
//

#include "PageOne.h"
#include "../../../main/Home.h"
#include "../page-two/PageTwo.h"

tama::PageOne::PageOne(const std::shared_ptr<Context> &context) : Stage(context)
{
    scene->addDrawable(std::shared_ptr<Text>(&nameText));
    scene->addDrawable(std::shared_ptr<Text>(&ageText));
    scene->addDrawable(std::shared_ptr<Text>(&actualPetAge));
    scene->addDrawable(std::shared_ptr<Text>(&actualPetName));
}

void tama::PageOne::onInput(tama::Button button)
{
    if (button == Button::A)
    {
        context->switchStage(std::make_shared<PageTwo>(context));
    }
    else if (button == Button::B)
    {

    }
    else if (button == Button::C)
    {
        context->switchStage(std::make_shared<Home>(context));
    }
}

void tama::PageOne::onInit()
{

}

void tama::PageOne::onFrame()
{

}
