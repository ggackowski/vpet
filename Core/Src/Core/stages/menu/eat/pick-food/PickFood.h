//
// Created by grzegorz on 6/2/21.
//

#ifndef VPET_PICKFOOD_H
#define VPET_PICKFOOD_H

#include "../../../../runtime/stage/Stage.h"
#include "../meal-type.h"
#include "eat-food-state.h"
#include "../../../../ui/display/drawable/sprite/Sprite.h"
#include "../../../../common/util/displayPlacementUtils.h"
#include "../../../../ui/common-components/happy-jump/HappyJump.h"


namespace tama
{
    class PickFood : public Stage
    {
    public:
        PickFood(const std::shared_ptr<Context> &context, MealType mealType);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        MealType mealType;
        int selectedFoodId;
        int animationState = 0;
        eat::State state = eat::SELECT;
        std::vector<TextureAsset *> food;
        int isHappyJump = false;

        const int goingDownAnimationLength = 6;
        const int eatingAnimationLength = 7;

        Sprite selectedFood;
        Sprite pet;
        Sprite cursor;
        HappyJump happyJump = HappyJump(*scene, *context);

        void onAnimationState();
        void loadMeals();
        void loadSnacks();
        TextureAsset * getFoodAssetByName(std::string name);
    };
}



#endif //VPET_PICKFOOD_H
