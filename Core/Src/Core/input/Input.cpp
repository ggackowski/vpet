//
// Created by grzegorz on 5/4/21.
//

#include "Input.h"

void tama::Input::addListener(tama::OnInput * listener)
{
    listeners.push_back(listener);
}

void tama::Input::removeListener(tama::OnInput * listener)
{
    for (unsigned i = 0; i < listeners.size(); ++i)
    {
        if (listener == listeners[i])
        {
            listeners.erase(listeners.begin() + i);
        }
    }
}
