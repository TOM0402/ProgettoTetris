#include <ncurses.h>
#include "../Classifica/classifica.hpp"

const int N=10;

struct leaderboard {
    int points;
    char data[N];
    char nome[];
};

class Lead {
private:
    leaderboard leadList[N];
    WINDOW* leadscr;
public:
    Lead();
    void printLead();
    void initgrill(WINDOW* griglia,int h, int w);
    WINDOW* getLeadscr();
};