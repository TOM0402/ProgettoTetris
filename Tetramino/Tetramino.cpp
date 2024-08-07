#include "Tetramino.hpp"
#include "../Screen/ScreenG.hpp"
#include "../Collisioni/Collisioni.hpp"
#include <ncurses.h>
using namespace std;

Tetramino::Tetramino(Screen screen) {
    posY=1;
    posX=(screen.getWide()/2)-2;
}

int Tetramino::getPosX(){
    return posX;
}

int Tetramino::getPosY(){
    return posY;
}
