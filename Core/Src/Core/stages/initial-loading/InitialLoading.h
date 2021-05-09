//
// Created by grzegorz on 4/29/21.
//

#ifndef VPET_INITIALLOADING_H
#define VPET_INITIALLOADING_H

#include "../../runtime/stage/Stage.h"
#include "../../ui/display/drawable/sprite/Sprite.h"
#include "../../ui/display/drawable/text/Text.h"

namespace tama
{
    class InitialLoading : public Stage
    {
    public:

        InitialLoading(const std::shared_ptr<Context> &context);

        void onInput(Button) override;

        void onInit() override;

        void onFrame() override;

    private:
//        std::shared_ptr<Sprite> egg;
//        std::shared_ptr<Sprite> bigFirstIcon;
        void initMenu();

        std::array<Sprite, 9> bigIcons;
        Sprite okIcon;
        Text text;
        int selectedIconIndex = 9;

    };
}



#endif //VPET_INITIALLOADING_H
