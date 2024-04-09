#ifndef FILE_HPP
#define FILE_HPP
#include <fstream>
#include <iostream>
#include <cstring>
#include "../Giocatore/Giocatore.hpp"
#define lpunteggio  6
#define ldata 10

using namespace std;

class File {
public:
    File(const char*  filename);
    bool write(Giocatore g);
    void read(Giocatore g[]);
private:
    char filename[lnome];
};
#endif