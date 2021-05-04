//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_MAIN_H
#define VPET_MAIN_H

#include <memory>
#include <spi.h>

#include "../Inc/tim.h"

#include "../STM32F411Disco-drivers/display/DisplayConfig.h"
#include "../STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.h"
#include "../STM32F411Disco-drivers/display/Nokia5510Display.h"
#include "../Core/ui/display/Display.h"
#include "../Core/ui/display/drawable/texture.h"
#include "../Core/ui/display/drawable/sprite/Sprite.h"
#include "../Core/ui/display/scene/Scene.h"
#include "../Core/ui/display/display-data-manager/DisplayDataManager.h"
#include "../STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.h"
#include "../Core/ui/display/drawable/texture-loader/TextureLoader.h"
#include "../STM32F411Disco-drivers/texture-loader/Stm32TextureLoader.h"
#include "../Core/ui/display/drawable/text/Text.h"
#include "../Core/runtime/context/Context.h"
#include "../Core/stages/initial-loading/InitialLoading.h"
#include "../Core/time/time-monitor/TimeMonitor.h"
#include "../STM32F411Disco-drivers/time-monitor/Stm32TimeMonitor.h"
#include "../Core/sound/SoundPlayingStrategy.h"
#include "../STM32F411Disco-drivers/sound-playing-strategy/Stm32SoundPlayingStrategy.h"
#include "../Core/sound/sound-player/SoundPlayer.h"


namespace tama
{
    class Main
    {
    public:
        [[noreturn]] void run();


    private:
        DisplayConfig getDefaultNokia5110DisplayConfig();
        std::shared_ptr<Texture> makeSampleTexture();
    };
}



#endif //VPET_MAIN_H
