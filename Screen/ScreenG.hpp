#ifndef SCREENG_HPP
#define SCREENG_HPP
#include <ncurses.h>
#include "../Classifica/classifica.hpp"


class Screen {
protected:
    WINDOW* screen;
    int high;
    int wide;

public:
    Screen(int h, int w);
    void borderscreen();
};


class Leaderboard:public Screen {
protected:
public:
    Leaderboard(int h, int w);
    void printLead();
};

class Home:public Screen {
protected:
    char* scelte[]; //PLAY, Leaderboard
public:
    Home(int h, int w);
    void printLogo();
    int menu();
};

class Name:public Screen {
protected:
public:
    Name(int h, int w);
    void insert();
};

class Game:public Screen {
protected:
public:
    Game(int h, int w);
};

#endif //SCREENG_HPP