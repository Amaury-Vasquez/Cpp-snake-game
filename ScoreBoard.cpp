#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>

#include "ScoreBoard.h"


ScoreBoard::ScoreBoard() : file_name(".score") {
  read_top_players();
}

std::vector<Player> ScoreBoard::get_top_players() const {
  return this->top_players;
}

void ScoreBoard::add_top_player(Player player) {
  top_players.push_back(player);
}

void ScoreBoard::print_players() const {
  for(int i = 0; i < top_players.size(); i++)
    std::cout << top_players[i];
}

void ScoreBoard::read_top_players() {
  std::ifstream score_file(file_name);
  std::string name;
  int score;

  while(score_file.is_open() && score_file >> name >> score) {
    Player tmp(name, score);
    top_players.push_back(tmp);
  } 
  sort();
}

void ScoreBoard::save_players() const {
  std::ofstream score_file(file_name, std::ofstream::out | std::ofstream::trunc);
  for(int i = 0; i < top_players.size(); i++) {
    score_file << top_players[i];
  }
}

void ScoreBoard::sort() {
  print_players();
  std::cout << std::endl;
  std::vector<Player> players = this->top_players;
  players[0] = players[5];
  players[5] = players[2];
  this->top_players = players;
  print_players();
}