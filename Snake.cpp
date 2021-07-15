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

bool Snake::collided(COORD food) const {
  if(head.x == 0 || head.x == max_x - 1 || head.y == 0 || head.y == max_y - 1)
    return true;
  for(int i = 0; i < body.size() - 1; i++) {
    if(food.x == body[i].x && food.y == body[i].y)
      return true;
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

COORD Snake::next_square() const {
  COORD head = this->head;
  if(dir == 'd')
    head.y++;
  else if(dir == 'l')
    head.x--;
  else if(dir == 'r')
    head.x++;
  else if(dir == 'u')
    head.y--;
  return head;
}


