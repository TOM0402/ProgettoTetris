#include "HandlerLeaderboard.hpp"

using namespace std;

HandlerLeaderboard::HandlerLeaderboard(char name[]) {
    f = new File(name);
    currentplayer =f->read(data.players);
}

int HandlerLeaderboard::getCurrentPlayer() {
    return this->currentplayer;
}

/**
 * This method searches for a player in the leaderboard by comparing the player's name
 * with the names of players currently in the leaderboard. If the player is found, 
 * the index of the player is returned. If the player is not found, -1 is returned.
 */
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

/**
 * This function attempts to add a player to the leaderboard. If the player already exists and has a lower score, 
 * their score is updated. If the leaderboard is full, the function will only add the player if their score is 
 * higher than the lowest score on the leaderboard.
 */
bool HandlerLeaderboard::add_player(Player g){
    bool found = false;
    int index = 0;
    int findex = find(g);
    
    // if the player is already in the leaderboard
    if(findex != -1){
        if(this->data.players[findex].getPoints() >= g.getPoints()) return true;
        else remove_player(g);
    }
    
    // Find the correct position for the new score starting from the top
    while(index < this->getCurrentPlayer() && this->data.players[index].getPoints() >= g.getPoints()) {
        index++;
    }
    
    // if the leaderboard is full
    if(this->getCurrentPlayer() == num_players) {
        // if the player's score is lower than the lowest score on the leaderboard 
        if(index >= num_players) {
            return false;
        }
        // otherwise, add the player to the leaderboard and remove the last player doing the slicing
        for(int i = num_players-1; i > index; i--) {
            this->data.players[i] = this->data.players[i-1];
        }
        this->data.players[index] = g;
        found = true;
    } else {
        // if the leaderboard is not full, add the player to the leaderboard 
        for(int i = this->getCurrentPlayer(); i > index; i--) {
            this->data.players[i] = this->data.players[i-1];
        }
        this->data.players[index] = g;
        found = true;
        currentplayer++;
    }

    // write the updated leaderboard to the file
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

/**
 * This method searches for a player in the leaderboard by comparing the player's name.
 * If the player is found, they are removed from the leaderboard and the remaining players
 * are shifted to fill the gap. The total number of players is then decremented.
 * Finally, the updated leaderboard is written to the file.
 */
void HandlerLeaderboard::remove_player(Player g) {
    int i = 0;
    bool found = false;
    while(!found && i< this->currentplayer){
        if(strcmp(this->data.players[i].getName(),g.getName()) == 0){
            found = true;
        }else i++;
    }
    //shift the players to fill the gap
    for(int a = i; a<this->currentplayer-1;a++){
        this->data.players[a] = this->data.players[a+1];
    }

    this->currentplayer--;

    this->f->write(this->data.players,this->getCurrentPlayer());
}