#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

class ScoreManager {
private:
    int currentScore;
    int level;
    int linesCleared;
    const int POINTS_SINGLE = 100;    // 1 linea
    const int POINTS_DOUBLE = 300;    // 2 linee
    const int POINTS_TRIPLE = 500;    // 3 linee
    const int POINTS_TETRIS = 800;    // 4 linee
    const int SOFT_DROP_POINTS = 1;   // Punti per soft drop
    const int HARD_DROP_POINTS = 2;   // Punti per hard drop
    const int LINES_PER_LEVEL = 5;   // Linee necessarie per salire di livello

public:
    ScoreManager();

    // Gestione punteggio base
    void addScore(int points);
    int getScore() const;
    void resetScore();

    // Gestione livello
    int getLevel() const;
    void updateLevel();

    // Gestione linee
    int getLinesCleared() const;
    void addLines(int lines);

    // Calcolo punteggio per linee completate
    void addLinesClearedPoints(int lines);

    // Punti per movimenti
    void addSoftDropPoints(int cells);
    void addHardDropPoints(int cells);
};

#endif