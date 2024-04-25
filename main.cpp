#include "fileManagement/file.hpp"
#include "Classifica/classifica.hpp"
#include <curses.h>
#include <stdlib.h>

using namespace std;

void init() {
    initscr(); // Inizializza la libreria curses
    noecho(); // Disabilita l'echo delle caratteri
    curs_set(0); // Nasconde il cursore
    keypad(stdscr, TRUE); // Abilita la lettura delle tasti speciali
    timeout(100); // Imposta un timeout per la lettura delle tasti
}

int main() {
    //init();
    /*
    File * f = new File("prova.txt");
    Giocatore giocatori [3];
    //la write funziona
    //Giocatore g("Andrea",15,"11/06/2024");
    //f->write(g);
    f->read(giocatori);
    for (int i = 0; i < 3; i++) {
        cout << "Nome: " << giocatori[i].getNome() << endl;
        cout << "Punteggio: " << giocatori[i].getPunteggio() << endl;
        cout << "Data Punteggio: " << giocatori[i].getDataPunteggio() << endl;
        cout << "------------------------" << endl;
        cout << "------------------------" << endl;
    }


    for(int i = 0; i<ngiocatori;i++){
        cout<<cla.giocatori[i].getNome()<<" "<<cla.giocatori[i].getPunteggio()<<" "<<cla.giocatori[i].getDataPunteggio()<<endl;
    }

*/ cout<<"Test classe gestione classifica"<<endl;
     HandlerClassifica * c = new HandlerClassifica("prova.txt");
     Giocatore gio[c->getCurrentPlayer()];
     //TODO segmentation fault a caso

     c->getClassifica(gio);
    for (int i = 0; i < c->getCurrentPlayer(); i++) {
        cout<<gio[i].getNome()<<endl;
    }
  /*   for(int i = 0; i<c->getCurrentPlayer();i++){
         cout<<gio[i].getNome()<<" "<<gio[i].getPunteggio()<<" "<<gio[i].getDataPunteggio()<<endl;
   }
     /*
     Giocatore g  = Giocatore("Added",70,"10/09/2024");
     c->aggiungi(g);
     cout<<c->getCurrentPlayer();
    */


    return 0;
}