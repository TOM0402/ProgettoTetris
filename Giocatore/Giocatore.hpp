#ifndef GIOCATORE_HPP
#define GIOCATORE_HPP
#include <cstring>
#include <ctime>
#define lnome 100
#define ldata 11

class Giocatore {
private:
    char nome[lnome];
    int punti;
    char data[ldata];
public:
    Giocatore();
    Giocatore(char []);
    Giocatore(char [], int, char []);

    void setNome(char []);
    char* getNome();
    void setPunteggio(int);
    int getPunteggio();
    char* getDataPunteggio();
    void setDataPunteggio( char []) ;
};

#endif