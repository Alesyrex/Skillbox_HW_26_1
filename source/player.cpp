#include <iostream>
#include "player.h"
#include <string>

Player::Player()
{
    is_play = false;
}

void Player::track_add()
{
    Track addedTrack;
    std::string title = addedTrack.getTrackTitle();

    if (trackList.find (title) == trackList.end())
    {
        trackList.insert(std::pair<std::string, Track> (title,addedTrack));
        std::cout << "Track " << title << " added!" << std::endl;
    } else std::cout << "The track is already on the list." << std::endl;
}

void Player::play(std::string trackTitle)
{

    if (!is_play)
    {
        std::map <std::string, Track>::iterator itf = trackList.find(trackTitle);
        if (itf != trackList.end())
        {
            is_play = true;
            std::cout << "The track '" << itf->second.getTrackTitle() << "' is playing." << std::endl;
            std::cout << "Info:" << std::endl;
            std::cout << "\t Created date: " << itf->second.getDate().tm_year+1900 << "/";
            std::cout <<  itf->second.getDate().tm_mon+1 << "/" << itf->second.getDate().tm_mday << std::endl;
            std::cout << "\t Duration: " << itf->second.getDuration() << std::endl;

            playingTrack = trackTitle;
        }
    }
}

void Player::pause()
{
    if (is_play)
    {
        std::cout << "The track '" << playingTrack << " 'is paused.";
        is_play = false;
    }
}

void Player::next()
{
    is_play = true;
    std::srand(std::time(nullptr));
    std::map <std::string, Track>::iterator itf = trackList.begin();
    std::advance(itf,(std::rand()%(trackList.size())));

    std::cout << "The track '" << itf->second.getTrackTitle() << "' is playing." << std::endl;
    std::cout << "Info:" << std::endl;
    std::cout << "\t Created date: " << itf->second.getDate().tm_year+1900 << "/";
    std::cout <<  itf->second.getDate().tm_mon+1 << "/" << itf->second.getDate().tm_mday << std::endl;
    std::cout << "\t Duration: " << itf->second.getDuration() << std::endl;

    playingTrack = itf->second.getTrackTitle();
}

void Player::stop()
{
    if (is_play)
    {
        std::cout << "The track '" << playingTrack << " 'is stopped.";
        is_play = false;
    }
}
