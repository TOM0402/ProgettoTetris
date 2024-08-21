#ifndef PROGETTOTETRIS_TETRAMINOLUNGO_HPP
#define PROGETTOTETRIS_TETRAMINOLUNGO_HPP

#include "Tetramino.hpp"
#include "../Collisioni/CollisioniLungo.hpp"

class TetraminoLungo:public Tetramino{
public:
    TetraminoLungo(Screen);
    void drawTetramino(WINDOW*, CollisioniLungo c);
    void spawnTetramino(Screen, CollisioniLungo c);
    void clearTetramino(WINDOW*);
    void moveTetramino(TetraminoLungo* , CollisioniLungo, int, WINDOW* screen);
};

#endif //PROGETTOTETRIS_TETRAMINOLUNGO_HPP
