//
// Created by grzegorz on 5/28/21.
//

#include "Home.h"
#include "../menu/wash/Wash.h"
#include "../menu/eat/Eat.h"
#include "../menu/play/menu/PlayMenu.h"
#include "../../assets/pet/misc/misc.texture.h"
#include "../menu/stats/page-one/PageOne.h"
#include "../menu/heal/Heal.h"
#include "../menu/lamp/Lamp.h"
#include "../time/TimeView.h"


void tama::Home::onInput(tama::Button button)
{
    if (button == Button::A)
    {
        icons.changeSelectedIcon();
    }
    if (button == Button::B)
    {
        int selected = icons.getSelectedIconIndex();
        if (selected == 9)
        {
            context->switchStage(std::make_shared<TimeView>(context));
        }
        else
        {
            onIconSelection(selected);
        }
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
            context->switchStage(std::make_shared<PageOne>(context));
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
        case 4:  //PH_2
            return;
        case 5:
            return;
        case 6:
            context->switchStage(std::make_shared<Heal>(context));
            return;
        case 7:
            context->switchStage(std::make_shared<Lamp>(context));
            return;
        case 8: //PH_2
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
    if (shouldUpdatePet())
    {
        timeToPetMove->startTimer();
        if (context->getGameState().isLightsOn())
        {
            lightsOff.hide();
            updatePetPosition();
            updatePoops();
        }
        else
        {
            lightsOff.show();
        }
    }
}

void tama::Home::updatePoops()
{
    int poopsCount = this->context->getGameState().getPoopsCount();
    if (poopsCount > this->poops.size())
    {
        for (int i = this->poops.size(); i < poopsCount; ++i)
        {
            int positionX = 9 + 8 * i;
            auto poop = std::make_shared<Sprite>(this->context->getTextureLoader()->load(tama::asset::misc::poop0),
                                     tama::util::fromBottomRight(tama::Vec2d(-positionX, -22)));
            this->poops.emplace_back(poop);
            this->scene->addDrawable(poop);
        }
    }
    else if (poopsCount == 0)
    {
            this->poops.erase(this->poops.begin(), this->poops.end());
    }
    for (int i = 0; i < poops.size(); ++i)
    {
        poops.at(i)->setTexture(context->getTextureLoader()->load(isFirstPoopTextureDisplayed ? tama::asset::misc::poop1 : tama::asset::misc::poop0));
    }
    isFirstPoopTextureDisplayed = !isFirstPoopTextureDisplayed;
}

void tama::Home::updatePetPosition()
{
    tama::Vec2d futurePosition = this->pet.getPosition() + tama::Vec2d(5 * this->petMovingDirection, 0);
    if (tama::util::fitsInContent(
            this->pet.getPosition() + tama::Vec2d(this->pet.getTexture()->width * this->petMovingDirection, 0)))
    {
        this->pet.setPosition(futurePosition);
    }
    else
    {
        this->petMovingDirection = -this->petMovingDirection;
    }

    this->isPosOne ? this->pet.setTexture(this->petFrontPosTwo) : this->pet.setTexture(this->petFrontPosOne);
    this->isPosOne = !this->isPosOne;
}

bool tama::Home::shouldUpdatePet()
{ return this->timeToPetMove->getElapsedTime() >= this->onePetMoveTime; }

tama::Home::Home(const std::shared_ptr<Context> &context) : Stage(context), icons(ActionIcons(scene, context))
{
    timeToPetMove = context->getTimeMonitorCreator()->createTimeMonitor();
    scene->addDrawable(std::shared_ptr<Drawable>(&pet));
    scene->addDrawable(std::shared_ptr<Drawable>(&lightsOff));
}
