//
// Created by kali on 10/28/24.
//

#include "CollisioniNuovo.hpp"
#include <iostream>

using namespace std;
CollisioniNuovo::CollisioniNuovo() {}

bool CollisioniNuovo::checkCollisioni(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo *t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(y, x) == 'X') {
                int boardX = t->getX() + x;
                int boardY = t->getY() + y;

                // Modifica qui: controllo più rigoroso dei bordi
                // Permettiamo il posizionamento nella prima colonna (boardX == 0)
                if (boardX < 0 || boardX >= GRID_WIDTH || boardY < 0 || boardY >= GRID_HEIGHT-2) {
                    return true; // Collisione con i bordi
                }

                // Controllo collisione con altri blocchi
                if (boardY >= 0 && board[boardY][boardX] == 'X') {
                    return true;
                }
            }
        }
    }
    return false;
}