#include "Player.h"

Player::Player(): score(0), name("") {}

Player::Player(std::string name, int score) : name(name), score(score) {}

const std::string Player::get_name() const {
  return name;
}

const int Player::get_score() const {
  return score;
}

Player Player::operator= (const Player &player) {
  Player tmp(player.get_name(), player.get_score());
  return tmp;
}

bool Player::operator< (const Player &b) const {
  if(this->get_score() < b.get_score())
    return true;
  return false;
}

std::ostream& operator<<(std::ostream &output, const Player &player) {
  output << player.get_name() << " " << player.get_score() << std::endl;
  return output;
}

// bool operator> (Player &a, Player &b) {
//   if(a.get_score() > b.get_score())
//     return true;
//   return false;
// }