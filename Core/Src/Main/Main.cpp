//
// Created by grzegorz on 3/25/21.
//


#include "Main.h"
// #include "../Core/stages/initial/time-selection/TimeSelection.h"
#include "../Core/stages/main/Home.h"
// #include "../Core/stages/initial/time-selection/TimeSelection.h"
#include "../Core/stages/menu/wash/Wash.h"
#include "../Core/ui/common-components/menu/Menu.h"
#include "../Core/stages/menu/eat/Eat.h"
#include "../Core/stages/initial/time-selection/TimeSelection.h"
#include "../STM32F411Disco-drivers/time-monitor/Stm32TimeMonitorCreator.h"
#include "../Core/stages/menu/play/menu/PlayMenu.h"


[[noreturn]] void tama::Main::run()
{
    unsigned fps = 4;
    unsigned frameMillis = 1000 / fps;

    DisplayConfig displayConfig = getDefaultNokia5110DisplayConfig();
    std::unique_ptr<Display> display = std::make_unique<Nokia5510Display>(displayConfig);
    std::shared_ptr<TextureLoader> textureLoader = std::make_shared<Stm32TextureLoader>();
    std::shared_ptr<DisplayDataManager> dataConverter = std::make_shared<Nokia5110DisplayDataManager>();
    std::shared_ptr<TimeMonitorCreator> timeMonitorCreator = std::make_shared<Stm32TimeMonitorCreator>();
    std::shared_ptr<TimeMonitor> soundTimeMonitor = timeMonitorCreator->createTimeMonitor();
    std::shared_ptr<TimeMonitor> refreshTimeMonitor = timeMonitorCreator->createTimeMonitor();
    std::shared_ptr<SoundPlayingStrategy> playingStrategy = std::make_shared<Stm32SoundPlayingStrategy>();
    SoundPlayer soundPlayer(soundTimeMonitor);
    std::shared_ptr<Input> input = std::make_shared<Stm32Input>();
    soundPlayer.setPlayingStrategy(playingStrategy);
    std::shared_ptr<Context> context = std::make_shared<Context>(textureLoader,
                                                                 input,
                                                                 std::shared_ptr<SoundPlayer>(&soundPlayer),
                                                                 timeMonitorCreator);
    //std::shared_ptr<Stage> loadingStage = std::make_shared<InitialLoading>(context);

    context->openNewStage(std::make_shared<PlayMenu>(context));
    context->getActiveStage()->onInit();
    refreshTimeMonitor->startTimer();

    //    soundPlayer.play(music);

    while (true)
    {
        input->update();
        soundPlayer.update();
        if (refreshTimeMonitor->getElapsedTime() > frameMillis)
        {
            refreshTimeMonitor->startTimer();
            auto sceneData = dataConverter->getActiveSceneDisplayData(context->getActiveStage()->getScene()->getSceneData());
            display->setData(sceneData);
            context->getActiveStage()->onFrame();
        }
    }
}

tama::DisplayConfig tama::Main::getDefaultNokia5110DisplayConfig()
{
    DisplayConfig cfg;
    cfg.spi = &hspi1;
    cfg.reset_port = RST_GPIO_Port;
    cfg.reset_pin = RST_Pin;
    cfg.bl_port = BL_GPIO_Port;
    cfg.bl_pin = BL_Pin;
    cfg.dc_port = DC_GPIO_Port;
    cfg.dc_pin = DC_Pin;
    cfg.ce_port = CE_GPIO_Port;
    cfg.ce_pin = CE_Pin;
    return cfg;
}

//std::vector<Tone> music;
//    music.push_back({400, 10});
//    music.push_back({400, 5});
//    music.push_back({400, 10});
//    music.push_back({400, 5});
//    music.push_back({300, 10});
//    music.push_back({200, 14});
//    music.push_back({200, 10});
//    music.push_back({200, 7});
//    music.push_back({200, 5});
//    music.push_back({400, 7});
//    music.push_back({200, 0});
//    music.push_back({400, 10});
//    music.push_back({400, 5});
//    music.push_back({400, 10});
//    music.push_back({400, 5});
//    music.push_back({300, 10});
//    music.push_back({200, 14});
//    music.push_back({200, 10});
//    music.push_back({200, 7});
//    music.push_back({200, 5});
//    music.push_back({400, 7});


// for next time

/*
 *
 * //    context->getActiveStage()->onFrame();

//    auto textureData1 = textureLoader->load(tama::asset::egg1); //PWM  (Głosniczek do timera) przycisk moze byc w pętli freertos + LCD
//    auto textureData2 = textureLoader->load(tama::asset::egg2); //
//
//    std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(textureData1, Vec2d(1, 37));
//    std::shared_ptr<Sprite> sprite2 = std::make_shared<Sprite>(textureData2, Vec2d(64, 37));
//    std::shared_ptr<Text> text = std::make_shared<Text>(Vec2d(1, 2));
//    std::string textStr("A");
//    text->setText(textStr);
//
//    scene->addDrawable(sprite);
//    scene->addDrawable(sprite2);
//    scene->addDrawable(text);

//    auto sceneData = dataConverter->getActiveSceneDisplayData(scene->getSceneData());


 //        if (HAL_GPIO_ReadPin(BUTTON_C_GPIO_Port, BUTTON_C_Pin) == GPIO_PIN_RESET){
////            textStr = std::string(1, (char)(textStr.c_str()[0] + 1));
//
//            text->setText(textStr);
//        }
//        if (HAL_GPIO_ReadPin(BUTTON_B_GPIO_Port, BUTTON_B_Pin) == GPIO_PIN_RESET){
////        	textStr = std::string(1, (char)(textStr.c_str()[0] - 1));
//        	__HAL_TIM_SET_PRESCALER(&htim3, k-=5);
//            text->setText(textStr);
//        }


 //    soundPlayer->play(music);
 //        sprite->setTexture(i % 2 ? textureData2 : textureData1);
//
//        text->move(Vec2d(0, i % 4 > 1 ? 1 : -1));
 *
 */
