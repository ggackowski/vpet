//
// Created by grzegorz on 5/8/21.
//

#include "ServicesStore.h"

tama::ServicesStore &tama::ServicesStore::get()
{
    return instance;
}
