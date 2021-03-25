//
// Created by grzegorz on 3/25/21.
//
#ifndef VPET_DISPLAY_CONFIG
#define VPET_DISPLAY_CONFIG

#include <stm32f4xx_hal.h>

namespace tama
{
    struct DisplayConfig
    {
        SPI_HandleTypeDef * spi;
        GPIO_TypeDef * reset_port;  uint16_t reset_pin;
        GPIO_TypeDef * bl_port;     uint16_t bl_pin;
        GPIO_TypeDef * dc_port;     uint16_t ce_pin;
        GPIO_TypeDef * ce_port;     uint16_t dc_pin;
    };
}

#endif