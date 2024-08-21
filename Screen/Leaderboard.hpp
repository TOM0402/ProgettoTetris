#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP
#include "Screen.hpp"

class Leaderboard:public Screen {
protected:
public:
    Leaderboard(int h, int w);
    void printLead();
};

#endif //LEADERBOARD_HPP
