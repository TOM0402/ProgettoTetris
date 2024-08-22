#ifndef PROGETTOTETRIS_TETRAMINOLUNGO_HPP
#define PROGETTOTETRIS_TETRAMINOLUNGO_HPP

#include "Tetramino.hpp"
#include "../Collisioni/CollisioniLungo.hpp"

class TetraminoLungo:public Tetramino{
protected:
    int orientamento;
public:
    TetraminoLungo();
    int getOrientamento();
    void setOrientamento();
    void drawTetramino(WINDOW*);
    void spawnTetramino(Screen);
    void clearTetramino(WINDOW*, int );
    void moveTetramino(TetraminoLungo* , CollisioniLungo, int, WINDOW* screen);
};

#endif //PROGETTOTETRIS_TETRAMINOLUNGO_HPP
