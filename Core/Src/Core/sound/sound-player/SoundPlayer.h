//
// Created by grzegorz on 5/4/21.
//

#ifndef VPET_SOUNDPLAYER_H
#define VPET_SOUNDPLAYER_H

#include <memory>
#include <vector>
#include "../../time/time-monitor/TimeMonitor.h"
#include "../tone/Tone.h"
#include "../SoundPlayingStrategy.h"

namespace tama
{
    class SoundPlayer
    {
    public:
        SoundPlayer(std::shared_ptr<TimeMonitor> time);

        void play(std::vector<Tone>);
        void update();
        void setPlayingStrategy(std::shared_ptr<SoundPlayingStrategy> player);
        //__HAL_TIM_SET_PRESCALER(&htim3, k+=5);

    private:
        std::shared_ptr<TimeMonitor> time;
        std::shared_ptr<SoundPlayingStrategy> player;
        std::vector<Tone> melody;
        int currentTone;
        bool playingNow;
    };
}



#endif //VPET_SOUNDPLAYER_H
