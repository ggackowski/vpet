//
// Created by grzegorz on 3/28/21.
//

#ifndef VPET_CHANGEOBSERVER_H
#define VPET_CHANGEOBSERVER_H

namespace tama
{
    class ChangeObserver
    {
    public:
        virtual void onChange() = 0;
    };
}

#endif //VPET_CHANGEOBSERVER_H
