#include <cstring>
#include "Giocatore.hpp"
#define ngiocatori 10;
struct classifica{
    Giocatore giocatori[ngiocatori];
};

class HandlerClassifica {
public:
    HandlerClassifica();
    bool aggiungi(Giocatore g);
    Giocatore [] getClassifica();
    bool rimuovi(Giocatore g);
private:
    classifica data;
};

/*
 * Classifica contiene: tutte info giocatore e posizione
 */