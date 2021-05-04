//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_INPUT_H
#define VPET_INPUT_H

#include <memory>
#include <vector>
#include "../common/observers/OnInput.h"

namespace tama
{
    class Input
    {
    public:
        virtual void update() = 0;
        void addListener(std::shared_ptr<OnInput>);

    protected:
        std::vector<std::shared_ptr<OnInput>> listeners;
    };
}



#endif //VPET_INPUT_H
