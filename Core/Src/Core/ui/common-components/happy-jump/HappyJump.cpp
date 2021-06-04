//
// Created by grzegorz on 6/3/21.
//

#include "HappyJump.h"
#include "../../../common/util/displayPlacementUtils.h"


tama::HappyJump::HappyJump(tama::Scene &scene, tama::Context & context) : scene(scene), context(context)
{
}

void tama::HappyJump::init()
{
    scene.addDrawable(std::shared_ptr<Sprite>(&sun));
    scene.addDrawable(std::shared_ptr<Sprite>(&pet));
    scene.hideAll();
    pet.show();
    sun.show();
    pet.setPosition(tama::util::fromBottomLeft(tama::Vec2d(7, -20)));
}

int tama::HappyJump::onFrame()
{
    if (this->oneFrameTimeMonitor->getElapsedTime() > this->oneFrameTime)
    {
        this->oneFrameTimeMonitor->startTimer();
        this->animationFrame++;
        if (this->animationFrame == this->animationMaxLength)
        {
            return 0;
        }
        pet.setPosition(tama::util::fromBottomLeft(this->animationFrame % 2 ? tama::Vec2d(7, -45) : tama::Vec2d(7, -20)));
        pet.setTexture(context.getPetTexture(animationFrame ? frontHappy : frontStandard));
        animationFrame % 2 ? sun.show() : sun.hide();
    }
    return 1;
}
