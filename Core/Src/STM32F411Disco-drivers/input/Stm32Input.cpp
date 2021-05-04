//
// Created by grzegorz on 5/4/21.
//

#include <gpio.h>
#include "Stm32Input.h"
#include "../../Core/input/button.h"

void tama::Stm32Input::update()
{
    Button button = tama::Button::NONE;

    if (HAL_GPIO_ReadPin(BUTTON_C_GPIO_Port, BUTTON_C_Pin) == GPIO_PIN_RESET)
    {
        button = tama::Button::C;
    }
    if (HAL_GPIO_ReadPin(BUTTON_B_GPIO_Port, BUTTON_B_Pin) == GPIO_PIN_RESET)
    {
        button = tama::Button::B;
    }

    if (button != tama::Button::NONE)
    {
        for (auto listener : listeners)
        {
            listener->onInput(button);
        }
    }
}
