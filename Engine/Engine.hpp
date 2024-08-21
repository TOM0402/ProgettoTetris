#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <ncurses.h>

#include "../Screen/Home.hpp"



class Engine{
private:
    p_list pezzi;

protected:
    Engine();
    void init();
    void setup();
    void play();

};

#endif