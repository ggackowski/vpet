//
// Created by grzegorz on 5/30/21.
//

#ifndef VPET_JUMPINGGAME_H
#define VPET_JUMPINGGAME_H

#include "../../../../runtime/stage/Stage.h"
#include "../../../../ui/display/drawable/text/Text.h"
#include "../../../../ui/display/drawable/sprite/Sprite.h"
#include "../menu/PlayMenu.h"

namespace tama
{
    class JumpingGame : public Stage
    {
    public:
        JumpingGame(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        Text obstacle = Text(std::string("H"), tama::util::fromBottomRight(Vec2d(-6, -6)));
        Text pointsText = Text(std::string("0"), Vec2d(20, 5));
//        std::shared_ptr<Texture> petFrontPosOne = context->getTextureLoader()->load(
//                *context->getGameState()
//                    .getPetDb()
//                    .getPetTextures({first, BABY, MASCULINE})
//                    .frontStandard);
        std::shared_ptr<Texture> petFrontPosOne = context->getPetTexture(frontStandard);
        std::shared_ptr<Texture> petFrontPosTwo = context->getTextureLoader()->load(firstMale::baby::frontTwo);
        Sprite pet = Sprite(petFrontPosOne, Vec2d(tama::util::fromBottomLeft(Vec2d(5, -petFrontPosOne->height + 1))));
        std::shared_ptr<TimeMonitor> oneFrameTimer;
        bool isPosOne = true;
        bool isJumping = false;
        int jumpAnimationProgress = 0;
        int jumpAnimationEnd = 5;
        unsigned oneFrameTime = 500;
        int points = 0;

        void frameOnJump();

        void onJumpingAnimationFrame();
    };
}



#endif //VPET_JUMPINGGAME_H
