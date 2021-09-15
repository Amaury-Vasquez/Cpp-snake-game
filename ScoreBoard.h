#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "Player.h"

#define MAX_LEN 15

class ScoreBoard {
  private: 
    Player top_players[MAX_LEN];
    const std::string filename = ".score";
    int len;

  public:
    ScoreBoard();
    ~ScoreBoard();
    bool add_top_player(Player);
    int is_top_score(Player) const;
    void print_players() const;
    void read_top_players();
    void save_players() const;
    void sort();
};

#endif