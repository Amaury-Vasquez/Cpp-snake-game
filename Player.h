#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
   
  private:
    const std::string name;
    const int score;

  public:
    Player(std::string, int);
    const std::string get_name() const;
    const int get_score() const;
    Player operator= (const Player&);
    bool operator< (const Player);
};

std::ostream& operator<<(std::ostream &output, const Player &);

// bool operator> (Player &a, Player &b);

#endif