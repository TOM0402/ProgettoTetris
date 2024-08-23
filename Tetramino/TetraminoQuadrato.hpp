#ifndef PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
#define PROGETTOTETRIS_TETRAMINOQUADRATO_HPP


#include "../Collisioni/CollisioniQuadrato.hpp"
#include "TetraminoLungo.hpp"
#include <ncurses.h>

class TetraminoQuadrato:public Tetramino{

public:
    TetraminoQuadrato();
    void drawTetramino(WINDOW*);
    void spawnTetramino(Screen);
    void clearTetramino(WINDOW*);
    void moveTetramino(TetraminoQuadrato* , CollisioniQuadrato , int, WINDOW* screen);
};


#endif //PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
