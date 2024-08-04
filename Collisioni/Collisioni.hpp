//
// Created by kali on 7/25/24.
//

#ifndef PROGETTOTETRIS_COLLISIONI_HPP
#define PROGETTOTETRIS_COLLISIONI_HPP

#define GRID_WIDE 22
#define GRID_HIGH 22

class Collisioni {
protected:
    bool occupiedMatrix[GRID_HIGH][GRID_WIDE];
public:
    Collisioni();
    bool isEmpty(bool );
    bool getMatrix(int , int );
    void setMatrix(int , int, bool);
    bool checkDown(int, int);
    bool checkLeft(int, int);
    bool checkRight(int, int);
};


#endif //PROGETTOTETRIS_COLLISIONI_HPP
