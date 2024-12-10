cmake_minimum_required(VERSION 3.26)
project(ProgettoTetris)

set(CMAKE_CXX_STANDARD 17)
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
add_executable(ProgettoTetris
        main.cpp
        FileManagement/File.cpp
        FileManagement/File.hpp
        Player/Player.cpp
        Player/Player.hpp
        classifica.txt
        HandlerLeaderboard/HandlerLeaderboard.cpp
        HandlerLeaderboard/HandlerLeaderboard.hpp
        Screen/Screen.cpp
        Screen/Screen.hpp
        Screen/Leaderboard.cpp
        Screen/Leaderboard.hpp
        Screen/Home.cpp
        Screen/Home.hpp
        Screen/Name.cpp
        Screen/Name.hpp
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
