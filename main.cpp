#include <ncurses.h>
#include "game.h"
#include "snake.h"

using namespace std;

int main() {
  Game snake_game;
  snake_game.play();
  return 0;
}