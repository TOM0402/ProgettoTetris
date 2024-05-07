#ifndef GIOCATORE_HPP
#define GIOCATORE_HPP
#include <cstring>
#include <ctime>
#define lnome 100

struct Punteggio {
    int punti;
    std::time_t data; // Campo per la data
};

class Giocatore {
private:
    char nome[lnome];
    Punteggio punteggio;
public:
    Giocatore();
    Giocatore(const char* nome);
    Giocatore(const char*, int, const char*);

    void setNome(const char*);
    const char* getNome() const;
    void setPunteggio(int);
    int getPunteggio() const;
    const char* getDataPunteggio() const;
    void setDataPunteggio(const char* data) ;
};

#endif