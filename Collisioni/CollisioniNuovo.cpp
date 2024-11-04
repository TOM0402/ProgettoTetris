//
// Created by kali on 10/28/24.
//

#include "CollisioniNuovo.hpp"

CollisioniNuovo::CollisioniNuovo() {}

bool CollisioniNuovo::checkCollisioni(char (*board)[10], TetraminoNuovo *t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(y,x) == 'X') {
                int boardX = t->getX() + x;
                int boardY = t->getY() + y;
                if (boardX <= 0 || boardX >= GRID_WIDTH|| boardY >= GRID_HEIGHT-1 ||
                    (boardY >= 0 && board[boardY][boardX] == 'X')) {
                    return true;
                }
            }
        }
    }
    return false;
}