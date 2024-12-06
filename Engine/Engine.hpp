#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <ncurses.h>
#include "../Screen/Home.hpp"
#include "../Screen/Screen.hpp"
#include "../Screen/NextT.hpp"
#include "../Screen/GameOver.hpp"
#include "../ScoreManager/ScoreManager.hpp"
#include "../Screen/SideBar.hpp"
#include "../Screen/Leaderboard.hpp"
#include "../Screen/Name.hpp"
#include "../HandlerClassifica/HandlerClassifica.hpp"

class Engine {
private:
    WINDOW* gameWin;
    WINDOW* nextWin;
    char board[GRID_HEIGHT][GRID_WIDTH];
    Tetramino* currentTetramino;
    Tetramino* nextTetramino;
    ScoreManager scoreManager;
    SideBar* sideBar;
    HandlerClassifica* classificaHandler;
    void startGame(char* playerName);
    void showLeaderboard();
public:
    Engine();
    void init();
    bool setup();
    void printBoard();
    void play(Screen playgrill, NextT, SideBar&);
    bool moving(int ch, int &score, bool isAutomatic = false);
    void initBoard();
    void drawNextTetramino(Tetramino*);
    Tetramino* createTetramino();
    int clearLines();
    void updateSideBar();
    void run();
};

#endif