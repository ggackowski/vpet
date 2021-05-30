//
// Created by grzegorz on 5/4/21.
//

#include <gpio.h>
#include "Stm32Input.h"
#include "../../Core/input/button.h"

void tama::Stm32Input::update()
{
    delay++;
    delay %= 4;
    if (HAL_GPIO_ReadPin(BUTTON_C_GPIO_Port, BUTTON_C_Pin) == GPIO_PIN_RESET)
    {
        button = tama::Button::C;
    }
    if (HAL_GPIO_ReadPin(BUTTON_B_GPIO_Port, BUTTON_B_Pin) == GPIO_PIN_RESET)
    {
        button = tama::Button::B;
    }
    if (HAL_GPIO_ReadPin(BUTTON_A_GPIO_Port, BUTTON_A_Pin) == GPIO_PIN_RESET)
    {
        button = tama::Button::A;
    }
    // temp
    if (delay % 2 == 0 && button != tama::Button::NONE)
    {
        for (auto listener : listeners)
        {
            if (listener != nullptr)
            {
                listener->onInput(button);
            }
        }
        button = tama::Button::NONE;
    }
}
