//
// Created by grzegorz on 4/29/21.
//

#ifndef VPET_CONTEXT_H
#define VPET_CONTEXT_H


#include <stack>
#include <memory>
#include "../stage/Stage.h"
#include "../../ui/display/drawable/texture-loader/TextureLoader.h"
#include "../../sound/sound-player/SoundPlayer.h"
#include "../../input/Input.h"
#include "../../game/model/game-state/GameState.h"
#include "../../time/time-monitor/time-monitor-creator/TimeMonitorCreator.h"

namespace tama
{
    class Stage;

    class Context
    {
    public:
        Context(std::shared_ptr<TextureLoader> textureLoader,
                std::shared_ptr<Input> input,
                std::shared_ptr<SoundPlayer> player,
                std::shared_ptr<TimeMonitorCreator> timeMonitorCreator);

        void openNewStage(std::shared_ptr<tama::Stage>);
        void goToPreviousStage();
        void switchStage(std::shared_ptr<tama::Stage>);
        std::shared_ptr<tama::Stage> getActiveStage();
        std::shared_ptr<TextureLoader> getTextureLoader();
        std::shared_ptr<Input> getInput();
        std::shared_ptr<SoundPlayer> getSoundPlayer();
        std::shared_ptr<TimeMonitorCreator> getTimeMonitorCreator();
        std::shared_ptr<Texture> getPetTexture(PetTextureVariant petTextureVariant);
        void startTimeTimer();
        GameState & getGameState();
    private:
        GameState gameState;
        std::stack<std::shared_ptr<Stage>> stages;
        std::shared_ptr<TextureLoader> textureLoader;
        std::shared_ptr<Input> input;
        std::shared_ptr<SoundPlayer> player;
        std::shared_ptr<TimeMonitorCreator> timeMonitorCreator;
    };
}



#endif //VPET_CONTEXT_H
