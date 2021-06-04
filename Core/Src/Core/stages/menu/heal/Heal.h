//
// Created by grzegorz on 6/4/21.
//

#ifndef VPET_HEAL_H
#define VPET_HEAL_H

#include "../../../runtime/stage/Stage.h"
#include "../../../ui/display/drawable/sprite/Sprite.h"
#include "../../../assets/menu/heal/heal.texture.h"
#include "../wash/Wash.h"
#include "../../../ui/common-components/happy-jump/HappyJump.h"

namespace tama
{
class Heal : public Stage
{
public:
    Heal(const std::shared_ptr<Context> &context);

    void onInput(Button button) override;

    void onInit() override;

    void onFrame() override;

private:
    bool firstHealIcon = false;
    Sprite healIcon = Sprite(context->getTextureLoader()->load(tama::asset::heal0), tama::util::toContentArea(Vec2d(30, 10)));
    Sprite pet = Sprite(context->getPetTexture(frontStandard), tama::util::fromBottomLeft(Vec2d(10, -20)));
    std::shared_ptr<TimeMonitor> timeToAnimationChange = context->getTimeMonitorCreator()->createTimeMonitor();
    HappyJump happyJump = HappyJump(*scene, *context);
    const int animationFrameTime = 1000;
    int currentAnimationFrame = 0;
    int maxAnimationFrame = 6;
    int isHappyJump = false;
};
}



#endif //VPET_HEAL_H
