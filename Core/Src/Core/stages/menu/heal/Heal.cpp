//
// Created by grzegorz on 6/4/21.
//

#include "Heal.h"
#include "../../main/Home.h"
#include "../../../ui/common-components/happy-jump/HappyJump.h"

tama::Heal::Heal(const std::shared_ptr<Context> &context) : Stage(context)
{
    scene->addDrawable(std::shared_ptr<Sprite>(&pet));
    scene->addDrawable(std::shared_ptr<Sprite>(&healIcon));
}

void tama::Heal::onInput(tama::Button button)
{

}

void tama::Heal::onInit()
{

}

void tama::Heal::onFrame()
{
    if (isHappyJump)
    {
        if (!happyJump.onFrame()) { context->switchStage(std::make_shared<Home>(context)); }
        return;
    }
    if (timeToAnimationChange->getElapsedTime() > animationFrameTime)
    {
        timeToAnimationChange->startTimer();
        pet.setTexture(context->getPetTexture(firstHealIcon ? frontHappy : frontStandard));
        healIcon.setTexture(context->getTextureLoader()->load(firstHealIcon ? asset::heal1 : asset::heal0));
        currentAnimationFrame++;
        firstHealIcon = !firstHealIcon;
        if (currentAnimationFrame == maxAnimationFrame)
        {
            if (context->getGameState().getPetData().getHealth() == 0)
            {
                context->getGameState().getPetData().updateHealth(2);
                isHappyJump = true;
                happyJump.init();
            }
            else
            {
                context->switchStage(std::make_shared<Home>(context));
            }
        }
    }
}
