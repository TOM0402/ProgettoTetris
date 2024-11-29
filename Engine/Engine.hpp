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
#include "../ScoreManager/ScoreManager.hpp"
#include "../Screen/SideBar.hpp"

class Engine {
private:
    WINDOW* gameWin;
    WINDOW* nextWin;
    char board[GRID_HEIGHT][GRID_WIDTH];
    CollisioniNuovo* C;
    TetraminoNuovo* currentTetramino;
    TetraminoNuovo* nextTetramino;
    ScoreManager scoreManager;
    SideBar* sideBar;
public:
    Engine();
    void init();
    bool setup();
    void printBoard();
    int play(Screen playgrill, NextT, SideBar&);
    bool moving(int ch, int &punteggio, bool isAutomatic = false);
    void initBoard();
    void drawNextTetramino(TetraminoNuovo*);
    TetraminoNuovo* createTetramino();
    int clearLines();
    void updateSideBar();
};

#endif