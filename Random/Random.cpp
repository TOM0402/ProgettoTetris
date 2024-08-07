#include "Random.hpp"
#include <ctime>
#include <iostream>

Random::Random() {}

bool Random::pezzo() {
    srand(time(0));
    if(rand()%2==0) {
        return false;
    }else{
        return true;
    }
}