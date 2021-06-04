//
// Created by grzegorz on 6/4/21.
//

#ifndef VPET_LAMP_H
#define VPET_LAMP_H

#include "../../../runtime/stage/Stage.h"
#include "../../../ui/common-components/menu/Menu.h"

namespace tama
{
    class Lamp : public Stage
    {
    public:
        Lamp(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;

    private:
        Menu menu;

    };
}



#endif //VPET_LAMP_H
