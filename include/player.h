#pragma once
#include "track.h"
#include <map>
#ifndef SKILLBOX_HW_26_1_PLAYER_H
#define SKILLBOX_HW_26_1_PLAYER_H

class Player
{
private:
    bool is_play;
    std::string playingTrack;
    std::map <std::string, Track> trackList;
public:
    Player();
    void track_add ();
    void play (std::string trackTitle);
    void pause ();
    void next ();
    void stop ();
};

#endif //SKILLBOX_HW_26_1_PLAYER_H
