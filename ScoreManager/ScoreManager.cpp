#include "ScoreManager.hpp"

ScoreManager::ScoreManager() {
    currentScore = 0;
    level = 1;
    linesCleared = 0;
}

void ScoreManager::addScore(int points) {
    // The score is multiplied by the level
    currentScore += points * level;
}

int ScoreManager::getScore() const {
    return currentScore;
}

void ScoreManager::resetScore() {
    currentScore = 0;
    level = 1;
    linesCleared = 0;
}

int ScoreManager::getLevel() const {
    return level;
}

void ScoreManager::updateLevel() {
    // The level is calculated based on the number of lines cleared
    level = (linesCleared / LINES_PER_LEVEL) + 1;
}

int ScoreManager::getLinesCleared() const {
    return linesCleared;
}

void ScoreManager::addLines(int lines) {
    linesCleared += lines;
    updateLevel();
}

/**
 * This method awards points according to the number of lines cleared in a single move.
 * The points awarded are defined by the constants POINTS_SINGLE, POINTS_DOUBLE, 
 * POINTS_TRIPLE, and POINTS_TETRIS for clearing 1, 2, 3, and 4 lines respectively.
 * Additionally, it updates the total number of lines cleared.
 */
void ScoreManager::addLinesClearedPoints(int lines) {
    switch(lines) {
        case 1:
            addScore(POINTS_SINGLE);
            break;
        case 2:
            addScore(POINTS_DOUBLE);
            break;
        case 3:
            addScore(POINTS_TRIPLE);
            break;
        case 4:
            addScore(POINTS_TETRIS);
            break;
    }
    addLines(lines);
}

void ScoreManager::addSoftDropPoints(int cells) {
    currentScore += SOFT_DROP_POINTS * cells;
}

void ScoreManager::addHardDropPoints(int cells) {
    currentScore += HARD_DROP_POINTS * cells;
}