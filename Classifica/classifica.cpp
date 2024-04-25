#include "classifica.hpp"

using namespace std;

HandlerClassifica::HandlerClassifica(char name[]) {
    f = new File(name);
    currentplayer =f->read(data.giocatori);
}

int HandlerClassifica::getCurrentPlayer() {
    return this->currentplayer;
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
    f->write(this->data.giocatori);
    return found;
}

void HandlerClassifica::getClassifica(Giocatore g[]){
    currentplayer = f->read(g);
}
