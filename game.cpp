#include "game.h"

Game::Game(): snake(COLUMNS / 2, ROWS / 2) {
  this->init_board();
  this->init_game();
  this->game_end = false;
}

void Game::init_board() {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLUMNS; j++) {
      if(i == 0 || i == ROWS - 1)
        this->board[i][j] = '#';
      else 
        this->board[i][j] = (j == 0 || j == COLUMNS -1)? '#' : ' ';
    }
  }
}

void Game::init_game() {
  // Initialize window
  WINDOW *win = initscr();
  erase();
  noecho();
  nonl();
  keypad(win, TRUE);
  curs_set(0);
  nodelay(win, TRUE);
  scrollok(win, TRUE);
  this->win = win;
}

void Game::drawSnake() {
  std::vector<COORD> body = this->snake.get_body();
  for(int i = 0; i < body.size(); i++) {
    board[body[i].y][body[i].x] = '@';
  }
  erase();
  print_board();
  refresh();
}

void Game::moveSnake(int input) {
  switch (input)
  {
  case KEY_UP:
    this->game_end = TRUE;
    break;
  
  default:
    break;
  }
}
void Game::print_board() {
  for(int i = 0; i < ROWS; i++) {
    // printw("\t\t");
    for(int j = 0; j < COLUMNS; j++)
      printw("%c", this->board[i][j]);
    printw("\n");
  }
}

