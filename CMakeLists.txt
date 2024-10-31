cmake_minimum_required(VERSION 3.26)
project(ProgettoTetris)

set(CMAKE_CXX_STANDARD 17)
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
add_executable(ProgettoTetris
        main.cpp
        fileManagement/file.cpp
        fileManagement/file.hpp
        Giocatore/Giocatore.cpp
        Giocatore/Giocatore.hpp
        prova.txt
        Classifica/classifica.cpp
        Classifica/classifica.hpp
        Screen/Screen.cpp
        Screen/Screen.hpp
        Tetramino/Tetramino.cpp
        Tetramino/Tetramino.hpp
        Screen/Leaderboard.cpp
        Screen/Leaderboard.hpp
        Screen/Home.cpp
        Screen/Home.hpp
        Screen/Name.cpp
        Screen/Name.hpp
        Screen/Game.cpp
        Screen/Game.hpp
        Collisioni/Collisioni.cpp
        Collisioni/Collisioni.hpp
        Tetramino/TetraminoQuadrato.cpp
        Tetramino/TetraminoQuadrato.hpp
        Collisioni/CollisioniQuadrato.cpp
        Collisioni/CollisioniQuadrato.hpp
        Collisioni/CollisioniLungo.cpp
        Collisioni/CollisioniLungo.hpp
        Tetramino/TetraminoLungo.cpp
        Tetramino/TetraminoLungo.hpp
        Screen/SideBar.cpp
        Screen/SideBar.hpp
        Engine/Engine.cpp
        Engine/Engine.hpp
        Tetramino/TetraminoNuovo.cpp
        Tetramino/TetraminoNuovo.hpp
        Collisioni/CollisioniNuovo.cpp
        Collisioni/CollisioniNuovo.hpp
        Screen/GameOver.cpp
        Screen/GameOver.hpp
)
target_link_libraries( ProgettoTetris ${CURSES_LIBRARIES} )
