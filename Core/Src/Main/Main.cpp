//
// Created by grzegorz on 3/25/21.
//

#include <spi.h>
#include "Main.h"
#include "../STM32F411Disco-drivers/display/Nokia5510Display.h"
#include "../Core/ui/display/Display.h"
#include "../Core/ui/display/drawable/texture.h"
#include "../Core/ui/display/drawable/sprite/Sprite.h"
#include "../Core/ui/display/scene/Scene.h"
#include "../Core/ui/display/display-data-manager/DisplayDataManager.h"
#include "../STM32F411Disco-drivers/nokia5110-display-data-manager/Nokia5110DisplayDataManager.h"

void tama::Main::run()
{
    DisplayConfig displayConfig = getDefaultNokia5110DisplayConfig();
    std::shared_ptr<Display> display = std::make_shared<Nokia5510Display>(displayConfig);

    std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(makeSampleTexture(), Vec2d(1, 1));
    std::shared_ptr<Sprite> sprite2 = std::make_shared<Sprite>(makeSampleTexture(), Vec2d(30, 35));

    std::shared_ptr<DisplayDataManager> dataManager = std::make_shared<Nokia5110DisplayDataManager>();

    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    scene->addDrawable(sprite);
    scene->addDrawable(sprite2);

    for (unsigned i = 0; i < 30; ++i)
    {
        HAL_Delay(100);
        sprite->move(Vec2d(0, 1));
        sprite2->move(Vec2d(0, -1));
        auto sceneData = dataManager->getActiveSceneDisplayData(scene->getSceneData());
        display->setData(sceneData);
    }



    while (true)
    {}

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

std::shared_ptr<tama::Texture> tama::Main::makeSampleTexture()
{
    unsigned tW = 4;
    unsigned tH = 4;
    PixelColor ** tD = new PixelColor*[tH];

    tD[0] = new PixelColor[tW];
    tD[1] = new PixelColor[tW];
    tD[2] = new PixelColor[tW];
    tD[3] = new PixelColor[tW];

    tD[0][0] = PixelColor::BLACK;
    tD[0][1] = PixelColor::WHITE;
    tD[0][2] = PixelColor::WHITE;
    tD[0][3] = PixelColor::BLACK;

    tD[1][0] = PixelColor::WHITE;
    tD[1][1] = PixelColor::WHITE;
    tD[1][2] = PixelColor::WHITE;
    tD[1][3] = PixelColor::WHITE;

    tD[2][0] = PixelColor::BLACK;
    tD[2][1] = PixelColor::WHITE;
    tD[2][2] = PixelColor::WHITE;
    tD[2][3] = PixelColor::BLACK;

    tD[3][0] = PixelColor::WHITE;
    tD[3][1] = PixelColor::BLACK;
    tD[3][2] = PixelColor::BLACK;
    tD[3][3] = PixelColor::WHITE;

    return std::make_shared<Texture>(tW, tH, tD);
}
