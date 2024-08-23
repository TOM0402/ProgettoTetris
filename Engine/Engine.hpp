#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <ncurses.h>
#include <ctime>
#include <iostream>
#include "../Tetramino/TetraminoLungo.hpp"
#include "../Tetramino/TetraminoQuadrato.hpp"
#include "../Screen/Home.hpp"
#include "../Screen/Game.hpp"



class Engine{
private:
    TetraminoQuadrato *tq;
    TetraminoLungo *tl;
    CollisioniLungo cl = CollisioniLungo();
    CollisioniQuadrato cq = CollisioniQuadrato();
public:
    Engine();
    void init();
    bool setup();
    int generateRandom();
    void play(Game playgrill);
    int moving(Game playgrill, int);

};

#endif