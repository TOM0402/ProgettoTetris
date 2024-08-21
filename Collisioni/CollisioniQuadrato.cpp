//
// Created by kali on 8/7/24.
//

#include "CollisioniQuadrato.hpp"
#include "Collisioni.hpp"

CollisioniQuadrato::CollisioniQuadrato():Collisioni(){}

bool CollisioniQuadrato::checkDownQ(int newY, int newX){
    if(isEmpty(getMatrix(newY, newX)) && isEmpty(getMatrix(newY, newX+1)) && isEmpty(getMatrix(newY, newX+2)) && isEmpty(getMatrix(newY, newX+3))){
        return true;
    }
    return false;
}

bool CollisioniQuadrato::checkLeftQ(int newY, int newX){
    if(isEmpty(getMatrix(newY, newX)) && isEmpty(getMatrix(newY+1, newX))){
        return true;
    }
    return false;
}

bool CollisioniQuadrato::checkRightQ(int newY, int newX){
    if(isEmpty(getMatrix(newY, newX)) && isEmpty(getMatrix(newY+1, newX))){
        return true;
    }
    return false;
}