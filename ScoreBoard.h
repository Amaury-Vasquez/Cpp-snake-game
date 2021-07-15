#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <fstream>
#include <vector>

#include "Player.h"

class ScoreBoard {
  private: 
    std::vector<Player> top_players;
    const char *file_name;
    
  public:
    ScoreBoard();
    std::vector<Player> get_top_players() const;
    void add_top_player(Player);
    void print_players() const;
    void read_top_players();
    void save_players() const;
    void sort();
};

#endif