#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "user.h"
#include "helping_methods.h" 
#include "property_database.h"
#include "menu_methods.h"
#include "LinkedUser.h"


Space_Property::Space_Property(Property* init)
{
   this_property = init; 
   name = this_property->getName();
}

void Space_Property::action(user* current)
{
   bool answer = false;

   if(!current->isCPU())
   {
      if(!this_property->isOwned())
      {
         cout << "Do you want to buy " << this_property->getName() << endl;
         answer = yes_no_question(); 
      }
   }

   if(answer && !this_property->isOwned() && current->subtractCurrency(this_property->getCost()))
   {
      this_property->setOwned(true);
      //this_property->setOwner(current->getName());
      owner = current;

      color* color_prop = dynamic_cast<color*>(this_property);
      railroad* rail_prop = dynamic_cast<railroad*>(this_property);
      utility* utility_prop = dynamic_cast<utility*>(this_property);

      if(color_prop != NULL)
      {
         current->addColorProperty(color_prop);
	
      }
      else if (rail_prop != NULL)
      {
         current->addRailroadProperty(rail_prop);
      }
      else
      {
         current->addUtilityProperty(utility_prop);
      }
   }

   if(this_property->isOwned() && current != owner)
   {
      cout << "Paying rent to " << owner->getName() <<endl;
      bool flag = current->subtractCurrency(this_property->getRent());
      current->setDebt(!flag);
      if(flag)
      {
         owner->addCurrency(this_property->getRent());
      }
   }

}

void Space_Luxury_Tax::action(user* current)
{
    bool flag = current->subtractCurrency(75);
    current->setDebt(!flag);
}

void Space_Income_Tax::action(user* current)
{
    bool flag = current->subtractCurrency(200);
    current->setDebt(!flag);
}

void Space_Jail::action(user* current)
{
   bool respond;
   
   if(current->isJailed() && turns_left[current] > 0)
   {
      cout << current->getName() << " In Jail\n";
      if(!current->isCPU())
      {
         cout << "Do you want to to pay $150 to exit or try to get doubles three times\n";
	 cout << "Say yes if you want to pay or say no if you want to try doubles\n";
         respond = yes_no_question();
      }

      if(respond)
      {
         if(current->subtractCurrency(150))
	 {
	    turns_left[current] = 0;
	    current->setJailed(false);
	 }
	 else
	 {
            --turns_left[current];
	 }
      }
      else
      {
         int dice_1;
	 int dice_2;
	 for(unsigned int i = 0; i < 3; ++i)
	 {
  	    dice_1 = (rand() % 6) + 1;
	    dice_2 = (rand() % 6) + 1;
            
	    cout << "Dice 1: " << dice_1 <<endl;
	    cout << "Dice 2: " << dice_2 <<endl;
	    
	    if(dice_1 != dice_2)
	    {              
	       break;
	    }
	 }
	 if(dice_1 == dice_2)
	 {
	    turns_left[current] = 0;
	    current->setJailed(false);
	 }
	 else
	 {
            --turns_left[current];
	 }
	 
      }
   }

   else
   {
      cout << current->getName() << " just visiting\n";
      current->setJailed(false);
   }

}

Space_Go_Jail::Space_Go_Jail(unsigned int index, Space* space)
{
   name = "Go To Jail";
   jail_index = index;
   jail_space = space;
}

void Space_Go_Jail::action(user* current)
{
   current->setJailed(true);
   current->setCurrPos(jail_index);
   Space_Jail* jail = dynamic_cast<Space_Jail*>(jail_space);
   if(jail != NULL)
   {
      jail->turns_left[current] = 3;
   }
   else
   {
      cerr << "ERROR IN DYNAMIC CAST\n";
      exit(EXIT_FAILURE);
   }
}

void Space_Go::action(user* current)
{
   current->addCurrency(200);
}

Board::Board()
{
   players = opening();
   curr_player = players->getCurrent()->getUser();
   DB = new property_database();
   board.resize(NUM_SPACES);
   board[0]  = new Space_Go();
   board[1]  = new Space_Property(DB->colors[0][0]);
   board[2]  = new Space_Free_Parking();
   board[3]  = new Space_Property(DB->colors[0][1]);
   board[4]  = new Space_Income_Tax();
   board[5]  = new Space_Property(DB->rails[0]);
   board[6]  = new Space_Property(DB->colors[1][0]);
   board[7]  = new Space_Free_Parking();
   board[8]  = new Space_Property(DB->colors[1][1]); 
   board[9]  = new Space_Property(DB->colors[1][2]); 
   board[10] = new Space_Jail();
   board[11] = new Space_Property(DB->colors[2][0]); 
   board[12] = new Space_Property(DB->utilities[0]); 
   board[13] = new Space_Property(DB->colors[2][1]); 
   board[14] = new Space_Property(DB->colors[2][2]); 
   board[15] = new Space_Property(DB->rails[1]);
   board[16] = new Space_Property(DB->colors[3][0]); 
   board[17] = new Space_Free_Parking();
   board[18] = new Space_Property(DB->colors[3][1]); 
   board[19] = new Space_Property(DB->colors[3][2]); 
   board[20] = new Space_Free_Parking();
   board[21] = new Space_Property(DB->colors[4][0]); 
   board[22] = new Space_Free_Parking(); 
   board[23] = new Space_Property(DB->colors[4][1]); 
   board[24] = new Space_Property(DB->colors[4][2]); 
   board[25] = new Space_Property(DB->rails[2]); 
   board[26] = new Space_Property(DB->colors[5][0]); 
   board[27] = new Space_Property(DB->colors[5][1]); 
   board[28] = new Space_Property(DB->utilities[1]); 
   board[29] = new Space_Property(DB->colors[5][2]); 
   board[30] = new Space_Go_Jail(10, board[10]); 
   board[31] = new Space_Property(DB->colors[6][0]); 
   board[32] = new Space_Property(DB->colors[6][1]); 
   board[33] = new Space_Free_Parking(); 
   board[34] = new Space_Property(DB->colors[6][2]); 
   board[35] = new Space_Property(DB->rails[3]); 
   board[36] = new Space_Free_Parking(); 
   board[37] = new Space_Property(DB->colors[7][0]); 
   board[38] = new Space_Luxury_Tax();
   board[39] = new Space_Property(DB->colors[7][2]); 

   //board[10] = new Space_Property(DB.colors[3][2]); 
}

Board::~Board()
{
   for(unsigned int i = 0; i < board.size(); ++i)
   {
      delete board[i];
   }
   
   delete DB;
   delete players;
   
}


unsigned int Board::moveSpace(int steps, int curr)
{
   int ite = curr;
   if(steps > 0)
   {
      ite = (ite + steps) % NUM_SPACES;
   }
   else if(steps < 0)
   {
      ite = ite - steps;
      if(ite < 0)
      {
         ite += NUM_SPACES;
      }
   }

   return ite;
}

void Board::displayList()
{
   for(unsigned int i = 0; i < board.size(); ++i)
   {
      cout << board[i]->getName()<<endl;
   }
}

Space* Board::getSpace_Name(string name)
{
   Space* search;
   for(unsigned int i = 0; i < board.size(); ++i)
   {
      if(name == board[i]->getName())
      {
         search = board[i];
	 break;
      }
   }

   return search;
}

Space* Board::getSpace_Index(unsigned int index)
{
   return board[index];
}

void Board::test_1()
{
   int index = 3;
   for(unsigned int i = 0; i < 6; ++i)
   {
      if(index > 5)
      {
         index = 3;
	 players->nextCurrent();
	 curr_player = players->getCurrent()->getUser();
      }
      //int dice = (rand() % 10) + 1;
      //cout << "Dice: " << dice << endl;
      //int index = moveSpace(dice, curr_player->getCurrPos());
      cout << "\nIndex: " << index << endl;
      curr_player->setCurrPos(index);

      Space* curr_space = getSpace_Index(index);
      cerr << curr_space->getName() << endl;
      curr_space->action(curr_player);
      cout << "End\n";
      curr_player->displayBalance();
      ++index;
   }
}

void Board::test_2()
{
   int index = 3;
   curr_player->subtractCurrency(1500);
   for(unsigned int i = 0; i < 6; ++i)
   {
      cout << "Round " << i << endl;
      if(curr_player->isJailed())
      {
         board[3]->action(curr_player);
	 curr_player->displayBalance();
      }
      if(!curr_player->isJailed())
      {
         cout << "Index = " << index <<endl;
	 curr_player->setCurrPos(index);
	 Space* curr_space = getSpace_Index(curr_player->getCurrPos());
	 curr_space->action(curr_player);
	 index = (index + 4) % NUM_SPACES;	 
      }
   }
}
