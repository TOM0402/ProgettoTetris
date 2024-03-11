#include "Giocatore.hpp"

Giocatore::Giocatore(const std::string& nome) {
    this->nome = nome;
    this->setPunteggio(0);
}

void Giocatore::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Giocatore::getNome() const {
    return nome;
}

void Giocatore::setPunteggio(int punti) {
    punteggio.punti = punti;
    punteggio.data = std::time(nullptr);//ottenere tempo corrente
}

int Giocatore::getPunteggio() const {
    return punteggio.punti;
}

std::string Giocatore::getDataPunteggio() const {
    // Formatta la data come giorno/mese/anno direttamente da time_t
    char buffer[11]; // Buffer sufficiente per "dd/mm/aaaa\0"
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", std::localtime(&punteggio.data));

    return std::string(buffer);
}
