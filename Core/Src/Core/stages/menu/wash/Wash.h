//
// Created by grzegorz on 5/29/21.
//

#ifndef VPET_WASH_H
#define VPET_WASH_H

#include "../../../runtime/stage/Stage.h"
#include "../../../ui/display/drawable/sprite/Sprite.h"
#include "../../../assets/menu/wash/wash.texture.h"
#include "../../../common/util/displayPlacementUtils.h"
#include "../../initial-loading/InitialLoading.h"

namespace tama
{
    class Wash : public Stage
    {
    public:
        Wash(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        static const int washElementsCount = 6;
        const int animationLength = 6;
        int animationStep = 1;
        Sprite washElements[washElementsCount];
    };
}



#endif //VPET_WASH_H
