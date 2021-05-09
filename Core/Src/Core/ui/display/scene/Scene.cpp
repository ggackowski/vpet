//
// Created by grzegorz on 3/28/21.
//

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
    //drawable->setChangeObserver(std::make_shared<Scene>(*this));
}

void tama::Scene::removeDrawable(std::shared_ptr<Drawable>)
{

}

std::shared_ptr<tama::Texture> tama::Scene::getSceneData()
{
    std::shared_ptr<tama::Texture> texture = std::make_shared<tama::Texture>(width, height);

    for (auto drawable : drawables)
    {
        if (drawable->isVisible())
        {
            texture->insertAt(drawable->getPosition(), drawable->getTexture());
        }
    }
    return texture;
}

void tama::Scene::onChange()
{

}


