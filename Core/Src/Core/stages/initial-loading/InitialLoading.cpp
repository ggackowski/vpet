//
// Created by grzegorz on 4/29/21.
//

#include "InitialLoading.h"


void tama::InitialLoading::onInput(tama::Button button)
{
    std::vector<Tone> music;
    music.push_back({5, 14});
    context->getSoundPlayer()->play(music);
    if (button == Button::C)
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
    if (button == tama::Button::B)
    {
        context->switchStage(std::make_shared<NameSelection>(context));
    }
}

void tama::InitialLoading::onInit()
{

}

void tama::InitialLoading::onFrame()
{

}

tama::InitialLoading::InitialLoading(const std::shared_ptr<Context> &context) : Stage(context)
{
    scene->addDrawable(std::make_shared<Sprite>(
            context->getTextureLoader()->load(tama::asset::egg1),
            Vec2d(34, 37)));
    text = Text(Vec2d(15, 5));
    text.setText(std::string("ABC"));
    scene->addDrawable(std::shared_ptr<Text>(&text));
    initMenu();
}

void tama::InitialLoading::initMenu()
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
