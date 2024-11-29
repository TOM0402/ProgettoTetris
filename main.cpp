#include "fileManagement/file.hpp"
#include <ncurses.h>
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

    Home home(28,62);
    home.printLogo();
    home.borderscreen();
    int s = home.menu();

    clear();
    if (s == 0) {
        Name insName(5,34);
        insName.borderscreen();
        insName.insert();
        char* name = insName.getName();

        clear();

        SideBar sideGrill(22, 22, name);
        NextT next(22/2,22);
        Game playGrill(22,22);
        
        playGrill.borderscreen();
        sideGrill.borderscreen();
        sideGrill.printScores(0, 1); // Inizializza la sidebar con punteggio 0 e livello 1

        engine.play(playGrill, next, sideGrill);
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