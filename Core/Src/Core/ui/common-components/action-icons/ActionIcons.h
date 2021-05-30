//
// Created by grzegorz on 5/28/21.
//

#ifndef VPET_ACTIONICONS_H
#define VPET_ACTIONICONS_H


#include <array>
#include "../../display/drawable/sprite/Sprite.h"
#include "../../display/scene/Scene.h"
#include "../../../runtime/context/Context.h"

namespace tama
{
    class ActionIcons
    {
    public:
        ActionIcons(std::shared_ptr<Scene> scene, const std::shared_ptr<Context> & context);
        void changeSelectedIcon();
        void removeSelection();
        int getSelectedIconIndex();
    private:
        void initMenu();
        std::shared_ptr<Scene> scene;
        std::shared_ptr<Context> context;
        std::array<Sprite, 9> bigIcons;
        Sprite okIcon;
        int selectedIconIndex = 9;
    };
}



#endif //VPET_ACTIONICONS_H
