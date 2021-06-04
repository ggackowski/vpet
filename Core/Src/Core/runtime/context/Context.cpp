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
    if (!stages.empty())
    {
        input->removeListener(stages.top().get());
        // stages.pop();
    }
    stages.push(stage);
}

std::shared_ptr<tama::Stage> tama::Context::getActiveStage()
{
    return stages.top(); // @todo return null object if no stage created
}

tama::Context::Context(std::shared_ptr<TextureLoader> textureLoader,
                       std::shared_ptr<Input> input,
                       std::shared_ptr<SoundPlayer> player,
                       std::shared_ptr<TimeMonitorCreator> timeMonitorCreator)
: textureLoader(textureLoader), input(input), player(player), timeMonitorCreator(timeMonitorCreator)
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

std::shared_ptr<tama::SoundPlayer> tama::Context::getSoundPlayer()
{
    return player;
}

tama::GameState &tama::Context::getGameState()
{
    return gameState;
}

std::shared_ptr<tama::TimeMonitorCreator> tama::Context::getTimeMonitorCreator()
{
    return timeMonitorCreator;
}

std::shared_ptr<tama::Texture> tama::Context::getPetTexture(tama::PetTextureVariant petTextureVariant)
{
    return textureLoader->load(gameState.getPetTextureAsset(petTextureVariant));
}

void tama::Context::startTimeTimer()
{
    auto timeTimer = getTimeMonitorCreator()->createTimeMonitor();
    gameState.setTimeTimer(timeTimer);
}
