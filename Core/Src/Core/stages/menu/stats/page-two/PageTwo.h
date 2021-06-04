//
// Created by grzegorz on 6/3/21.
//

#ifndef VPET_PAGETWO_H
#define VPET_PAGETWO_H

#include "../../../../runtime/stage/Stage.h"
#include "../../../../ui/display/drawable/text/Text.h"
#include "../../../../common/util/displayPlacementUtils.h"

namespace tama
{
    class PageTwo : public Stage
    {
    public:
    private:
        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    public:
        PageTwo(const std::shared_ptr<Context> &context);

    private:
        Text hungryText = Text("HUNGRY", util::toContentArea(Vec2d(1, 1)));
        Text actualPetHungry = Text("_____", util::toContentArea(Vec2d(1, 10)));
        Text happyText = Text("HAPPY", util::toContentArea(Vec2d(1, 22)));
        Text actualPetHappy = Text("_____", util::toContentArea(Vec2d(1, 31)));

        static std::string getIndicationStr(int data) ;
    };
}



#endif //VPET_PAGETWO_H
