//
// Created by grzegorz on 5/30/21.
//

#include "PlayMenu.h"
#include "../jumping-game/JumpingGame.h"

void tama::PlayMenu::onInput(tama::Button button)
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
            context->switchStage(std::make_shared<JumpingGame>(context));
        }
    }
    if (button == Button::C)
    {
        context->switchStage(std::make_shared<Home>(context));
    }
}

void tama::PlayMenu::onInit()
{

}

void tama::PlayMenu::onFrame()
{

}

tama::PlayMenu::PlayMenu(const std::shared_ptr<Context> &context) : Stage(context), menu(Menu(scene, context))
{
    std::vector<std::string> options;
    options.emplace_back("JUMP");
    options.emplace_back("SHOP");
    menu.setOptions(options);
}
