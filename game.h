#ifndef GAME_H
#define GAME_H


#include <ncurses.h>
#include "food.h"
#include "globals.h"
#include "snake.h"

class Game {
  private:
    int board[ROWS][COLUMNS];
    Food food;
    bool game_end;
    Snake snake;
    WINDOW *win;

  public:
    Game();
    // member initializers
    void init_board();
    void init_game();
    // Setters
    void set_food(Food);
    // methods
    void clean_board();
    void draw();
    void moveSnake(int);
    void play();
    void print_board();
};
#endif