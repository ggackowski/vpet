    //
// Created by grzegorz on 4/29/21.
//

#ifndef VPET_STAGE_H
#define VPET_STAGE_H

#include <memory>
#include "../../common/observers/OnInput.h"
#include "../../ui/display/scene/Scene.h"
#include "../context/Context.h"


namespace tama
{
    class Context;

class Stage : public OnInput
    {
    public:
        Stage(const std::shared_ptr<Context> &context);

        virtual void onInput(Button) = 0;
        virtual void onInit() = 0;
        virtual void onFrame() = 0;
        std::shared_ptr<Scene> getScene();
    protected:
        std::shared_ptr<Scene> scene;
        std::shared_ptr<Context> context;
    };
}



#endif //VPET_STAGE_H

