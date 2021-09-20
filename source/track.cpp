#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include "track.h"

Track::Track()
{
    std::cout << "Enter track title:";
    std::cin.ignore();
    std::getline (std::cin, trackTitle);

    std::cout << "Enter creation date in the format YYYY/MM/DD:";
    std::time_t date = std::time(nullptr);
    creationDate = *std::localtime(&date);
    std::cin >> std::get_time(&creationDate, "%Y/%m/%d");

    std::cout << "Enter track duration in seconds:";
    std::cin >> duration;
}
std::string Track::getTrackTitle()
{
    return trackTitle;
}
std::tm Track::getDate()
{
    return creationDate;
}
uint16_t Track::getDuration()
{
    return duration;
}