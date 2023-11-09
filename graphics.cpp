#include <ncurses.h>
#include <unistd.h>
int main() {
  //Inizializza la libreria ncurses
  initscr();

  // Disabilita l'echo delle pressioni dei tasti
  //noecho();

  // Nasconde il cursore
  //curs_set(FALSE);

  // Crea una finestra 20x10
  WINDOW* win = newwin(20, 10, 0, 0);

  // Disegna la griglia sullo schermo
  box(win, 0, 0); // Disegna i bordi della finestra

  // Aggiorna la visualizzazione dello schermo
  wrefresh(win);

  // Aspetta 5 secondi prima di terminare il programma
  sleep(5);
  //getch();
  // Ripristina il comportamento normale del terminale
  endwin();
  return 0;
}