#ifndef PROGETTOTETRIS_COLLISIONIQUADRATO_HPP
#define PROGETTOTETRIS_COLLISIONIQUADRATO_HPP
#include "Collisioni.hpp"

class CollisioniQuadrato:public Collisioni{
public:
    CollisioniQuadrato();
    bool checkDownQ(int, int);
    bool checkLeftQ(int, int);
    bool checkRightQ(int, int);
};


#endif //PROGETTOTETRIS_COLLISIONIQUADRATO_HPP
