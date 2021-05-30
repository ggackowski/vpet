//
// Created by grzegorz on 5/28/21.
//

#ifndef VPET_HOME_H
#define VPET_HOME_H

#include "../../runtime/stage/Stage.h"
#include "../../ui/display/drawable/sprite/Sprite.h"
#include "../name-selection/NameSelection.h"
#include "../../assets/pet/first-male/baby/fir.st-male-baby.texture.h"
#include "../../ui/common-components/action-icons/ActionIcons.h"

namespace tama
{
    using namespace tama::asset;

    class Home : public Stage
    {


    public:
        Home(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        int petMovingDirection = 1;
        //int delay = 0;
        std::shared_ptr<TimeMonitor> timeToPetMove;
        const unsigned onePetMoveTime = 700;
        bool isPosOne = true;
        ActionIcons icons;
        std::shared_ptr<Texture> petFrontPosOne = context->getTextureLoader()->load(firstMale::baby::frontOne);
        std::shared_ptr<Texture> petFrontPosTwo = context->getTextureLoader()->load(firstMale::baby::frontTwo);
        Sprite pet = Sprite(petFrontPosOne, Vec2d(tama::util::fromBottomLeft(Vec2d(0, -petFrontPosOne->height))));

        void onIconSelection(int selected);
    };
}



#endif //VPET_HOME_H
