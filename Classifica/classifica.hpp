#include "../Giocatore/Giocatore.hpp"
#include "../fileManagement/file.hpp"



struct classifica{
    Giocatore giocatori[ngiocatori];
};

class HandlerClassifica {
public:
    HandlerClassifica(char name[]);
    int getCurrentPlayer();
    bool aggiungi(Giocatore g);
    void getClassifica(Giocatore  []);
    void rimuovi(Giocatore g);
private:
    File * f;
    classifica data;
    int find(Giocatore g);
    int currentplayer;
};


