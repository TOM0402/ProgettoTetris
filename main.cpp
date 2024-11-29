#include "Engine/Engine.hpp"

int main() {
    Engine engine;
    engine.run();
    
    getch();
    endwin();
    
    return 0;
}