//
// Created by grzegorz on 5/4/21.
//

#include "Stage.h"

std::shared_ptr<tama::Scene> tama::Stage::getScene()
{
    return scene;
}

tama::Stage::Stage(const std::shared_ptr<Context> &context) : context(context)
{
    scene = std::make_shared<Scene>();
}
