//
// Created by grzegorz on 3/28/21.
//

#include <algorithm>
#include "Scene.h"

tama::Scene::Scene()
{
    observer = nullptr;
}

void tama::Scene::setChangeObserver(std::shared_ptr<ChangeObserver> observer)
{
    this->observer = observer;
}

void tama::Scene::addDrawable(std::shared_ptr<Drawable> drawable)
{
    this->drawables.push_back(drawable);
    //drawable->setChangeObserver(std::shared_ptr<Scene>(&(*this)));
}

void tama::Scene::removeDrawable(std::shared_ptr<Drawable> drawable)
{
    auto position = std::find(drawables.begin(), drawables.end(), drawable);
    if (position != drawables.end())
    {
        drawables.erase(position);
    }
}

std::shared_ptr<tama::Texture> tama::Scene::getSceneData()
{
    std::shared_ptr<tama::Texture> texture = std::make_shared<tama::Texture>(width, height);
    for (auto drawable : drawables)
    {
        if (drawable && drawable->isVisible())
        {
            texture->insertAt(drawable->getPosition(), drawable->getTexture());
        }
    }
    return texture;
}

void tama::Scene::onChange()
{

}

void tama::Scene::hideAll()
{
    for (int i = 0; i < drawables.size(); ++i)
    {
        drawables[i]->hide();
    }
}


