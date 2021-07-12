#ifndef GAME_H
#define GAME_H
#define COLUMNS 60
#define ROWS 20

#include <ncurses.h>
#include "snake.h"


class Game {
  private:
    int board[ROWS][COLUMNS];
    bool game_end;
    Snake snake;
    WINDOW *win;

  public:
    Game();
    // member initializers
    void init_board();
    void init_game();
    // methods
    void drawSnake();
    void moveSnake(int);
    void print_board();
};
#endif