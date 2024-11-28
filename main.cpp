#include "fileManagement/file.hpp"
#include <ncurses.h>
//#include <stdlib.h>
#include "Screen/Game.hpp"
#include "Screen/Leaderboard.hpp"
#include "Screen/Name.hpp"
#include "Screen/SideBar.hpp"
#include "Engine/Engine.hpp"
#include "Screen/GameOver.hpp"
#include "Screen/NextT.hpp"

using namespace std;

int main() {

    Engine engine;
    //engine.init();

    //int s= engine.setup();

    Home home(28,62);
    home.printLogo();
    home.borderscreen();
    int s =home.menu();

    clear();
    if (s==0) {
        Name insName(5,34);
        insName.borderscreen();
        insName.insert();
        char* name=insName.getName();

        // clear();
        // printw(name);
        // refresh();
        // getch();

        clear();

        SideBar sideGrill(22, 22, name);
        sideGrill.printScores();
        sideGrill.borderscreen();

        NextT next(22/2,22);

        Game playGrill(22,22);
        playGrill.borderscreen();

        engine.play(playGrill, next);

        /*
        GameOver gameover(20,40);
        gameover.printLogo();
        gameover.borderscreen();
        int s2 =gameover.menu();
        */
        //getch();
    }
    else { // CLASSIFICA
        Leaderboard lead(27,46);
        lead.borderscreen();
        lead.printLead();
    }

    getch();
    endwin();

    return 0; //prova linux
}