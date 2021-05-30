//
// Created by grzegorz on 5/28/21.
//

#include "Home.h"
#include "../menu/wash/Wash.h"
#include "../menu/eat/Eat.h"
#include "../menu/play/menu/PlayMenu.h"

void tama::Home::onInput(tama::Button button)
{
    if (button == Button::A)
    {
        icons.changeSelectedIcon();
    }
    if (button == Button::B)
    {
        int selected = icons.getSelectedIconIndex();
        onIconSelection(selected);
        return;
    }
    if (button == Button::C)
    {
        icons.removeSelection();
    }
}

void tama::Home::onIconSelection(int selected)
{
    switch (selected)
    {
        case 0:
            return;
        case 1:
            context->switchStage(std::make_shared<Eat>(context));
            return;
        case 2:
            context->switchStage(std::make_shared<Wash>(context));
            return;
        case 3:
            context->switchStage(std::make_shared<PlayMenu>(context));
            return;
        case 4:
            return;
        case 5:
            return;
        case 6:
            return;
        case 7:
            return;
        default:
            return;
    }
}

void tama::Home::onInit()
{

}

void tama::Home::onFrame()
{
    if (timeToPetMove->getElapsedTime() >= onePetMoveTime)
    {
        timeToPetMove->startTimer();
        Vec2d futurePosition = pet.getPosition() + Vec2d(5 * petMovingDirection, 0);
        if (util::fitsInContent(pet.getPosition() + Vec2d(pet.getTexture()->width * petMovingDirection, 0)))
        {
            pet.setPosition(futurePosition);
        }
        else
        {
            petMovingDirection = -petMovingDirection;
        }
//
//        if (pet.getPosition().x + pet.getTexture()->width > util::dispWorkspaceRight)
//        {
//            pet.setPosition(util::fromBottomRight(Vec2d(0-pet.getTexture()->width, 0)));
//            petMovingDirection = !petMovingDirection;
//        }
        isPosOne ? pet.setTexture(petFrontPosTwo) : pet.setTexture(petFrontPosOne);
        isPosOne = !isPosOne;
    }
}

tama::Home::Home(const std::shared_ptr<Context> &context) : Stage(context), icons(ActionIcons(scene, context))
{
    timeToPetMove = context->getTimeMonitorCreator()->createTimeMonitor();
    scene->addDrawable(std::shared_ptr<Drawable>(&pet));
}
