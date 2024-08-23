#include "Collisioni.hpp"
using namespace std;

Collisioni::Collisioni(){
    for(int i=0;i<22;i++){
        for(int j=0; j<22; j++){
            occupiedMatrix[i][j]=false;
        }
    }
    for(int i=0;i<22;i++){
        occupiedMatrix[0][i]=true;
        occupiedMatrix[21][i]=true;
        occupiedMatrix[i][0]=true;
        occupiedMatrix[i][21]=true;
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
