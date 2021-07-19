#include <iostream>
#include <fstream>

#include "Game.h"
#include "Snake.h"

using namespace std;

int main() {
  ofstream score_file;
  score_file.open(".score", ios::in | ios::out | ios::app);
  score_file.close();
  Game snake;
  snake.play();
  return 0;
}