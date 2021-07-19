#include <stdlib.h>
#include "Food.h"

Food::Food(int board[ROWS][COLUMNS]) {
  COORD rand;
  do {
    rand.x = std::rand() % (COLUMNS - 1) + 1;
    rand.y = std::rand() % (ROWS - 1) + 1;
  } while(board[rand.y][rand.x] != ' ');
  this->p = rand;
}

COORD Food::get_p() const {
  return this->p;
}