//
// Created by grzegorz on 5/30/21.
//

#ifndef VPET_PLAYMENU_H
#define VPET_PLAYMENU_H

#include "../../../../runtime/stage/Stage.h"
#include "../../../../ui/common-components/menu/Menu.h"
#include "../../../main/Home.h"

namespace tama
{
    class PlayMenu : public Stage
    {
    public:
        PlayMenu(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;
    private:
        Menu menu;
    };
}



#endif //VPET_PLAYMENU_H
