#include <iostream>
#include <string>
#include "player.h"

static const int number = 6;

bool is_correct_answer (std::string answer, std::string* actions) {

    for (int i=0;i < number;++i) {
        if (answer == actions[i]) return true;
    }
    return false;
}

int main()
{
    std::string actions[] = {"add","play","pause","next","stop","exit"};
    std::string answer;
    Player myAudioPlayer;

    do {
        std::cout << "\nInput one from the list of commands:" << std::endl;
        for (int i=0;i < number;++i) {
            std::cout << "-" << actions[i] << std::endl;
        }
        std::cout << ">";

        do {
            std::cin >> answer;
            if (!(is_correct_answer(answer,actions))) std::cout << "Incorrect!Repeat.\n>";
        } while (!(is_correct_answer(answer,actions)));

        if (answer == actions[0]) {
            myAudioPlayer.track_add();
        }
        else if (answer == actions[1]) {
            std::string title;
            std::cout << "Enter a song to play:";
            std::cin >> title;
            myAudioPlayer.play(title);
        }
        else if (answer == actions[2]) {
            myAudioPlayer.pause();
        }
        else if (answer == actions[3]) {
            myAudioPlayer.next();
        }
        else if (answer == actions[4]) {
            myAudioPlayer.stop();
        }
    } while (answer != "exit");


    return 0;
}
