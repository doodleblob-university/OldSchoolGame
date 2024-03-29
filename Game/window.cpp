//Charles Barry
#include <ncurses.h>
#include "window.h"

Window::Window(WINDOW* _frame, int _height, int _width, int _y, int _x){//Charles Barry
  frame = _frame; width = _width; height = _height; x = _x; y = _y;//assigns variables
  winrefresh();
}
Window::Window(int _height, int _width){//Charles Barry
  frame = NULL; width = _width; height = _height; x = 0; y = 0;
  winrefresh();
}
void Window::winrefresh(){//Charles Barry
  refresh();
  if(frame){
    win = derwin(frame, height,width,y,x);//creates a sub window
    box(win,0,0);
    wrefresh(frame);
  }else{
    win = newwin(height, width, 0,0);//creates a new window
    box(win,0,0);
  }
  wrefresh(win);
}
void Window::resize(int y, int x){//Charles Barry
  wresize(win, y, x);//resize window
}
