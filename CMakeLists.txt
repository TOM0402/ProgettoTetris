cmake_minimum_required(VERSION 3.27)
project(progetto)

set(CMAKE_CXX_STANDARD 17)
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
add_executable( progetto
        main.cpp
        fileManagement/file.cpp
        fileManagement/file.hpp
        Giocatore/Giocatore.cpp
        Giocatore/Giocatore.hpp
        prova.txt
        Classifica/classifica.cpp
        Classifica/classifica.hpp
)
target_link_libraries( progetto ${CURSES_LIBRARIES} )
