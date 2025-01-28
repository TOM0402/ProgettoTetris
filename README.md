# ProgettoTetris

Project Programming course 2023/2024

## Description

ProgettoTetris is a classic Tetris game developed in C++ as part of the 2023/2024 programming project.

## Features

- Classic Tetris mechanics
- Increasing levels of difficulty
- Score tracking
- High-score leaderboard

## Prerequisites

- C++ compiler (e.g., g++ version 7.0 or higher)
- CMake (version 3.10 or higher)
- Make

## Installation

1. Clone the repository:
    ```
    git clone https://github.com/TOM0402/ProgettoTetris.git
    ```
2. Navigate to the project directory:
    ```
    cd ProgettoTetris
    ```

## Compilation

Use CMake to build the project:

```
mkdir build
cd build
cmake ..
make
```

## Usage

After compilation, run the game executable:

```
./ProgettoTetris
```

Use the arrow keys to move and rotate the Tetris blocks. Clear lines to earn points and advance levels.

## Contributors

Angelo Maggio, angelo.maggio3@studio.unibo.it;
    Graphics: Grid, Initial Menu, Game Sidebar, Leaderboard Page

Tommaso Bersani Berselli, tommaso.bersani@studio.unibo.it;
    Logic: Player,Score Manager, Leaderboard Management, File Saving, End Game

Alessio Atzeni, alessio.atzeni3@studio.unibo.it;
    Logic: Tetramino Class: Collisions, Spawn Pieces, Random Piece Generation
    Movement: Tetramino Movement, Tetramino Rotation
    Row Elimination




