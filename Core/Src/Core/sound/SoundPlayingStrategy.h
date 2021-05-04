//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_SOUNDPLAYINGSTRATEGY_H
#define VPET_SOUNDPLAYINGSTRATEGY_H

#include "tone/Tone.h"

namespace tama
{
    class SoundPlayingStrategy
    {
    public:
        virtual void play(Tone) = 0;
        virtual void stop() = 0;
    };
}


#endif //VPET_SOUNDPLAYINGSTRATEGY_H
