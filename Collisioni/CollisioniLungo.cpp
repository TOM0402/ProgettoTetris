#include "CollisioniLungo.hpp"
#include "Collisioni.hpp"

CollisioniLungo::CollisioniLungo():Collisioni(){}

bool CollisioniLungo::checkDownL(int newY, int newX, int ori) {
    if(ori==0){
        if(isEmpty(getMatrix(newY, newX)) && isEmpty(getMatrix(newY,newX+1)) && isEmpty(getMatrix(newY,newX+2)) && isEmpty(getMatrix(newY,newX+3)) && isEmpty(getMatrix(newY,newX+4)) && isEmpty(getMatrix(newY,newX+5))  && isEmpty(getMatrix(newY,newX+6)) && isEmpty(getMatrix(newY,newX+7))) {
            return true;
        }
        return false;
    }else{

    }
}
bool CollisioniLungo::checkLeftL(int newY, int newX, int ori) {
    if(ori==0){
        if(isEmpty(getMatrix(newY, newX))) {
            return true;
        }
        return false;
    }else{

    }
}

bool CollisioniLungo::checkRightL(int newY, int newX, int ori) {
    if(ori==0){
        if(isEmpty(getMatrix(newY, newX+7))) {
            return true;
        }
        return false;
    }else{

    }
}