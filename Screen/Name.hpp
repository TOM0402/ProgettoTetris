#ifndef NAME_HPP
#define NAME_HPP
#include "ScreenG.hpp"

class Name:public Screen {
protected:
    char* name;
public:
    Name(int h, int w);
    void insert();
    char* getName();
};

#endif //NAME_HPP
