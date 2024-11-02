#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <ncurses.h>
#include <ctime>
#include <iostream>
#include "../Screen/Home.hpp"
#include "../Screen/Game.hpp"
#include "../Screen/Screen.hpp"



class Engine{
private:

public:
    Engine();
    void init();
    bool setup();
    void play(Game playgrill);
    int moving(int ch, WINDOW* gameWin, WINDOW* nextWin, TetraminoNuovo* currentTetramino, TetraminoNuovo* nextTetramino, char board[GRID_HEIGHT][GRID_WIDTH], CollisioniNuovo* C, int &punteggio);
    void initBoard(char board[GRID_HEIGHT][GRID_WIDTH]);

};

#endif