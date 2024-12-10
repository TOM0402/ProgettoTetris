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
    std::strftime(date, sizeof(date), "%d/%m/%Y", std::localtime(&now));
    strcpy(this->date,date);

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

bool Player::updatePoints(int p){
  if(p>this->points){
    if (p>0){
      this->setPoints(this->getPoints()+p);
      return true;
    }
  }
  return false;
}
