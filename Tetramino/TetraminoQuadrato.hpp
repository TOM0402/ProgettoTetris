#ifndef PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
#define PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
#include "Tetramino.hpp"

class TetraminoQuadrato:public Tetramino{

public:
    TetraminoQuadrato(Screen);
    void drawTetramino(WINDOW*, Collisioni c);
    void spawnTetramino(Screen, Collisioni c);
    void clearTetramino(WINDOW*);
    void moveTetramino(TetraminoQuadrato* , Collisioni, int, WINDOW* screen);
};


#endif //PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
