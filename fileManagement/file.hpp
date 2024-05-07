#ifndef FILE_HPP
#define FILE_HPP
#include <fstream>
#include <iostream>
#include <cstring>
#include "../Giocatore/Giocatore.hpp"
#define lpunteggio  6
#define ldata 10
#define ngiocatori 10


using namespace std;

class File {
public:
    File(char filename[]);
    bool write(Giocatore g[], int);
    int read(Giocatore g[]);
private:
    char filename[lnome];
};
#endif