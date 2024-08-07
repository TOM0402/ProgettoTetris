#ifndef PROGETTOTETRIS_COLLISIONILUNGO_HPP
#define PROGETTOTETRIS_COLLISIONILUNGO_HPP

#include "Collisioni.hpp"

class CollisioniLungo:public Collisioni{
public:
    CollisioniLungo();
    bool checkDown(int, int);
    bool checkLeft(int, int);
    bool checkRight(int, int);
};

#endif //PROGETTOTETRIS_COLLISIONILUNGO_HPP
