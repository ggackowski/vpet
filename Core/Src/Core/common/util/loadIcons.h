//
// Created by grzegorz on 6/4/21.
//

#ifndef VPET_LOADICONS_H
#define VPET_LOADICONS_H

#include "../../assets/common/icon-bar-background.texture.h"

namespace tama
{
    namespace util
    {
        void loadIcons(std::shared_ptr<Scene> scene, std::shared_ptr<Context> context)
        {
            scene->addDrawable(std::make_shared<Sprite>(context->getTextureLoader()->load(tama::asset::iconBarBackgroundLeft), Vec2d(0, 0)));
            scene->addDrawable(std::make_shared<Sprite>(context->getTextureLoader()->load(tama::asset::iconBarBackgroundRight), Vec2d(84-14, 0)));
        }
    }

}





#endif //VPET_LOADICONS_H
