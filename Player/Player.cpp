#include "Player.hpp"

Player::Player() {
    strcpy(this->name, "");
    this->setPoints(0);
}

Player::Player(char name[]) {
    strcpy(this->name, name);
    this->setPoints(0);
}

Player::Player(char name[], int p, char d[]) {
    strcpy(this->name, name);
    this->setPoints(p);
    this->setDatePoints(d);
}

void Player::setName(char name[]) {
    strcpy(this->name, name);
}

char* Player::getName(){
    return this->name;
}

void Player::setPoints(int points) {
    this->points = points;
    time_t now = std::time(nullptr);
    // Get current date and time and store it in date array in the format dd/mm/yyyy 
    std::strftime(date, sizeof(date), "%d/%m/%Y", std::localtime(&now)); 
    this->setDatePoints(date);
}

int Player::getPoints() {
    return this->points;
}

char* Player::getDatePoints() {
    return this->date;
}

void Player::setDatePoints(char date[]) {
    strcpy(this->date,date);
}

/**
 * This method checks if the provided points (p) are greater than the player's current points.
 * If so, and if the provided points are positive, it adds the provided points to the player's
 * current points and returns true. Otherwise, it returns false.
 */
bool Player::updatePoints(int p){
  if(p>this->points){
    if (p>0){
      this->setPoints(this->getPoints()+p);
      return true;
    }
  }
  return false;
}
