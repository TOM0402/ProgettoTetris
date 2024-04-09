#include "classifica.hpp"

using namespace std;

HandlerClassifica::HandlerClassifica(char name[]) {
    f = new File(name);
    f->read(data.giocatori);
    currentplayer = 0;
}


bool HandlerClassifica::aggiungi(Giocatore g){
    bool found = false;
    int index = 0;
    while(!found && index < ngiocatori){
        if(this->data.giocatori[index].getPunteggio()>=g.getPunteggio())index++; // va dopo
        else {
            // slide array
            int i = currentplayer;
            while(i > index){
                this->data.giocatori[i] = this->data.giocatori[i-1];
                i--;
            }
            this->data.giocatori[index] = g;
            found = true;
        }
    }
    if(found)currentplayer++;
    return found;
}

void HandlerClassifica::getClassifica(classifica g){
    f->read(g.giocatori);
}
