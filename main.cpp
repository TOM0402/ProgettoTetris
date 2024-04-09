#include "fileManagement/file.hpp"
#include "Classifica/classifica.hpp"
using namespace std;
int main() {
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
    }


    for(int i = 0; i<ngiocatori;i++){
        cout<<cla.giocatori[i].getNome()<<" "<<cla.giocatori[i].getPunteggio()<<" "<<cla.giocatori[i].getDataPunteggio()<<endl;
    }

*/
    cout<<"Test classe gestione classifica"<<endl;
    HandlerClassifica * c = new HandlerClassifica("prova.txt");
    classifica cla;
    //TODO non salva bene la classifica /legge 
    c->getClassifica(cla);
    for(int i = 0; i<ngiocatori;i++){
        cout<<cla.giocatori[i].getNome()<<" "<<cla.giocatori[i].getPunteggio()<<" "<<cla.giocatori[i].getDataPunteggio()<<endl;
    }
    return 0;
}