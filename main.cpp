#include <ncurses.h>
#include "game.h"
#include "snake.h"

using namespace std;

int main() {
  Game snake_game;
  int input;
  bool game_end = false;
  do {
    input = getch();
    switch (input) {
    case KEY_UP:
      game_end = true;
      break;
    
    case KEY_RIGHT:
      
    default:
      break;
    }
    snake_game.drawSnake();
    napms(500);
  } while(!game_end);

  endwin();
  return 0;
}