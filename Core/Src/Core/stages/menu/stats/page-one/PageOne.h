//
// Created by grzegorz on 6/3/21.
//

#ifndef VPET_PAGEONE_H
#define VPET_PAGEONE_H

#include "../../../../runtime/stage/Stage.h"
#include "../../../../ui/display/drawable/text/Text.h"
#include "../../wash/Wash.h"

namespace tama
{
    class PageOne : public Stage
    {
    public:
        PageOne(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        Text nameText = Text("NAME:", util::toContentArea(Vec2d(1, 1)));
        Text actualPetName = Text(context->getGameState().getPetData().getName(), util::toContentArea(Vec2d(1, 10)));
        Text ageText = Text("AGE:", util::toContentArea(Vec2d(1, 24)));
        Text actualPetAge = Text(std::to_string(context->getGameState().getPetData().getAge()), util::toContentArea(Vec2d(40, 24)));
    };
}



#endif //VPET_PAGEONE_H
