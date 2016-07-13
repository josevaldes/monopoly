#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Board.h"
#include "user.h"
#include "LinkedUser.h"
#include "menu_methods.h"

using namespace std;

int main()
{
  srand(time(NULL));
  Board board;
  board.test_3();
  /*
   LinkedUser* players = opening();
   Board board;
   srand(time(NULL));
   
   for(unsigned int i = 0; i < 6; ++i)
   {
      int dice = (rand() % 10) + 1;
      cout <<"Dice: " << dice << endl;
      user* curr = players->getCurrent()->getUser();
      int index = board.moveSpace(dice, curr->getCurrPos());
      curr->setCurrPos(index);
      Space* curr_space = board.getSpace_Index(index);
      curr_space->action(curr);
      curr->displayBalance();
      players->nextCurrent();
   }

   delete players;
  */

   return 0;
}
