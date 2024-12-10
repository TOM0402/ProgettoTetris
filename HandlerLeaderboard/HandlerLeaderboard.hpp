#ifndef HANDLER_LEADERBOARD_HPP
#define HANDLER_LEADERBOARD_HPP

#include "../Player/Player.hpp"
#include "../FileManagement/File.hpp"

struct leaderboard{
    Player players[num_players];
};

class HandlerLeaderboard {
public:
    HandlerLeaderboard(char name[]);
    int getCurrentPlayer();
    bool add_player(Player g);
    void getLeaderboard(Player  []);
    void remove_player(Player g);
private:
    File * f;
    leaderboard data;
    int find(Player g);
    int currentplayer;
};

#endif // HANDLER_CLASSIFICA_HPP


