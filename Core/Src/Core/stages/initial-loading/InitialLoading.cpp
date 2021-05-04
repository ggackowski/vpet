//
// Created by grzegorz on 4/29/21.
//

#include "InitialLoading.h"
#include "../../assets/egg.texture.h"

void tama::InitialLoading::onInput(tama::Button button)
{
    i++;
    if (button == Button::C)
    {
        egg->move(Vec2d(1, 0));
    } else if (button == Button::B) {
        egg->move(Vec2d(-1, 0));
    }

    if (i == 10)
    {
        context->switchStage(std::make_shared<InitialLoading>(context));
    }

    int a = 5;
    a = 3;
}

void tama::InitialLoading::onInit()
{

    int b = 4;
    int c = 3;
}

void tama::InitialLoading::onFrame()
{
    int w = 3;
    w = 1;
}

tama::InitialLoading::InitialLoading(const std::shared_ptr<Context> &context) : Stage(context)
{
    context->getInput()->addListener(std::make_shared<InitialLoading>(*this));
    egg = std::make_shared<Sprite>(context->getTextureLoader()->load(tama::asset::egg1), Vec2d(10, 37));
    scene->addDrawable(egg);
}
