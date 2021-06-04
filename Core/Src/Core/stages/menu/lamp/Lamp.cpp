//
// Created by grzegorz on 6/4/21.
//

#include "Lamp.h"
#include "../../main/Home.h"

tama::Lamp::Lamp(const std::shared_ptr<Context> &context) : Stage(context), menu(Menu(scene, context))
{
    std::vector<std::string> options;
    options.emplace_back("ON");
    options.emplace_back("OFF");
    menu.setOptions(options);
}

void tama::Lamp::onInput(tama::Button button)
{
    if (button == Button::A)
    {
        menu.moveToNextItem();
    }
    if (button == Button::B)
    {
        int selectedItem = menu.getSelectedItem();
        if (selectedItem == 1)
        {
            //light off
            context->getGameState().setLightsOn(false);
        }
        else
        {
            context->getGameState().setLightsOn(true);
        }
        context->switchStage(std::make_shared<Home>(context));
    }
    if (button == Button::C)
    {
        context->switchStage(std::make_shared<Home>(context));
    }
}

void tama::Lamp::onInit()
{

}

void tama::Lamp::onFrame()
{

}
