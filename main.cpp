#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Board.h"
#include "user.h"
#include "LinkedUser.h"
#include "menu_methods.h"
#include "clrscreen_linux.h"

using namespace std;

int main()
{
  clrscreen();
  cout << "Welcome to Command Prompt Monopoly Game\n";
  srand(time(NULL));
  Board board;
  board.start_game();

  return 0;
}
