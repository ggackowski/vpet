//
// Created by grzegorz on 5/29/21.
//

#include "Wash.h"
#include "../../main/Home.h"
#include "../../../ui/common-components/happy-jump/HappyJump.h"


void tama::Wash::onInput(tama::Button button)
{

}

void tama::Wash::onInit()
{

}

void tama::Wash::onFrame()
{
    if (isHappyJump)
    {
        if (!happyJump.onFrame()) { context->switchStage(std::make_shared<Home>(context)); }
        return;
    }
    for (int i = 0; i < washElementsCount; ++i)
    {
        washElements[i].move(Vec2d(-8, 0));
    }
    animationStep++;
    if (animationStep == animationLength)
    {
        if (context->getGameState().getPoopsCount() > 0)
        {
            context->getGameState().removePoops();
            happyJump.init();
            isHappyJump = true;
        }
        else
        {
            context->switchStage(std::make_shared<Home>(context));
        }
    }
}

tama::Wash::Wash(const std::shared_ptr<Context> &context) : Stage(context)
{
    auto washTexture = context->getTextureLoader()->load(tama::asset::menu::wash);
    for (int i = 0; i < washElementsCount; ++i)
    {
        washElements[i].setTexture(washTexture);
        washElements[i].setPosition(tama::util::fromTopRight(Vec2d(-washTexture->width, i * washTexture->height)));
        scene->addDrawable(std::shared_ptr<Sprite>(&(washElements[i])));
    }
}
