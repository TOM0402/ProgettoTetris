#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <ctime>
#define len_name 10
#define len_date 11

class Player {
private:
    char name[len_name];
    int points;
    char date[len_date];
public:
    Player();
    Player(char []);
    Player(char [], int, char []);

    void setName(char []);
    char* getName();
    void setPoints(int);
    int getPoints();
    char* getDatePoints();
    void setDatePoints( char []) ;
    bool updatePoints (int );
};

#endif
