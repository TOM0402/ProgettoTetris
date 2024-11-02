//
// Created by kali on 10/28/24.
//

#ifndef PROGETTOTETRIS_TETRAMINONUOVO_HPP
#define PROGETTOTETRIS_TETRAMINONUOVO_HPP

#include "../Collisioni/CollisioniNuovo.hpp"
class TetraminoNuovo {
protected:
    char shape[4][5];
    int x, y;
    int color;
    char tetramini[7][4][5] = {
            {"....", "XXXX", "....", "...."},
            {".X..", ".X..", ".XX.", "...."},
            {"..X.", "..X.", ".XX.", "...."},
            {"....", ".XX.", ".XX.", "...."},
            {".XX.", "XX..", "....", "...."},
            {"XX..", ".XX.", "....", "...."},
            {"..X.", ".XXX", "....", "...."}
    };

public:
    TetraminoNuovo();
    char getTetramini(int, int, int);
    char getShape(int , int );
    void setShape(int , int , char );
    int getColor();
    void setColor(int);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void rotateTetramino(TetraminoNuovo* t);
    void placeTetramino(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo* t);
};


#endif //PROGETTOTETRIS_TETRAMINONUOVO_HPP
