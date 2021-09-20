#pragma once
#ifndef SKILLBOX_HW_26_1_TRACK_H
#define SKILLBOX_HW_26_1_TRACK_H

class Track
{
private:
    std::string trackTitle;
    std::tm creationDate;
    uint16_t duration;

public:
    Track();
    std::string getTrackTitle ();
    std::tm getDate ();
    uint16_t getDuration ();
};

#endif //SKILLBOX_HW_26_1_TRACK_H
