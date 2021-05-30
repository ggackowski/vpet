//
// Created by grzegorz on 5/30/21.
//

#include "JumpingGame.h"

void frameOnJump();

tama::JumpingGame::JumpingGame(const std::shared_ptr<Context> &context) : Stage(context)
{
    oneFrameTimer = context->getTimeMonitorCreator()->createTimeMonitor();
    scene->addDrawable(std::shared_ptr<Text>(&obstacle));
    scene->addDrawable(std::shared_ptr<Sprite>(&pet));
    scene->addDrawable(std::shared_ptr<Text>(&pointsText));
}

void tama::JumpingGame::onInput(tama::Button button)
{
    if (button == Button::C)
    {
        context->switchStage(std::make_shared<PlayMenu>(context));
    }
    if (button == Button::B)
    {
        isJumping = true;
    }
}

void tama::JumpingGame::onInit()
{

}

void tama::JumpingGame::onFrame()
{
    if (oneFrameTimer->getElapsedTime() >= oneFrameTime)
    {
        oneFrameTimer->startTimer();
        if (isJumping) { frameOnJump(); }
        else {
            isPosOne = !isPosOne;
            isPosOne ? pet.setTexture(petFrontPosTwo) : pet.setTexture(petFrontPosOne);
        }
        obstacle.move(Vec2d(-5, 0));
        if (!tama::util::fitsInContent(obstacle.getPosition()))
        {
            points += 10;
            pointsText.setText(std::to_string(points));
            obstacle.setPosition(Vec2d(tama::util::fromBottomRight(Vec2d(-6, -6))));
        }
    }
}

void tama::JumpingGame::frameOnJump()
{
    if (jumpAnimationProgress > jumpAnimationEnd)
    {
        isJumping = false;
        jumpAnimationProgress = 0;
    }
    else
    {
        onJumpingAnimationFrame();
        jumpAnimationProgress++;
    }
}

void tama::JumpingGame::onJumpingAnimationFrame()
{
    switch (jumpAnimationProgress)
    {
        case 0:
            pet.move(Vec2d(0, -4));
            return;
        case 1:
            pet.move(Vec2d(0, -4));
            return;
        case 2:
            pet.move(Vec2d(0, -4));
            return;
        case 3:
            pet.move(Vec2d(0, 4));
            return;
        case 4:
            pet.move(Vec2d(0, 4));
            return;
        case 5:
            pet.move(Vec2d(0, 4));
            return;
    }
}