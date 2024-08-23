#ifndef PROGETTOTETRIS_COLLISIONI_HPP
#define PROGETTOTETRIS_COLLISIONI_HPP


#define GRID_WIDE 22
#define GRID_HIGH 22

class Collisioni {
public:
    bool occupiedMatrix[GRID_HIGH][GRID_WIDE];
public:
    Collisioni();
    bool isEmpty(bool );
    bool getMatrix(int , int );
    void setMatrix(int , int, bool);
};


#endif //PROGETTOTETRIS_COLLISIONI_HPP
