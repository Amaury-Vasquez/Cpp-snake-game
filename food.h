#ifndef FOOD_H
#define FOOD_H

#include "coord.h"
#include "globals.h"

class Food {
  private:
    COORD p;
  
  public:
    Food(int [ROWS][COLUMNS]);
    COORD get_p() const;
};

#endif