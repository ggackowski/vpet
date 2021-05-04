//
// Created by grzegorz on 5/4/21.
//

#include "SoundPlayer.h"

#include <utility>

void tama::SoundPlayer::play(std::vector<tama::Tone> tones)
{
    currentTone = 0;
    playingNow = true;
    melody = std::move(tones);
    time->startTimer();
}

void tama::SoundPlayer::update()
{
    if (!playingNow)
    {
        return;
    }
    if (time->getElapsedTime() > melody[currentTone].duration)
    {
    	int w = melody.size();
        if (melody.size() == currentTone + 1)
        {
            playingNow = false;
            player->stop();
            return;
        } else {
            currentTone++;
            time->startTimer();
        }
    }
    player->play(melody[currentTone]);
}

void tama::SoundPlayer::setPlayingStrategy(std::shared_ptr<SoundPlayingStrategy> player)
{
    this->player = player;
}

tama::SoundPlayer::SoundPlayer(std::shared_ptr<TimeMonitor> time) : time(std::move(time))
{
    this->playingNow = false;
    this->currentTone = 0;
}
