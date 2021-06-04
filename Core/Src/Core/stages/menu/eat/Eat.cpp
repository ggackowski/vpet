//
// Created by grzegorz on 5/29/21.
//

#include "Eat.h"
#include "../../main/Home.h"
#include "pick-food/PickFood.h"

void tama::Eat::onInput(tama::Button button)
{
    if (button == Button::A)
    {
        menu.moveToNextItem();
    }
    if (button == Button::B)
    {
        int selectedItem = menu.getSelectedItem();
        if (selectedItem == 0)
        {
            //meal
        	context->switchStage(std::make_shared<PickFood>(context, MEAL));
        }
        else
        {
            //snack
        }
    }
    if (button == Button::C)
    {
        context->switchStage(std::make_shared<Home>(context));
    }
}

void tama::Eat::onInit()
{

}

void tama::Eat::onFrame()
{

}

tama::Eat::Eat(const std::shared_ptr<Context> &context) : Stage(context), menu(Menu(scene, context))
{
    std::vector<std::string> options;
    options.emplace_back("MEAL");
    options.emplace_back("SNACK");
    menu.setOptions(options);
}
