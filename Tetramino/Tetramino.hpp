#ifndef PROGETTOTETRIS_TETRAMINONUOVO_HPP
#define PROGETTOTETRIS_TETRAMINONUOVO_HPP

#define GRID_WIDTH 10
#define GRID_HEIGHT 22
class Tetramino {
protected:
    char shape[4][4];
    int x, y;
    int color;
    char tetramini[7][4][5] = {
            {"....", "XXXX", "....", "...."},
            {".X..", ".X..", ".XX.", "...."},
            {"..X.", "..X.", ".XX.", "...."},
            {"....", ".XX.", ".XX.", "...."},
            {".XX.", "XX..", "....", "...."},
            {"XX..", ".XX.", "....", "...."},
            {"..X.", ".XXX", "....", "...."}
    };

public:
    Tetramino();
    char getTetramini(int, int, int);
    char getShape(int , int );
    void setShape(int , int , char );
    int getColor();
    void setColor(int);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void rotateTetramino(Tetramino* t);
    void placeTetramino(char board[GRID_HEIGHT][GRID_WIDTH], Tetramino* t);
    bool checkCollisioni(char board[GRID_HEIGHT][GRID_WIDTH], Tetramino *t);
};


#endif //PROGETTOTETRIS_TETRAMINONUOVO_HPP
