//Charles Barry
#include <ncurses.h>
#include <string>
#include "terminalfunc.h"

void TerminalFunctions::printTerminalText(std::string text){//Charles Barry
  int y = 1;
  wmove(term, y, 1);//moves cursor to top left corner of the terminal
  for(int i = 0; i < text.length(); ++i){
    char cha = text[i];
    if(cha == '\n'){y += 1; wmove(term, y, 1);}else{//drops down a line when \n
      wprintw(term, "%c", cha);//prints character by character
    }
  }
  wrefresh(term);
}

int TerminalFunctions::centreTextCursorPos(std::string text){//Charles Barry
  return (getWindowWidth() - text.size())/2;
}

std::string TerminalFunctions::getUserInput(){//Charles Barry
  wmove(term, 10, 1);
  wprintw(term, ">");
  std::string userinput;
  for(int i = 1; i < 45; ++i){
    int input = wgetch(term);
    switch(input){
      case 127://if user presses backspace key
        if(userinput.length() > 0){userinput = userinput.substr(0,userinput.length()-1); mvwprintw(term, 10, i, " "); i -= 1; wmove(term, 10, i+1);}
        i -= 1;//delete previous character and remove from display
        break;
      case '\n'://if user presses enter key
        return userinput;
        break;
      default://adds char onto the end of the current string
        userinput = userinput.append(1u, input);
        wprintw(term, "%c", input);
        break;
    }
  }
}

std::string TerminalFunctions::getUserInput(bool secure){//Charles Barry
  wmove(term, 10, 1);
  wprintw(term, ">");
  std::string userinput;
  for(int i = 1; i < 45; ++i){
    int input = wgetch(term);
    switch(input){
      case 127://if user presses backspace key
        if(userinput.length() > 0){userinput = userinput.substr(0,userinput.length()-1); mvwprintw(term, 10, i, " "); i -= 1; wmove(term, 10, i+1);}
        i -= 1;//delete previous character and remove from display
        break;
      case '\n'://if user presses enter key
        return userinput;
        break;
      default://adds char onto the end of the current string
        userinput = userinput.append(1u, input);
        wprintw(term, "*");//prints asterisks as oppose to plaintext
        break;
    }
  }
}

bool TerminalFunctions::getUserYN(){//Charles Barry
  while(true){
    std::string input = getUserInput();
    if(input == "y" || input == "yes" || input == "Y" || input == "YES"){
      return true;
    }else if(input == "n" || input == "no" || input == "N" || input == "NO" || input == ""){
      return false;
    }else{
      printTerminalText("\n\n\n\nSorry, I didn't understand that");
    }
  }
}

void TerminalFunctions::eraseTerminal(){//Charles Barry
  werase(term);//clears terminal and redraws border
  box(term, 0, 0);
  wrefresh(term);
}

TerminalFunctions::TerminalFunctions(WINDOW* _stat, WINDOW* _term, int _windowWidth){//Charles Barry
  stat = _stat; term = _term; windowWidth = _windowWidth;
}
