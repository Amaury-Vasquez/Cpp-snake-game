#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "Player.h"

class ScoreBoard {
  private: 
    std::vector<Player> top_players;
    const std::string filename = ".score";
    const int max_len = 20;
    // std::ofstream score_output;
    
  public:
    ScoreBoard();
    ~ScoreBoard();
    std::vector<Player> get_top_players() const;
    void add_top_player(Player);
    void print_players() const;
    void read_top_players();
    void save_players() const;
    void sort();
};

#endif