#include "HandlerClassifica.hpp"

using namespace std;

HandlerClassifica::HandlerClassifica(char name[]) {
    f = new File(name);
    currentplayer =f->read(data.giocatori);
}

int HandlerClassifica::getCurrentPlayer() {
    return this->currentplayer;
}

int HandlerClassifica::find(Giocatore g) {
    bool found = false;
    int i = 0;
    while (!found && i<this->getCurrentPlayer()){
        if(strcmp(g.getNome(),this->data.giocatori[i].getNome()) == 0) found = true;
        else i++;
    }
    if(found) return i;
    else return -1;
}

bool HandlerClassifica::aggiungi(Giocatore g){
    bool found = false;
    int index = 0;
    int findex = find(g);
    
    // Se il giocatore esiste già
    if(findex != -1){
        if(this->data.giocatori[findex].getPunteggio() >= g.getPunteggio()) return true;
        else rimuovi(g);
    }
    
    // Trova la posizione corretta per il nuovo punteggio
    while(index < this->getCurrentPlayer() && 
          this->data.giocatori[index].getPunteggio() >= g.getPunteggio()) {
        index++;
    }
    // Se la classifica è piena
    if(this->getCurrentPlayer() == ngiocatori) {
        // Se il nuovo punteggio è peggiore dell'ultimo, non fare nulla
        if(index >= ngiocatori) {
            return false;
        }
        // Altrimenti, fai spazio per il nuovo punteggio
        for(int i = ngiocatori-1; i > index; i--) {
            this->data.giocatori[i] = this->data.giocatori[i-1];
        }
        this->data.giocatori[index] = g;
        found = true;
    } else {
        // Se c'è ancora spazio nella classifica
        for(int i = this->getCurrentPlayer(); i > index; i--) {
            this->data.giocatori[i] = this->data.giocatori[i-1];
        }
        this->data.giocatori[index] = g;
        found = true;
        currentplayer++;
    }

    if(found)currentplayer++;

    //salvo su file solo giocatori esistenti non quelli vuoti
    found = false;
    index = 0;
    Giocatore gio[this->currentplayer];
    for (int i = 0; i < this->currentplayer; i++) {
        gio[i] = this->data.giocatori[i];
    }
    f->write(gio, this->currentplayer);
    return found;
}

void HandlerClassifica::getClassifica(Giocatore g[]){
    Giocatore g_tmp[ngiocatori];
    currentplayer = f->read(g_tmp);
    for(int i = 0; i < this->getCurrentPlayer();i++) {
        g[i] = g_tmp[i];
    }
}

void HandlerClassifica::rimuovi(Giocatore g) {
    int i = 0;
    bool found = false;
    while(!found && i< this->currentplayer){
        if(strcmp(this->data.giocatori[i].getNome(),g.getNome()) == 0){
            found = true;
        }else i++;
    }
    //slide array a sinistra
    for(int a = i; a<this->currentplayer-1;a++){
        this->data.giocatori[a] = this->data.giocatori[a+1];
    }

    this->currentplayer--;

    this->f->write(this->data.giocatori,this->getCurrentPlayer());
}