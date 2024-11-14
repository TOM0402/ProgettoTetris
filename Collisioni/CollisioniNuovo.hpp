//
// Created by kali on 10/28/24.
//

#ifndef PROGETTOTETRIS_COLLISIONINUOVO_HPP
#define PROGETTOTETRIS_COLLISIONINUOVO_HPP
#include "../Tetramino/TetraminoNuovo.hpp"



class CollisioniNuovo{
public:
    CollisioniNuovo();
    bool checkCollisioni(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo* t);
};

#endif //PROGETTOTETRIS_COLLISIONINUOVO_HPP
