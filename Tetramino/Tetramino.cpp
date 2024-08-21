#include "Tetramino.hpp"
#include "../Screen/Screen.hpp"
#include "../Collisioni/Collisioni.hpp"
#include <ncurses.h>
using namespace std;

Tetramino::Tetramino() {
    posX=22/2-2;
    posY=1;
}

int Tetramino::getPosX(){
    return posX;
}

int Tetramino::getPosY(){
    return posY;
}

void Tetramino:: drawTetramino(WINDOW*, Collisioni c){}
void Tetramino:: spawnTetramino(Screen, Collisioni c){}
void Tetramino:: clearTetramino(WINDOW*){}
void Tetramino:: moveTetramino(Tetramino* , Collisioni, int, WINDOW* screen){}