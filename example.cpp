#include <ncurses.h>

using namespace std;

int main() {
  WINDOW *w;

  int tecla;

  int max_x, max_y, pos_x, pos_y;

  bool fin = false;

  w = initscr();

  keypad(w, TRUE);

  noecho();

  nonl();

  curs_set(0);

  erase();

  getmaxyx(w, max_y, max_x);

  pos_x = max_x / 2;
  pos_y = max_y / 2;

  do
  {
        move(pos_y, pos_x);
        addch('@');
        refresh();

    tecla = getch();

        move(pos_y, pos_x);
        addch(' ');
        refresh();

        switch(tecla)
        {
          case KEY_UP:
             pos_y = (pos_y + (max_y - 1)) % max_y;
             break;
          case KEY_LEFT:
             pos_x = (pos_x + (max_x - 1)) % max_x;
             break;
          case KEY_RIGHT:
             pos_x = (pos_x + 1) % max_x;
             break;
          case KEY_DOWN:
             pos_y = (pos_y + 1) % max_y;
             break;
          case 27: // tecla ESC
             fin = true;
             break;
        }

  }  while (!fin);

  endwin();

  return 0;
}

