//
// Created by tommaso on 11/03/24.
//
#include "../fileManagement/file.hpp"
using namespace std;
int main() {
    File * f = new File("prova.txt");
    Giocatore gio("Tommasooo");
    cout <<"Test get nomeee "<<endl<< "Nome: " << gio.getNome() << endl;

    Giocatore giocatori [10];
    //la write funziona
    //Giocatore g("Andrea",15,"11/06/2024");
    //f->write(g);
    f->read(giocatori);
    for (int i = 0; i < 10; i++) {
        cout << "Nome: " << giocatori[i].getNome() << endl;
        cout << "Punteggio: " << giocatori[i].getPunteggio() << endl;
        cout << "Data Punteggio: " << giocatori[i].getDataPunteggio() << endl;
        cout << "------------------------" << endl;
    }
    return 0;
}