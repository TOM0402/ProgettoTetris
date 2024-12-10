#include "HandlerLeaderboard.hpp"

using namespace std;

HandlerLeaderboard::HandlerLeaderboard(char name[]) {
    f = new File(name);
    currentplayer =f->read(data.players);
}

int HandlerLeaderboard::getCurrentPlayer() {
    return this->currentplayer;
}

int HandlerLeaderboard::find(Player g) {
    bool found = false;
    int i = 0;
    while (!found && i<this->getCurrentPlayer()){
        if(strcmp(g.getName(),this->data.players[i].getName()) == 0) found = true;
        else i++;
    }
    if(found) return i;
    else return -1;
}

bool HandlerLeaderboard::add_player(Player g){
    bool found = false;
    int index = 0;
    int findex = find(g);
    
    // Se il giocatore esiste già
    if(findex != -1){
        if(this->data.players[findex].getPoints() >= g.getPoints()) return true;
        else remove_player(g);
    }
    
    // Trova la posizione corretta per il nuovo punteggio partendo dall alto
    while(index < this->getCurrentPlayer() && this->data.players[index].getPoints() >= g.getPoints()) {
        index++;
    }
    
    // Se la classifica è piena
    if(this->getCurrentPlayer() == num_players) {
        // Se il nuovo punteggio è peggiore dell'ultimo, non fare nulla
        if(index >= num_players) {
            return false;
        }
        // Altrimenti, fai spazio per il nuovo punteggio
        for(int i = num_players-1; i > index; i--) {
            this->data.players[i] = this->data.players[i-1];
        }
        this->data.players[index] = g;
        found = true;
    } else {
        // Se c'è ancora spazio nella classifica
        for(int i = this->getCurrentPlayer(); i > index; i--) {
            this->data.players[i] = this->data.players[i-1];
        }
        this->data.players[index] = g;
        found = true;
        currentplayer++;
    }

    //salvo su file solo players esistenti non quelli vuoti
    Player gio[this->currentplayer];
    for (int i = 0; i < this->currentplayer; i++) {
        gio[i] = this->data.players[i];
    }
    f->write(gio, this->currentplayer);
    return found;
}

void HandlerLeaderboard::getLeaderboard(Player g[]){
    Player g_tmp[num_players];
    currentplayer = f->read(g_tmp);
    for(int i = 0; i < this->getCurrentPlayer();i++) {
        g[i] = g_tmp[i];
    }
}

void HandlerLeaderboard::remove_player(Player g) {
    int i = 0;
    bool found = false;
    while(!found && i< this->currentplayer){
        if(strcmp(this->data.players[i].getName(),g.getName()) == 0){
            found = true;
        }else i++;
    }
    //slide array a sinistra
    for(int a = i; a<this->currentplayer-1;a++){
        this->data.players[a] = this->data.players[a+1];
    }

    this->currentplayer--;

    this->f->write(this->data.players,this->getCurrentPlayer());
}