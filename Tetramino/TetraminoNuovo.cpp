//
// Created by kali on 10/28/24.
//

#include "TetraminoNuovo.hpp"
TetraminoNuovo::TetraminoNuovo() {

}
char TetraminoNuovo::getTetramini(int x, int y, int z) {
    return tetramini[x][y][z];
}
char TetraminoNuovo::getShape(int x, int y) {
    return shape[x][y];
}

void TetraminoNuovo::setShape(int x, int y, char a){
    shape[x][y]=a;
}

int TetraminoNuovo::getX() {
    return x;
}

int TetraminoNuovo::getY() {
    return y;
}

void TetraminoNuovo::setX(int a) {
    x=a;
}

void TetraminoNuovo::setY(int a) {
    y=a;
}

int TetraminoNuovo::getColor() {
    return color;
}

void TetraminoNuovo::setColor(int a) {
    color=a;
}