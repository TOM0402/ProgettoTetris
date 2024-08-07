#include "CollisioniLungo.hpp"
#include "Collisioni.hpp"

CollisioniLungo::CollisioniLungo():Collisioni(){}

bool CollisioniLungo::checkDown(int newY, int newX) {
    if(isEmpty(getMatrix(newY, newX)) && isEmpty(getMatrix(newY,newX+1)) && isEmpty(getMatrix(newY,newX+2)) && isEmpty(getMatrix(newY,newX+3))) {
        return true;
    }
    return false;
}
bool CollisioniLungo::checkLeft(int newY, int newX) {
    if(isEmpty(getMatrix(newY, newX))) {
        return true;
    }
    return false;
}

bool CollisioniLungo::checkRight(int newY, int newX) {
    if(isEmpty(getMatrix(newY, newX))) {
        return true;
    }
    return false;
}