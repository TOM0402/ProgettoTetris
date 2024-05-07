#include "Giocatore.hpp"
Giocatore::Giocatore() {
    strcpy(this->nome, "");
    this->setPunteggio(0);
}

Giocatore::Giocatore(const char* nome) {
    strcpy(this->nome, nome);
    this->setPunteggio(0);
}

Giocatore::Giocatore(const char* nome, int p, const char* d) {
    strcpy(this->nome, nome);
    this->setPunteggio(p);
    this->setDataPunteggio(d);
}

void Giocatore::setNome(const char* nome) {
    strcpy(this->nome, nome);
}

const char* Giocatore::getNome() const {
    return nome;
}

void Giocatore::setPunteggio(int punti) {
    punteggio.punti = punti;
    punteggio.data = std::time(nullptr); // Ottenere tempo corrente
}

int Giocatore::getPunteggio() const {
    return punteggio.punti;
}

const char* Giocatore::getDataPunteggio() const {
    // Formatta la data come giorno/mese/anno direttamente da time_t
    static char buffer[11]; // Buffer sufficiente per "dd/mm/aaaa\0"
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", std::localtime(&punteggio.data));

    return buffer;
}

void Giocatore::setDataPunteggio(const char* data) {
    struct tm tmData = {0}; // Inizializza la struttura tm a zero
    strptime(data, "%d/%m/%Y", &tmData); // Converte la stringa in tm
    punteggio.data = mktime(&tmData); // Converte tm in time_t
}
