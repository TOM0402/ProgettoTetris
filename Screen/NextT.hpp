#ifndef NEXTT_HPP
#define NEXTT_HPP
#include "Screen.hpp"
#include "../Tetramino/Tetramino.hpp"

class NextT:public Screen {
protected:
public:
    NextT(int h, int w);
    void drawNextTetramino(Tetramino *t);
};

#endif //NEXTT_HPP
