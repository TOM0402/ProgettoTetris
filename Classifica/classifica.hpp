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
private:
    File * f;
    classifica data;
    int currentplayer;
};


