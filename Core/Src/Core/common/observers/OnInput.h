//
// Created by grzegorz on 4/29/21.
//

#ifndef VPET_ONINPUT_H
#define VPET_ONINPUT_H

#include "../../input/button.h"

namespace tama
{
    class OnInput
    {
    public:
        virtual void onInput(Button) = 0;
    };
}


#endif //VPET_ONINPUT_H

