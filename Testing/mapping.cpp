//Charlie Barry
#include <iostream>
#include <ncurses.h>
#include <locale>

using namespace std;

const int width = 40;
const int height = 20;

int playerpos[] = {17,2};

int main(void){
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);
    void printMap(int map[][width]);
    void movement(int map[][width]);

    int map[][width] = {  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0},
                          {0,1,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,1,0,0,1,3,3,3,3,3,3,3,3,1,0},
                          {0,1,3,3,3,3,3,3,3,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,1,3,1,0,0,1,3,3,3,3,3,3,3,3,1,0},
                          {0,1,2,1,1,1,1,3,3,1,0,1,3,3,3,3,3,3,3,3,3,1,0,0,1,3,1,0,0,1,3,3,3,3,3,3,3,3,1,0},
                          {0,1,3,1,0,0,1,3,3,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,3,1,0,0,1,3,3,3,3,3,3,3,3,1,0},
                          {0,1,3,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,1,0,0,1,3,3,3,3,3,3,3,3,1,0},
                          {0,1,2,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,3,1,0,0,1,3,3,3,3,3,3,3,3,1,0},
                          {0,1,3,3,3,3,3,1,0,1,1,1,1,1,1,1,3,3,3,3,3,3,1,0,1,3,1,0,0,1,1,1,1,2,2,1,1,1,1,0},
                          {0,1,3,3,3,3,3,1,0,1,3,3,2,3,3,2,3,1,3,3,1,3,1,0,1,3,1,0,0,0,1,3,3,3,3,3,3,3,1,0},
                          {0,1,3,3,3,3,3,1,0,1,3,6,1,1,1,1,3,3,3,3,3,3,1,1,1,3,1,0,0,0,1,3,3,3,3,3,3,3,1,0},
                          {0,1,1,1,1,1,1,1,0,1,2,1,1,0,0,1,3,1,3,3,1,3,2,3,3,3,1,0,0,0,1,3,3,3,3,3,3,3,1,0},
                          {0,0,0,0,0,0,0,0,0,1,3,1,0,0,0,1,3,3,3,3,3,3,1,1,1,1,1,0,0,0,1,1,1,1,1,1,3,3,1,0},
                          {0,0,0,0,0,0,0,0,0,1,3,1,0,0,0,1,1,1,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,3,3,1,0},
                          {0,0,0,0,0,0,1,1,1,1,2,1,1,1,1,1,0,1,3,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,3,3,1,0},
                          {0,1,1,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,3,1,1,1,1,3,3,3,3,3,3,3,1,0,0,0,0,1,3,3,1,0},
                          {0,1,3,3,2,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,2,3,3,3,3,3,3,3,1,1,1,1,1,1,3,3,1,0},
                          {0,1,3,3,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,2,3,3,2,3,3,3,3,1,0},
                          {0,1,5,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

    while(true){
      printMap(map);
      movement(map);
      clear();
    }
  }

void movement(int map[][width]){
  char keypress;
  keypress = getch();
  try{
    switch(keypress){
      case 'w':
          if(map[playerpos[0]-1][playerpos[1]] == 3 or map[playerpos[0]-1][playerpos[1]] == 4 or map[playerpos[0]-1][playerpos[1]] == 6){
            playerpos[0] -= 1;
          }
          break;
        case 'a':
          if(map[playerpos[0]][playerpos[1]-1] == 3 or map[playerpos[0]][playerpos[1]-1] == 4 or map[playerpos[0]][playerpos[1]-1] == 6){
            playerpos[1] -= 1;
          }
          break;
        case 's':
          if(map[playerpos[0]+1][playerpos[1]] == 3 or map[playerpos[0]+1][playerpos[1]] == 4 or map[playerpos[0]+1][playerpos[1]] == 6){
            playerpos[0] += 1;
          }
          break;
        case 'd':
          if(map[playerpos[0]][playerpos[1]+1] == 3 or map[playerpos[0]][playerpos[1]+1] == 4 or map[playerpos[0]][playerpos[1]+1] == 6){
            playerpos[1] += 1;
          }
          break;
        case 'e':
          void doors( int map[][width]);
          doors(map);
          break;
        default: cout << "";
          break;
        }

    }catch(...){}
  }


void printMap(int map[][width]){
  initscr();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    for (int row = 0; row < height; ++row)
    {
        for (int column = 0; column < width; ++column)
        {
          string terrain;
          switch(map[row][column]){
            case 0:
            attron(COLOR_PAIR(3));
              terrain = "░";
              break;
            case 1:
              attron(COLOR_PAIR(3));
              terrain = "\u2588";
              break;
            case 2:
              attron(COLOR_PAIR(3));
              terrain = "~";
              break;
            case 3:
              terrain = " ";
              break;
            case 4:
              attron(COLOR_PAIR(3));
              terrain = "/";
              break;
            case 5:
              attron(COLOR_PAIR(3));
              terrain = "☰";
              break;
            case 6:
              attron(COLOR_PAIR(5));
              terrain = "⏛";
              break;
          }
          if(playerpos[0] == row && playerpos[1] == column){
            attron(COLOR_PAIR(1));
            terrain = "\u2625";
          }
          printw(terrain.c_str());
          attron(COLOR_PAIR(2));
        }
        printw("\n");
    }
}

void doors( int map[][width]){
  string terrain;
        if(map[playerpos[0]][playerpos[1]+1] == 2){
          terrain = map[playerpos[0]][playerpos[1]+1] = 4;
        }
        else if(map[playerpos[0]+1][playerpos[1]] == 2){
          terrain = map[playerpos[0]+1][playerpos[1]] = 4;
        }
        else if(map[playerpos[0]][playerpos[1]-1] == 2){
          terrain = map[playerpos[0]][playerpos[1]-1] = 4;
        }
        else if(map[playerpos[0]-1][playerpos[1]] == 2){
          terrain = map[playerpos[0]-1][playerpos[1]] = 4;
      } 

      else if(map[playerpos[0]][playerpos[1]+1] == 4){
          terrain = map[playerpos[0]][playerpos[1]+1] = 2;
        }
        else if(map[playerpos[0]+1][playerpos[1]] == 4){
          terrain = map[playerpos[0]+1][playerpos[1]] = 2;
        }
        else if(map[playerpos[0]][playerpos[1]-1] == 4){
          terrain = map[playerpos[0]][playerpos[1]-1] = 2;
        }
        else if(map[playerpos[0]-1][playerpos[1]] == 4){
          terrain = map[playerpos[0]-1][playerpos[1]] = 2;
     }
      
  }
