//
// Created by grzegorz on 6/3/21.
//

#ifndef VPET_HAPPYJUMP_H
#define VPET_HAPPYJUMP_H

#include "../../display/drawable/sprite/Sprite.h"
#include "../../display/scene/Scene.h"
#include "../../../runtime/context/Context.h"
#include "../../../assets/pet/misc/misc.texture.h"
#include "../../../common/util/displayPlacementUtils.h"

namespace tama
{
    class HappyJump
    {
    public:
        HappyJump(Scene &scene, Context& context);
        int onFrame();
        void init();

    private:
        Scene & scene;
        Context & context;
        Sprite pet = Sprite(context.getPetTexture(frontStandard), tama::Vec2d(7, -20));
        std::shared_ptr<TimeMonitor> oneFrameTimeMonitor = context.getTimeMonitorCreator()->createTimeMonitor();
        const int oneFrameTime = 1000;
        const int animationMaxLength = 6;
        int animationFrame = 0;
        Sprite sun = Sprite(context.getTextureLoader()->load(asset::misc::sun0), tama::util::fromBottomLeft(Vec2d(28, -32)));
    };
}



#endif //VPET_HAPPYJUMP_H
