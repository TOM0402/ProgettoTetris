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

                //Corrected Boundary Checks

                if (boardX <= 0 || boardX >= GRID_WIDTH || boardY <= 0 || boardY > GRID_HEIGHT) {
                    return true; // Collision with wall
                }

                //Simplified Collision Check
                if (board[boardY][boardX] == 'X') {
                    return true; // Collision with another block
                }
            }
        }
    }
    return false; // No collision
}