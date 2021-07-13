#include <stdlib.h>
#include <ctime>

#include "game.h"

Game::Game(): snake(COLUMNS / 2, ROWS / 2, COLUMNS, ROWS), food(board) {
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

void Game::set_food(Food food) {
  this->food = food;
}

void Game::clean_board() {
  std::vector<COORD> body = this->snake.get_body();
  for(int i = 0; i < body.size(); i++) 
    board[body[i].y][body[i].x] = ' ';
}

void Game::draw() {
  std::vector<COORD> body = this->snake.get_body();
  for(int i = 0; i < body.size(); i++)
    board[body[i].y][body[i].x] = '@';
  const COORD p = food.get_p();
  board[p.y][p.x] = '0';
  erase();
  print_board();
  refresh();
}

void Game::moveSnake(int input) {
  std::vector<COORD> tmp;
  clean_board();
  this->snake.move_snake();
  switch (input) {
    case KEY_DOWN:
      this->snake.set_dir('d');
      break;
    case KEY_LEFT:
      this->snake.set_dir('l');
      break;
    case KEY_RIGHT:
      this->snake.set_dir('r');
      break;
    case KEY_UP:
      this->snake.set_dir('u');
      break;
    case KEY_BACKSPACE:
      this->game_end = true;
      break;
    default:
      break;
  }
  if(this->snake.collided())
    this->game_end = true;
  COORD food = this->food.get_p(), head = this->snake.get_head();
  if(food.x == head.x && food.y == head.y) {
    this->snake.eat();
    Food tmp(board);
    set_food(tmp);
  }
}

void Game::print_board() {
  for(int i = 0; i < ROWS; i++) {
    printw("\t\t");
    for(int j = 0; j < COLUMNS; j++)
      printw("%c", this->board[i][j]);
    printw("\n");
  }
}

void Game::play() {
  std::srand((unsigned) time(NULL));
  int input;
  do {
    input = getch();
    this->moveSnake(input);
    this->draw();
    napms(200);
  } while(!this->game_end);
  endwin();
}
