#ifndef PROGETTOTETRIS_TETRAMINOLUNGO_HPP
#define PROGETTOTETRIS_TETRAMINOLUNGO_HPP

#include "Tetramino.hpp"
#include "../Collisioni/CollisioniLungo.hpp"

class TetraminoLungo:public Tetramino{
public:
    TetraminoLungo(Screen);
    void drawTetraminoL(WINDOW*, CollisioniLungo c);
    void spawnTetraminoL(Screen, CollisioniLungo c);
    void clearTetraminoL(WINDOW*);
    void moveTetraminoL(TetraminoLungo* , CollisioniLungo, int, WINDOW* screen);
};

#endif //PROGETTOTETRIS_TETRAMINOLUNGO_HPP
