//
// Created by grzegorz on 5/26/21.
//

#include "Menu.h"



void tama::Menu::setOptions(std::vector<std::string> options)
{
    this->options = options;
    initMenu();
}

tama::Menu::Menu(std::shared_ptr<Scene> scene, const std::shared_ptr<Context> &context)
{
    this->scene = scene;
    this->context = context;
}

void tama::Menu::initMenu()
{
    for (int i = 0; i < options.size(); ++i)
    {
        auto text = std::make_shared<Text>(options[i], Vec2d(10, i * 8));
        //optionTexts.emplace_back(text);
        scene->addDrawable(text);
    }
    cursor.setPosition(Vec2d(0, 0));
    cursor.setTexture(context->getTextureLoader()->load(tama::asset::menuCursor));
    scene->addDrawable(std::shared_ptr<Sprite>(&cursor));
}

int tama::Menu::getSelectedItem()
{
    return selectedItem;
}

void tama::Menu::moveToNextItem()
{
    selectedItem++;
    cursor.move(Vec2d(0, 8));
    if (selectedItem == options.size())
    {
        cursor.setPosition(Vec2d(0, 0));
        selectedItem = 0;
    }
}
