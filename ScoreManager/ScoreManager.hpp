#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

class ScoreManager {
private:
    int currentScore;
    int level;
    int linesCleared;
    const int POINTS_SINGLE = 100;
    const int POINTS_DOUBLE = 300;
    const int POINTS_TRIPLE = 500;
    const int POINTS_TETRIS = 800;
    const int SOFT_DROP_POINTS = 1;
    const int HARD_DROP_POINTS = 2;
    const int LINES_PER_LEVEL = 5;   // Numbers of lines to clear to level up

public:
    ScoreManager();

    void addScore(int points);
    int getScore() const;
    void resetScore();

    int getLevel() const;
    void updateLevel();

    int getLinesCleared() const;
    void addLines(int lines);

    void addLinesClearedPoints(int lines);

    void addSoftDropPoints(int cells);
    void addHardDropPoints(int cells);
};

#endif