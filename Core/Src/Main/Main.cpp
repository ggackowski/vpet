//
// Created by grzegorz on 3/25/21.
//

#include <spi.h>
#include "Main.h"
#include "../STM32F411Disco-drivers/display/Nokia5510Display.h"
#include "../Core/ui/display/Display.h"

void tama::Main::run()
{
    DisplayConfig displayConfig = getDefaultNokia5110DisplayConfig();
    std::shared_ptr<Display> display = std::make_shared<Nokia5510Display>(displayConfig);
    PixelColor data[48 * 84] = {PixelColor::WHITE};
    data[4] = PixelColor::BLACK;
    display->setData(data);
    display->displayData();
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
