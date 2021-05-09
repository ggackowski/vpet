//
// Created by grzegorz on 5/8/21.
//

#ifndef VPET_SERVICESSTORE_H
#define VPET_SERVICESSTORE_H

#include <memory>
#include "../../ui/display/Display.h"
#include "../../ui/display/drawable/texture-loader/TextureLoader.h"
#include "../../ui/display/display-data-manager/DisplayDataManager.h"
#include "../../sound/sound-player/SoundPlayer.h"
#include "../../input/Input.h"

namespace tama
{
    class ServicesStore
    {
    public:
        static ServicesStore & get();
    private:
        static ServicesStore instance;
        std::shared_ptr<Display> display;
        std::shared_ptr<TextureLoader> textureLoader;
        std::shared_ptr<DisplayDataManager> displayDataManager;
        std::shared_ptr<SoundPlayer> soundPlayer;
        std::shared_ptr<Input> input;
    };
}



#endif //VPET_SERVICESSTORE_H
