#ifndef PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
#define PROGETTOTETRIS_TETRAMINOQUADRATO_HPP

#include "TetraminoLungo.hpp"
#include "../Collisioni/CollisioniQuadrato.hpp"

class TetraminoQuadrato:public Tetramino{

public:
    TetraminoQuadrato(Screen);
    void drawTetraminoQ(WINDOW*, CollisioniQuadrato c);
    void spawnTetraminoQ(Screen, CollisioniQuadrato c);
    void clearTetraminoQ(WINDOW*);
    void moveTetraminoQ(TetraminoQuadrato* , CollisioniQuadrato , int, WINDOW* screen);
};


#endif //PROGETTOTETRIS_TETRAMINOQUADRATO_HPP
