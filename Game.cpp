#include <stdlib.h>
#include <ctime>

#include "Game.h"

Game::Game(): snake(COLUMNS / 2, ROWS / 2, COLUMNS, ROWS), food(board) {
  this->init_board();
  this->init_window();
  this->game_end = false;
  this->score = 0;
}

void Game::init_board() {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLUMNS; j++) {
      if(i == 0 || i == ROWS - 1)
        this->board[i][j] = '-';
      else 
        this->board[i][j] = (j == 0 || j == COLUMNS -1)? '|' : ' ';
    }
  }
}

void Game::init_window() {
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

void Game::draw() {
  std::vector<COORD> body = snake.get_body();
  int i;
  for(i = 0; i < body.size() - 1; i++)
    board[body[i].y][body[i].x] = '*';
  board[body[i].y][body[i].x] = '@';
  const COORD p = food.get_p();
  board[p.y][p.x] = '0';
  erase();
  print_board();
  print_score();
  refresh();
}

void Game::gameOver() {
  this->game_end = true;
  char words[2][4] = {{'G', 'A', 'M', 'E'}, {'O', 'V', 'E', 'R'}};
  for(int i = 1, l = 0, k; i < ROWS - 1; i++) {
    k = 0;
    for(int j = 1; j < COLUMNS - 1; j++) { 
      if(j > COLUMNS / 2 - 2 && j <= COLUMNS / 2 + 2 && (i == ROWS / 2 || i == ROWS / 2 + 1)) 
        board[i][j] = words[l][k++];
      else
        board[i][j] = ' ';
    }
    l = k != 0? l + 1 : l;
  }
  erase();
  print_board();
  print_score();
  refresh();
  napms(2000);
}

void Game::moveSnake(int input) {
  update_board();
  switch (input) {
    case KEY_DOWN:
      if(snake.get_dir() != 'u')
        snake.set_dir('d');
      break;
    case KEY_LEFT:
      if(snake.get_dir() != 'r')
        snake.set_dir('l');
      break;
    case KEY_RIGHT:
      if(snake.get_dir() != 'l')
        snake.set_dir('r');
      break;
    case KEY_UP:
      if(snake.get_dir() != 'd')
        snake.set_dir('u');
      break;
    case KEY_BACKSPACE:
      gameOver();
      break;
    default:
      break;
  }

  if(snake.collided(food.get_p()))
    gameOver();

  COORD food = this->food.get_p(), head = snake.get_head();
  if(food.x == head.x && food.y == head.y) {
    this->score++;
    snake.eat();
    Food tmp(board);
    set_food(tmp);
  }
}

void Game::play() {
  std::srand((unsigned) time(NULL));
  int input;
  do {
    input = getch();
    moveSnake(input);
    draw();
    napms(200 - score * 10);
    if(score == 20) 
      gameOver();
  } while(!game_end);
  endwin();
}

void Game::print_board() const {
  for(int i = 0; i < ROWS; i++) {
    printw("\t\t");
    for(int j = 0; j < COLUMNS; j++)
      printw("%c", board[i][j]);
    printw("\n");
  }
}

void Game::print_score() const {
  printw("\t\t\tScore:  %d", score * 10);
}

void Game::update_board() {
  std::vector<COORD> body = snake.get_body();
  int i;
  for(i = 0; i < body.size() - 1; i++) {  
    board[body[i].y][body[i].x] = ' ';
    body[i] = body[i + 1];
  }
  COORD head = snake.next_square();
  body[i] = head;
  snake.set_body(body);
  snake.set_head(head);
}