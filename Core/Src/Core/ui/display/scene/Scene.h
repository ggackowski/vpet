//
// Created by grzegorz on 3/28/21.
//

#ifndef VPET_SCENE_H
#define VPET_SCENE_H

#include <memory>
#include <vector>
#include "../../../common/observers/ChangeObserver.h"
#include "../drawable/Drawable.h"
#include "../../../../Configuration/display.config.h"

namespace tama
{
    class Scene : public ChangeObserver
    {
    public:
        void setChangeObserver(std::shared_ptr<ChangeObserver>);

        void addDrawable(std::shared_ptr<Drawable>);

        Scene();

        void removeDrawable(std::shared_ptr<Drawable>);

        std::shared_ptr<Texture> getSceneData();

        void onChange() override;

    private:
        std::shared_ptr<ChangeObserver> observer;
        std::vector<std::shared_ptr<Drawable>> drawables;
        unsigned width = Config_Display_Width;
        unsigned height = Config_Display_Height;
    };
}



#endif //VPET_SCENE_H
