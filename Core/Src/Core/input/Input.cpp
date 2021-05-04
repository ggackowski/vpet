//
// Created by grzegorz on 5/4/21.
//

#include "Input.h"

void tama::Input::addListener(std::shared_ptr<tama::OnInput> listener)
{
    listeners.push_back(listener);
}
