#include "GameOver.hpp"

GameOver::GameOver(int h, int w):Screen(h,w) {
    scelte[0]={"Retry"};
    scelte[1]={"Home"};
}

void GameOver::printLogo(){
    int wl=21, delay=400;
    int y=3;
    int x=(wide-wl)/2;
    wattron(screen, COLOR_PAIR(1) | A_BOLD);
    mvwprintw(screen,y,x,  " _____\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+1,x,"|   __|___ _____ ___\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+2,x,"|  |  | .'|     | -_|\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+3,x,"|_____|__,|_|_|_|___|\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+4,x," _____\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+5,x,"|     |_ _ ___ ___\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+6,x,"|  |  | | | -_|  _|\n");
    //napms(delay); wrefresh(screen);
    mvwprintw(screen,y+7,x,"|_____|\\_/|___|_|\n");
    //napms(delay); wrefresh(screen);
    wattroff(screen, COLOR_PAIR(1) | A_BOLD);

    refresh();
    wrefresh(screen);
};

int GameOver::menu() {
    int nc=2;
    //scelte[nc]={"Retry","Home"};
    int scelta;
    int highlight=0;
    keypad(screen, true);

    wattron(screen, COLOR_PAIR(2));
    while(1){

        for (int i = 0; i < nc; i++) {
            if(i==highlight)
                wattron(screen, A_BOLD | A_UNDERLINE);
            mvwprintw(screen, (high/2)+(i*3)+3, (wide/2)-3, scelte[i]);
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

    //printw("La tua scelta: %s", scelte[highlight]);
    return highlight;
}
