#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
int main() {
  srand((unsigned) time(NULL));
  for(int i = 0; i < 10; i++)
    cout << rand() % 10 + 1 << endl;
  return 0;
}