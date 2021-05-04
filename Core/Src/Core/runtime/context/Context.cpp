//
// Created by grzegorz on 4/29/21.
//

#include "Context.h"


#include <utility>

void tama::Context::openNewStage(std::shared_ptr<Stage> stage)
{
    stages.push(stage);
}

void tama::Context::goToPreviousStage()
{
    stages.pop();
}

void tama::Context::switchStage(std::shared_ptr<Stage> stage)
{
    if (stages.size() > 0)
    {
        stages.pop();
    }
    stages.push(stage);
}

std::shared_ptr<tama::Stage> tama::Context::getActiveStage()
{
    return stages.top(); // @todo return null object if no stage created
}

tama::Context::Context(std::shared_ptr<TextureLoader> textureLoader, std::shared_ptr<Input> input)
: textureLoader(textureLoader), input(input)
{
}

std::shared_ptr<tama::TextureLoader> tama::Context::getTextureLoader()
{
    return textureLoader;
}

std::shared_ptr<tama::Input> tama::Context::getInput()
{
    return input;
}
