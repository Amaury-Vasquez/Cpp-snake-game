#include <iostream>
#include <fstream>

#include "Player.h"
#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() {
  this->len = 0;
  read_top_players();
}

ScoreBoard::~ScoreBoard() {
  // save_players();
}

bool ScoreBoard::add_top_player(Player player) {
  int i = is_top_score(player);
  if(i >= 0) {
    if(len < MAX_LEN) 
      this->len++;
    Player tmp = player;
    while(i < len) {
      std::cout << tmp;
      Player aux = top_players[i];
      this->top_players[i++] = tmp;
      tmp = aux;
    }
    return true;
  }
  return false;
}

// Returns top score index. If is not top score then returns -1
int ScoreBoard::is_top_score(Player player) const {
  int i;
  for(i = 0; i < len && player < top_players[i]; i++) {
    if(i + 1 < len && top_players[i + 1] < player)
      return i + 1;
  }
  return i < MAX_LEN? i : -1;
}

void ScoreBoard::print_players() const {
  for(int i = 0; i < len; i++)
    std::cout << top_players[i];
}

void ScoreBoard::read_top_players() {
  std::ifstream score_input(filename);
  int score;
  std::string name;

  while(score_input.is_open() && score_input >> name >> score) {
    Player tmp(name, score);
    add_top_player(tmp);
  }
}

void ScoreBoard::save_players() const {
  std::ofstream score_file(filename, std::ofstream::out | std::ofstream::trunc);
  for(int i = 0; i < len; i++)
    score_file << top_players[i];
}

void ScoreBoard::sort() {
  // print_players();
  // std::cout << std::endl;
  // std::vector<Player> players = this->top_players;
  // players[0] = players[5];
  // players[5] = players[2];
  // this->top_players = players;
  // print_players();
}