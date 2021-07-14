#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "coord.h"

class Snake {  
  private:
    std::vector<COORD> body;
    int dir, max_x, max_y;
    COORD head;

  public:
    //Constructor. Receives x, y, max_x and max_y, initializes snake vector with head in (x, y)
    Snake(int, int, int, int);

    // Getters
    std::vector<COORD> get_body() const;
    int get_dir() const;
    COORD get_head() const;
    
    // Setters
    void set_body(std::vector<COORD>);
    void set_dir(int);
    void set_head(COORD);
    
    // Methods
    bool collided(COORD) const;
    void eat();
    COORD next_square() const;
};

#endif