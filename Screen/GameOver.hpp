#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP
#include "Screen.hpp"

class GameOver:public Screen {
protected:
    char* scelte[]; // Retry, Home
public:
    GameOver(int h, int w);
    void printLogo();
    int menu();
};

#endif //GAMEOVER_HPP
