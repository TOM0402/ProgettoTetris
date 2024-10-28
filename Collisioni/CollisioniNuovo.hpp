//
// Created by kali on 10/28/24.
//

#ifndef PROGETTOTETRIS_COLLISIONINUOVO_HPP
#define PROGETTOTETRIS_COLLISIONINUOVO_HPP
#include "../Tetramino/TetraminoNuovo.hpp"
#define GRID_WIDTH 10
#define GRID_HEIGHT 20

class CollisioniNuovo{
public:
    bool checkCollisioni(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo &t);
};

#endif //PROGETTOTETRIS_COLLISIONINUOVO_HPP
