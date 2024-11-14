#ifndef NEXTT_HPP
#define NEXTT_HPP
#include "Screen.hpp"
#include "../Tetramino/TetraminoNuovo.hpp"

class NextT:public Screen {
protected:
public:
    NextT(int h, int w);
    void drawNextTetramino(TetraminoNuovo *t);
};

#endif //NEXTT_HPP
