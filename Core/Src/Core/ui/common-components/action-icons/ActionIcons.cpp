//
// Created by grzegorz on 5/28/21.
//

#include "ActionIcons.h"
#include "../../../assets/common/icon-bar-background.texture.h"
#include "../../../assets/common/icon-bar-big-icons.texture.h"


void tama::ActionIcons::initMenu()
{
    scene->addDrawable(std::make_shared<Sprite>(context->getTextureLoader()->load(tama::asset::iconBarBackgroundLeft), Vec2d(0, 0)));
    scene->addDrawable(std::make_shared<Sprite>(context->getTextureLoader()->load(tama::asset::iconBarBackgroundRight), Vec2d(84-14, 0)));

    bigIcons.at(0) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon1), Vec2d(0, 0));
    bigIcons.at(1) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon2), Vec2d(0, 8));
    bigIcons.at(2) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon3), Vec2d(0, 15));
    bigIcons.at(3) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon4), Vec2d(0, 22));
    bigIcons.at(4) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon5), Vec2d(0, 29));
    bigIcons.at(5) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon6), Vec2d(65, 0));
    bigIcons.at(6) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon7), Vec2d(65, 8));
    bigIcons.at(7) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon8), Vec2d(65, 15));
    bigIcons.at(8) = Sprite(context->getTextureLoader()->load(tama::asset::bigIcon9), Vec2d(65, 20));

    for (int i = 0; i < 9; ++i)
    {
        bigIcons.at(i).hide();
        scene->addDrawable(std::shared_ptr<Sprite>(&bigIcons.at(i)));
    }

    okIcon = Sprite(context->getTextureLoader()->load(tama::asset::okIcon), Vec2d(84 - 11, 48 - 8));
    scene->addDrawable(std::shared_ptr<Sprite>(&okIcon));
}

tama::ActionIcons::ActionIcons(std::shared_ptr<Scene> scene, const std::shared_ptr<Context> & context)
{
    this->scene = scene;
    this->context = context;
    initMenu();
}

void tama::ActionIcons::changeSelectedIcon()
{
    if (selectedIconIndex != 9)
    {
        bigIcons.at(selectedIconIndex).hide();
    }
    selectedIconIndex++;
    selectedIconIndex %= 10;
    if (selectedIconIndex != 9)
    {
        bigIcons.at(selectedIconIndex).show();
    }
}

void tama::ActionIcons::removeSelection()
{
    bigIcons.at(selectedIconIndex).hide();
    selectedIconIndex = 9;
}

int tama::ActionIcons::getSelectedIconIndex()
{
    return selectedIconIndex;
}


