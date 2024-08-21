#ifndef PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
#define PROGETTOTETRIS_TETRAMINOQUADRATO_HPP

#include "TetraminoLungo.hpp"
#include "../Collisioni/CollisioniQuadrato.hpp"

class TetraminoQuadrato:public Tetramino{

public:
    TetraminoQuadrato(Screen);
    void drawTetramino(WINDOW*, CollisioniQuadrato c);
    void spawnTetramino(Screen, CollisioniQuadrato c);
    void clearTetramino(WINDOW*);
    void moveTetramino(TetraminoQuadrato* , CollisioniQuadrato , int, WINDOW* screen);
};


#endif //PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
