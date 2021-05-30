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
        void addListener(OnInput *);
        void removeListener(OnInput *);

    protected:
        std::vector<OnInput *> listeners;
    };
}



#endif //VPET_INPUT_H
