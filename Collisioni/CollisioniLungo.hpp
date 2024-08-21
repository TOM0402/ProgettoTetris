#ifndef PROGETTOTETRIS_COLLISIONILUNGO_HPP
#define PROGETTOTETRIS_COLLISIONILUNGO_HPP

#include "Collisioni.hpp"

class CollisioniLungo:public Collisioni{
public:
    CollisioniLungo();
    bool checkDownL(int, int);
    bool checkLeftL(int, int);
    bool checkRightL(int, int);
};

#endif //PROGETTOTETRIS_COLLISIONILUNGO_HPP
