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
        classifica.txt
        HandlerClassifica/HandlerClassifica.cpp
        HandlerClassifica/HandlerClassifica.hpp
        Screen/Screen.cpp
        Screen/Screen.hpp
        Screen/Leaderboard.cpp
        Screen/Leaderboard.hpp
        Screen/Home.cpp
        Screen/Home.hpp
        Screen/Name.cpp
        Screen/Name.hpp
        Screen/Game.cpp
        Screen/Game.hpp
        Screen/SideBar.cpp
        Screen/SideBar.hpp
        Engine/Engine.cpp
        Engine/Engine.hpp
        Tetramino/Tetramino.cpp
        Tetramino/Tetramino.hpp
        Screen/GameOver.cpp
        Screen/GameOver.hpp
        Screen/NextT.cpp
        Screen/NextT.hpp
        ScoreManager/ScoreManager.cpp
        ScoreManager/ScoreManager.hpp
)
target_link_libraries( ProgettoTetris ${CURSES_LIBRARIES} )
