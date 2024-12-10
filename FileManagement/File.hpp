#ifndef FILE_HPP
#define FILE_HPP
#include <fstream>
#include <iostream>
#include <cstring>
#include "../Player/Player.hpp"
#define len_points  6
#define num_players 10


using namespace std;

class File {
public:
    File(char filename[]);
    bool write(Player g[], int);
    int read(Player g[]);
private:
    char filename[len_name];
};
#endif