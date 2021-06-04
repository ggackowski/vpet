//
// Created by grzegorz on 6/2/21.
//

#include "PickFood.h"
#include "../Eat.h"
#include "../../../../assets/menu/eat/meal/meal.texture.h"

void tama::PickFood::onInput(tama::Button button)
{
    if (state == tama::eat::SELECT)
    {
        if (button == Button::A)
        {
            selectedFoodId++;
            selectedFoodId %= food.size();
            selectedFood.setTexture(context->getTextureLoader()->load(*food.at(selectedFoodId)));
        }
        else if (button == Button::B)
        {
            cursor.hide();
            state = tama::eat::EAT;
        }
        else if (button == Button::C)
        {
            context->switchStage(std::make_shared<Eat>(context));
        }
    }

}

void tama::PickFood::onInit()
{

}

void tama::PickFood::onFrame()
{
    if (isHappyJump) { if (!happyJump.onFrame()) {
            context->switchStage(std::make_shared<Eat>(context));
    } return; }
    if (state == tama::eat::SELECT)
    {

    }
    if (state == tama::eat::EAT)
    {
        animationState++;
        onAnimationState();
        if (animationState > goingDownAnimationLength + eatingAnimationLength)
        {
            //say hurray
            if (context->getGameState().getPetData().getFood() == 0)
            {
                happyJump.init();
                isHappyJump = true;
            }
            else
            {
                context->switchStage(std::make_shared<Eat>(context));
            }
            context->getGameState().getPetData().increaseFood(1);
        }
    }
}

tama::PickFood::PickFood(const std::shared_ptr<Context> &context, MealType mealType) : Stage(context)
{
    selectedFoodId = 0;
    this->mealType = mealType;
    if (mealType == MEAL)
    {
        loadMeals();
    }
    else
    {
        loadSnacks();
    }
    cursor.setPosition(tama::util::toContentArea(Vec2d(26, 14)));
    cursor.setTexture(context->getTextureLoader()->load(tama::asset::menuCursor));
    scene->addDrawable(std::shared_ptr<Sprite>(&cursor));

    selectedFood.setPosition(tama::util::toContentArea(Vec2d(8, 10)));
    selectedFood.setTexture(context->getTextureLoader()->load(*food.at(selectedFoodId)));
    scene->addDrawable(std::shared_ptr<Sprite>(&selectedFood));

    pet.setPosition(tama::util::fromBottomRight(Vec2d(-20, -20)));
    pet.setTexture(context->getPetTexture(sideStandard));
    scene->addDrawable(std::shared_ptr<Sprite>(&pet));
}

void tama::PickFood::onAnimationState()
{
    if (animationState <= goingDownAnimationLength)
    {
        selectedFood.move(Vec2d(0, 4));
    }
    else if (animationState <= goingDownAnimationLength + eatingAnimationLength)
    {
        pet.setTexture(context->getPetTexture(animationState % 2 ? sideEat : sideStandard));
        if (animationState == goingDownAnimationLength + 1)
        {
            selectedFood.setTexture(context->getTextureLoader()->load(tama::asset::eat::rice1));
        }
        if (animationState == goingDownAnimationLength + 4)
        {
            selectedFood.setTexture(context->getTextureLoader()->load(tama::asset::eat::rice2));
        }
        if (animationState == goingDownAnimationLength + 7)
        {
            selectedFood.setTexture(context->getTextureLoader()->load(tama::asset::eat::rice3));
        }
    }
}

void tama::PickFood::loadMeals()
{
    food.emplace_back(&tama::asset::eat::rice0);
}

void tama::PickFood::loadSnacks()
{

}

tama::TextureAsset *tama::PickFood::getFoodAssetByName(std::string name)
{

}

