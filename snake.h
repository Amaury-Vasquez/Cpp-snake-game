#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

struct COORD{
  int x, y;
};

class Snake {  
  private:
    std::vector<COORD> body;
    COORD head;
  
  public:
    //Constructor. Receives x and y, initializes snake vector with head in (x, y)
    Snake(int, int);
    // Getters
    std::vector<COORD> get_body();
    COORD get_head();
    // // Setters
    // void set_body(std::vector<COORD>);
    // void set_head(COORD);
  
};

#endif