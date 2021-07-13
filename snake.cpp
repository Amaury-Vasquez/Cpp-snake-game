#include "snake.h"

Snake::Snake(int x, int y, int max_x, int max_y) {
  COORD tmp = {x, y};
  const int head_x = tmp.x;
  std::vector<COORD> body;
  
  for(tmp.x = head_x - 2; tmp.x <= head_x; tmp.x++)
    body.push_back(tmp);
  this->dir = 'r';
  this->body = body;
  tmp.x--;
  this->head = tmp;
  this->max_x = max_x;
  this->max_y = max_y;
}

std::vector<COORD> Snake::get_body() const {
  return this->body;
}

int Snake::get_dir() const {
  return this->dir;
}

COORD Snake::get_head() const {
  return this->head;
}

void Snake::set_body(std::vector<COORD> body) {
  this->body = body;
}

void Snake::set_dir(int dir) {
  this->dir = dir;
}

void Snake::set_head(COORD head) {
  this->head = head;
}

int Snake::backward(int value, int limit) const {
  return value - 1 > 0? value - 1 : limit - 2;
}

int Snake::forward(int value, int limit) const {
  return value + 1 < limit - 1? value + 1 : 1;
}

bool Snake::collided() {
  for(int i = 0; i < body.size() - 1; i++) {
    if(head.x == body[i].x && head.y == body[i].y)
      return true;
  }
  return false;
}

void Snake::eat() {
  COORD head = next_square();
  this->body.push_back(head);
  this->head = head;
}

COORD Snake::next_square() {
  COORD head = this->head;
  switch (dir) {
    case 'd':
      head.y = forward(head.y, max_y);
      break;
    case 'l':
      head.x = backward(head.x, max_x);
      break;
    case 'r':
      head.x = forward(head.x, max_x);
      break;
    case 'u':
      head.y = backward(head.y, max_y);
      break;
    default:
      break;
  }
  return head;
}

void Snake::move_snake() {
  COORD head = next_square();
  int i;
  for(i = 0; i < body.size() - 1; i++)
    body[i] = body[i + 1];
  body[i] = head;
  this->head = head;
}

