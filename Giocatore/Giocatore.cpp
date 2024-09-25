#include "Giocatore.hpp"

Giocatore::Giocatore() {
    strcpy(this->nome, "");
    this->setPunteggio(0);
}

Giocatore::Giocatore(char nome[]) {
    strcpy(this->nome, nome);
    this->setPunteggio(0);
}

Giocatore::Giocatore(char nome[], int p, char d[]) {
    strcpy(this->nome, nome);
    this->setPunteggio(p);
    this->setDataPunteggio(d);
}

void Giocatore::setNome(char nome[]) {
    strcpy(this->nome, nome);
}

char* Giocatore::getNome(){
    return this->nome;
}

void Giocatore::setPunteggio(int punti) {
    this->punti = punti;
    time_t now = std::time(nullptr);
    std::strftime(data, sizeof(data), "%d/%m/%Y", std::localtime(&now));
    strcpy(this->data,data);

}

int Giocatore::getPunteggio() {
    return this->punti;
}

char* Giocatore::getDataPunteggio() {
    return this->data;
}

void Giocatore::setDataPunteggio(char data[]) {
    strcpy(this->data,data);
}

bool Giocatore::updatePunteggio(int p){
  if(p>this->punti){
    if (p>0){
      this->setPunteggio(this->getPunteggio()+p);
      return true;
    }
  }
  return false;
}
