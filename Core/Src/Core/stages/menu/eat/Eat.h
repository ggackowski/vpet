//
// Created by grzegorz on 5/29/21.
//

#ifndef VPET_EAT_H
#define VPET_EAT_H

#include "../../../runtime/stage/Stage.h"
#include "../../../ui/common-components/menu/Menu.h"

namespace tama
{
    class Eat : public Stage
    {
    public:
        Eat(const std::shared_ptr<Context> &context);
        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;
    private:
        Menu menu;
    };
}



#endif //VPET_EAT_H
