#include "snake.h"

Snake::Snake(int x, int y) {
  COORD tmp = {x, y};
  const int head_x = tmp.x;
  std::vector<COORD> body;
  
  for(tmp.x = head_x - 2; tmp.x < head_x; tmp.x++)
    body.push_back(tmp);
  this->body = body;
  // this->head = tmp;
}

std::vector<COORD> Snake::get_body() {
  return this->body;
}

COORD Snake::get_head() {
  return this->head;
}

// void Snake::set_head(COORD tmp) {

// }

// void Snake::set_body(std::vector<COORD> body) {
//   this->body = body;
// }

// void Snake::set_head(COORD head) {
//   this->head = head;
// }