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

                // Controllo bordi
            if (boardX < 0 || boardX >=  GRID_WIDTH || boardY <= 0 || boardY >= GRID_HEIGHT-2) {
                    return true; // Collisione con i bordi
                }

                // Controllo collisione con altri blocchi
                if (board[boardY][boardX] == 'X') {
                    return true;
                }
            }
        }
    }
    return false; // No collision
}