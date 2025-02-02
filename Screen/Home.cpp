#include "Home.hpp"

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
            mvwprintw(screen, high/2+i*4+3, (wide/2)-((i+1)*2)-i, scelte[i]);
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

    return highlight;
}
