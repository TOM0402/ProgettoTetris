#include "fileManagement/file.hpp"
#include <ncurses.h>
//#include <stdlib.h>
#include <vector>
#include "Collisioni/Collisioni.hpp"
#include "Collisioni/CollisioniLungo.hpp"
#include "Collisioni/CollisioniQuadrato.hpp"
#include "Screen/Game.hpp"
#include "Screen/Leaderboard.hpp"
#include "Screen/Name.hpp"
#include "Screen/SideBar.hpp"
#include "Engine/Engine.hpp"

using namespace std;

int main() {

    Engine engine;
    //engine.init();

    //int s= engine.setup();

    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    int s =home.menu();

    clear();
    if (s==0) {
        Name insName(5,34);
        insName.borderscreen();
        insName.insert();

        clear();
        SideBar sideGrill(GRID_HIGH, GRID_WIDE,insName.getName());
        sideGrill.printScores();
        sideGrill.borderscreen();

        Game playGrill(GRID_HIGH,GRID_WIDE);
        playGrill.borderscreen();

        engine.play(playGrill);

    }
    else { // CLASSIFICA
        Leaderboard lead(27,46);
        lead.borderscreen();
        lead.printLead();
    }

    getch();
    endwin();

    return 0;
}