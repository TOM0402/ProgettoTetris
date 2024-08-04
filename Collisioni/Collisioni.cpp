#include "../Screen/ScreenG.hpp"
#include "Collisioni.hpp"
#include <ncurses.h>
using namespace std;

Collisioni::Collisioni(){
    for(int i=0;i<22;i++){
        for(int j=0; j<22; j++){
            occupiedMatrix[i][j]=false;
        }
    }

}

bool Collisioni::isEmpty(bool a) {
    if(a){
        return false;
    }else{
        return true;
    }
}

bool Collisioni::getMatrix(int h, int w) {
    return occupiedMatrix[h][w];
}
void Collisioni::setMatrix(int h, int w, bool a){
    occupiedMatrix[h][w]=a;
}
bool Collisioni::checkDown(int newY, int newX) {
    if(isEmpty(getMatrix(newY, newX)) && isEmpty(getMatrix(newY,newX+1)) && isEmpty(getMatrix(newY,newX+2)) && isEmpty(getMatrix(newY,newX+3))) {
        return true;
    }
    return false;
}
bool Collisioni::checkLeft(int newY, int newX) {
    if(isEmpty(getMatrix(newY, newX))) {
        return true;
    }
    return false;
}

bool Collisioni::checkRight(int newY, int newX) {
    if(isEmpty(getMatrix(newY, newX))) {
        return true;
    }
    return false;
}