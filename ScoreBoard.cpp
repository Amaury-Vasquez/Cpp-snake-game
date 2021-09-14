#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#include "Player.h"
#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() {
  read_top_players();
}

ScoreBoard::~ScoreBoard() {
  save_players();
}

std::vector<Player> ScoreBoard::get_top_players() const {
  return this->top_players;
}

void ScoreBoard::add_top_player(Player player) {
  Player a("gg", 180);
  print_players();
  this->top_players.at(0) = a;
  std::cout << std::endl;
  print_players();

  // top_players.push_back(player);
}

void ScoreBoard::print_players() const {
  for(int i = 0; i < top_players.size(); i++)
    std::cout << top_players[i];
}

void ScoreBoard::read_top_players() {
  std::ifstream score_input(filename);
  int score;
  std::string name;

  while(score_input.is_open() && score_input >> name >> score) {
    Player tmp(name, score);
    top_players.push_back(tmp);
  } 
  // sort();
}

void ScoreBoard::save_players() const {
  std::ofstream score_file(filename, std::ofstream::out | std::ofstream::trunc);
  for(int i = 0; i < top_players.size(); i++)
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