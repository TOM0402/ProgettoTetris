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