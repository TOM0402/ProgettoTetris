#ifndef GIOCATORE_HPP
#define GIOCATORE_HPP
#include <string>
#include <ctime>
struct Punteggio {
    int punti;
    std::time_t data; // Campo per la data
};

class Giocatore {
private:
    std::string nome;
    Punteggio punteggio;
public:
    Giocatore(const std::string& nome);
    void setNome(const std::string&);
    std::string getNome() const;
    void setPunteggio(int);
    int getPunteggio() const;
    std::string getDataPunteggio() const;
};

#endif