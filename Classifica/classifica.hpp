#include "../Giocatore/Giocatore.hpp"
#include "../fileManagement/file.hpp"



struct classifica{
    Giocatore giocatori[ngiocatori];
};

class HandlerClassifica {
public:
    HandlerClassifica(char name[]);
    bool aggiungi(Giocatore g);
    void getClassifica(classifica c);
private:
    File * f;
    classifica data;
    int currentplayer;
};


