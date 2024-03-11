#include <curses.h>
#include <stdlib.h>

// Dimensioni del campo di gioco
#define GRID_WIDTH 20
#define GRID_HEIGHT 10

// Struttura per rappresentare un Tetrimino
typedef struct {
    int shape[4][1]; // Ridimensionato a 4x1
    int posX, posY;
} Tetrimino;

// Funzione per inizializzare la libreria curses
void init() {
    initscr(); // Inizializza la libreria curses
    noecho(); // Disabilita l'echo delle caratteri
    curs_set(0); // Nasconde il cursore
    keypad(stdscr, TRUE); // Abilita la lettura delle tasti speciali
    timeout(100); // Imposta un timeout per la lettura delle tasti
}

// Funzione per disegnare la griglia vuota con bordi centrata
void drawGrid(Tetrimino* tetriminos, int numTetriminos) {
    clear(); // Pulisce lo schermo

    // Ottieni le dimensioni della finestra del terminale
    int termWidth, termHeight;
    getmaxyx(stdscr, termHeight, termWidth);

    // Calcola la posizione iniziale della griglia per centrarla
    int startX = (termWidth - GRID_WIDTH) / 2;
    int startY = (termHeight - GRID_HEIGHT) / 2;

    // Disegna i bordi della griglia
    for (int x = startX; x < startX + GRID_WIDTH; x++) {
        mvaddch(startY + GRID_HEIGHT - 1, x, '_'); // Bordo inferiore
    }
    for (int y = startY; y < startY + GRID_HEIGHT; y++) {
        mvaddch(y, startX, '|'); // Bordo sinistro
        mvaddch(y, startX + GRID_WIDTH - 1, '|'); // Bordo destro
    }

    // Disegna la griglia vuota
    for (int y = startY + 1; y < startY + GRID_HEIGHT - 1; y++) {
        for (int x = startX + 1; x < startX + GRID_WIDTH - 1; x++) {
            // Utilizza il carattere spazio ' ' per rappresentare le celle vuote
            mvaddch(y, x, ' ');
        }
    }

    // Disegna i Tetrimini
    for (int i = 0; i < numTetriminos; i++) {
        for (int x = 0; x < 4; x++) {
            if (tetriminos[i].shape[x][0]) {
                mvaddch(tetriminos[i].posY + startY + 1, tetriminos[i].posX + startX + 1 + x, '#');
            }
        }
    }

    refresh(); // Aggiorna lo schermo
}

// Funzione per spostare un Tetrimino
void moveTetrimino(Tetrimino* tetrimino, int dx, int dy) {
    // Calcola la nuova posizione
    int newX = tetrimino->posX + dx;
    int newY = tetrimino->posY + dy;

    // Verifica se il movimento è valido
    if (newX < 0 || newX + 5 > GRID_WIDTH -1 || newY < 0 || newY + 1 > GRID_HEIGHT - 1) {
        // Il movimento è fuori dai limiti della griglia, quindi non lo eseguiamo
        return;
    }

    // Se il movimento è valido, aggiorna la posizione del Tetrimino
    tetrimino->posX = newX;
    tetrimino->posY = newY;
}

// Funzione principale
int main() {

    init(); // Inizializza la libreria curses

    // Inizializza un array di Tetrimini
    Tetrimino tetriminos[10]; // Supponendo che ci siano fino a 10 Tetrimini contemporaneamente
    int numTetriminos = 1; // Numero iniziale di Tetrimini

    // Inizializza il primo Tetrimino
    tetriminos[0].posX = GRID_WIDTH / 2 - 2; // Centra orizzontalmente
    tetriminos[0].posY = 0; // Inizia in alto
    // Inizializza con una forma di Tetrimino semplice
    for (int i = 0; i < 4; i++) {
        tetriminos[0].shape[i][0] = 1;
    }

    while (true) {
        drawGrid(tetriminos, numTetriminos); // Disegna la griglia e i Tetrimini

        int ch = getch();
        if (ch == 'a') { // Muovi a sinistra
            moveTetrimino(&tetriminos[numTetriminos - 1], -1, 0);
        } else if (ch == 'd') { // Muovi a destra
            moveTetrimino(&tetriminos[numTetriminos - 1], 1, 0);
        } else if (ch == 's') { // Muovi verso il basso
            moveTetrimino(&tetriminos[numTetriminos - 1], 0, 1);
        }

        // Verifica se il Tetrimino corrente ha toccato la base della griglia
        if (tetriminos[numTetriminos - 1].posY + 1 >= GRID_HEIGHT - 1) {
            // Il Tetrimino ha toccato la base, quindi crea un nuovo Tetrimino
            // Qui dovresti implementare la logica per creare un nuovo Tetrimino
            // e inizializzarlo con una forma casuale
            // Per semplicità, inizializziamo un nuovo Tetrimino alla stessa posizione
            numTetriminos++;
            tetriminos[numTetriminos - 1].posX = GRID_WIDTH / 2 - 2;
            tetriminos[numTetriminos - 1].posY = 0;
            for (int i = 0; i < 4; i++) {
                tetriminos[numTetriminos - 1].shape[i][0] = 1;
            }
        }
    }

    endwin(); // Termina la libreria curses
    return 0;
}
