#include "ScreenG.hpp"
#include <ncurses.h>
using namespace std;

const int N=11;

Screen::Screen(int h, int w) {
    int yMax,xMax;
    high=h;
    wide=w;
    getmaxyx(stdscr,yMax,xMax);
    int startY=(yMax/2)-high/2;
    int startX=(xMax/2)-wide/2;
    screen=newwin(high,wide, startY,startX);
    //borderscreen();
}

void Screen::borderscreen(){

    wattron(screen,COLOR_PAIR(2));
    wattron(screen,A_ALTCHARSET);

    //box(griglia, 0,0);
    //wborder(screen, 'Y', 'Y', 'R', 'R', 'C', 'B', 'D', 'A'); // Windows
    wborder(screen, 'x', 'x', 'q', 'q', 'l', 'k', 'm', 'j'); // Linux

    wattroff(screen,COLOR_PAIR(2));
    wattroff(screen,A_ALTCHARSET);

    refresh();
    wrefresh(screen);
}

Leaderboard::Leaderboard(int h, int w):Screen(h,w){}

void Leaderboard::printLead() {
    HandlerClassifica lead("prova.txt");
    int lclass=lead.getCurrentPlayer();
    Giocatore player[lclass];
    lead.getClassifica(player);

    wattron(screen, COLOR_PAIR(5));
    wattron(screen,A_BOLD | A_UNDERLINE);
    mvwprintw(screen,2,(wide-11)/2,"LEADERBOARD");
    wattroff(screen,A_BOLD | A_UNDERLINE);
    mvwprintw(screen,4,3,"#  NAME\t\tPOINTS\tDATE");
    for (int i = 0; i < lclass; i++) {
        mvwprintw(screen,i*2+6,3,"%d",i+1);
        wprintw(screen,". ");
        wprintw(screen,player[i].getNome());
        if(strlen(player[i].getNome())<3) {
            wprintw(screen,"\t\t\t");
        }
        else {
            wprintw(screen,"\t\t");
        }
        wprintw(screen,"%d",player[i].getPunteggio());
        wprintw(screen,"\t");
        wprintw(screen,player[i].getDataPunteggio());
    }
    wattroff(screen,COLOR_PAIR(5));
    refresh();
    wrefresh(screen);
}

Home::Home(int h, int w):Screen(h,w) {
    scelte[0]={"PLAY"};
    scelte[1]={"Leaderboard"};
}

void Home::printLogo(){
    int wl=38, hl=6;
    int y=6;
    int x=(wide-wl)/2 -1;
    mvwprintw(screen,y,x, "___________     __         .__        \n");
    mvwprintw(screen,y+1,x,"\\__    ___/____/  |________|__| ______\n");
    mvwprintw(screen,y+2,x,"  |    |_/ __ \\   __\\_  __ \\  |/  ___/\n");
    mvwprintw(screen,y+3,x,"  |    |\\  ___/|  |  |  | \\/  |\\___ \\ \n");
    mvwprintw(screen,y+4,x,"  |____| \\___  >__|  |__|  |__/____  >\n");
    mvwprintw(screen,y+5,x,"             \\/                    \\/ \n");

    //Red Blue Yellow Green Cyan Magenta // 38x6

    //colora lettere
    int tot, shift;
    for (int i=0; i< hl; i++) {
        tot=0; shift=8;
        for (int j=0; j<6; j++) { //6=letters
            if(j==1){shift=7;}
            else if(j==2){shift=6;}
            else if(j==3){shift=6;}
            else if(j==4){shift=4;}
            else if(j==5){shift=7;}
            mvwchgat(screen,y+i,x+tot, shift, A_BOLD, j+1, NULL);
            tot=tot+shift;
        }
    }

    //aggiustamenti
    mvwchgat(screen,y,x+8, 3, A_BOLD, 1, NULL);
    mvwchgat(screen,y+1,x+8, 3, A_BOLD, 1, NULL);

    mvwchgat(screen,y+1,x+14, 1, A_BOLD, 3, NULL);

    mvwchgat(screen,y+4,x+15, 1, A_BOLD, 2, NULL);

    mvwchgat(screen,y+1,x+20, 1, A_BOLD, 4, NULL);
    mvwchgat(screen,y+2,x+20, 1, A_BOLD, 4, NULL);

    mvwchgat(screen,y+2,x+27, 1, A_BOLD, 4, NULL);
    mvwchgat(screen,y+3,x+27, 1, A_BOLD, 4, NULL);

    refresh();
    wrefresh(screen);
};

int Home::menu() {
    int nc=2;
    //scelte[nc]={"PLAY","Leaderboard"};
    int scelta;
    int highlight=0;
    keypad(screen, true);

    wattron(screen, COLOR_PAIR(2));
    while(1){

        for (int i = 0; i < nc; i++) {
            if(i==highlight)
                wattron(screen, A_BOLD | A_UNDERLINE);
            mvwprintw(screen, high/2+i*4, (wide/2)-(i+1)*2-i, scelte[i]);
            wattroff(screen, A_BOLD | A_UNDERLINE);
        }
        scelta=wgetch(screen);

        switch(scelta){
            case KEY_UP:
                highlight--;
            if(highlight==-1)
                highlight=0;
            break;
            case KEY_DOWN:
                highlight++;
            if(highlight==nc)
                highlight=nc-1;
            break;
            default:
                break;
        }
        if(scelta==10)
            break;
    }
    wattroff(screen,COLOR_PAIR(2));

    printw("La tua scelta: %s", scelte[highlight]);
    return highlight;
}

Name::Name(int h, int w):Screen(h,w){}

void Name::insert() {
    echo();
    curs_set(1);

    char name[N];
    wattron(screen,COLOR_PAIR(2));
    mvwprintw(screen,0,2,"Inserisci il tuo Nome:");
    wattroff(screen,COLOR_PAIR(2));

    wmove(screen,2,3);

    wgetnstr(screen,name,N-1);

    // Stampa il nome inserito nella finestra principale
    mvprintw(high - 2, 0, "Nome inserito: %s", name);

    wrefresh(screen);
    refresh();
    noecho();
    curs_set(0);
}

Game::Game(int h, int w):Screen(h,w){}
