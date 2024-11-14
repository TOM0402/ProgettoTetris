#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <ncurses.h>
#include <ctime>
#include <iostream>
#include "../Screen/Home.hpp"
#include "../Screen/Game.hpp"
#include "../Screen/Screen.hpp"
#include "../Screen/NextT.hpp"
#include "../Screen/GameOver.hpp"

#define GRID_WIDTH 12
#define GRID_HEIGHT 20


class Engine{
private:
    WINDOW* gameWin;
    WINDOW* nextWin;
    char board[GRID_HEIGHT][GRID_WIDTH];
    CollisioniNuovo* C;
    TetraminoNuovo* currentTetramino;
    TetraminoNuovo* nextTetramino;
public:
    Engine();
    void init();
    bool setup();
    void play(Game playgrill, NextT);
    bool moving(int ch ,  int &punteggio);
    void initBoard();
    void drawNextTetramino(TetraminoNuovo*);
    TetraminoNuovo* createTetramino();
    int clearLines();
};

#endif