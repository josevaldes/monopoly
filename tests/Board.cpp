#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "strings.h"
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
   owner = nullptr;
}

void Space_Property::action(user* current)
{
   cout << "In " << name << endl;
   bool answer = false;

   if(!current->isCPU())
   {  
      string n = owner == nullptr? "UNOWNED" : "OWNED";
      cout << n << endl;

      if(owner == nullptr)
      {
         cout << "Do you want to buy " << this_property->getName() << endl;
         answer = yes_no_question(); 
      }
   }

   if(answer && !this_property->isOwned() && current->subtractCurrency(this_property->getCost()))
   {
      this_property->setOwned(true);
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

   else if(this_property->isOwned() && current != owner)
   {
      cout << "Paying rent to " << owner->getName() <<endl;
      this_property->setChanceFlag(current->getChanceFlag());
      
      utility* prop = dynamic_cast<utility*>(this_property);
      if(prop != NULL)
      {
         prop->setDice(dice);
      }

      int rent = this_property->getRent();
      
      bool flag = current->subtractCurrency(rent);
      
      if(flag)
      {
         owner->addCurrency(rent);
      }
      else
      {
         current->setDebt(true);
	 current->setDebter(owner);
	 current->setDebtCost(rent);	 
      }
      
   }

}

void Space_Luxury_Tax::action(user* current)
{
    cout << "In " << name << endl;
    bool flag = current->subtractCurrency(75);
    if(!flag)
    {
       current->setDebt(true);
       current->setDebtCost(75);
    }
}

void Space_Income_Tax::action(user* current)
{
    cout << "In " << name << endl;
    bool flag = current->subtractCurrency(200);
    if(!flag)
    {
       current->setDebt(true);
       current->setDebtCost(200);
    }
}

Space_Jail::Space_Jail()
{
   name = "Jail";
   //chest_space = chest;
   //chance_space= chance;
}

void Space_Jail::action(user* current)
{
   bool respond;
   
   if(!current->isJailed())
   {
      cout << current->getName() << " just visiting\n";
      current->setJailed(false);
      turns_left[current] = 0;
   }
   
   else if(turns_left[current] == 0)
   {
      current->setJailed(false);
   }

   else if(current->isChestCard())
   {
      cout << "Do you want to use your community chest jail free card?\n";
      respond = yes_no_question();
      if(respond)
      {
         current->setChestCard(false);
	 turns_left[current] = 0;
	 current->setJailed(false);
      }
   }
   
   else if(current->isChanceCard())
   {
      cout << "Do you want to use your Chance jail free card?\n";
      respond = yes_no_question();
      if(respond)
      {
         current->setChanceCard(false);
	 turns_left[current] = 0;
	 current->setJailed(false);
      }
   }
   

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



}

Space_Go_Jail::Space_Go_Jail(unsigned int index, Space* space)
{
   name = "Go To Jail";
   jail_index = index;
   jail_space = space;
}

void Space_Go_Jail::action(user* current)
{
   cout << "In " << name << endl;
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
   cout << "You Passed through GO. Collect $200\n";
   current->addCurrency(200);
}

Space_Chance::Space_Chance(LinkedUser* players, Space* goJail)
{
   name  = "Chance";
   users = players;
   gojailSpace = goJail;
   isJailCard = true;
   currentCard = 0;
   order.resize(CHANCE_CARDS);
   
   
   bool picked[CHANCE_CARDS];
   for(unsigned int i = 0; i < CHANCE_CARDS; ++i)
   {
      picked[i] = false;
   }

   int chosen = rand() % CHANCE_CARDS;
   for(unsigned int i = 0; i < CHANCE_CARDS; ++i)
   {
      while(picked[chosen])
      {
         chosen = rand() % CHANCE_CARDS;
      }
      
      picked[chosen] = true;
      order[i] = chosen;
   }

}

void Space_Chance::setJailCard(bool flag)
{
   isJailCard = flag;
}

void Space_Chance::AdvanceToGo(user* current)
{
   cout << "Advance to Go and collect $200\n";
   current->setCurrPos(0);
}

void Space_Chance::AdvanceToIllinois(user* current)
{
   cout << "Advance to Illinois Ave\n";
   if(current->getCurrPos() == 36)
   {
     cout << "You passed through Go. Collect $200\n";
     current->addCurrency(200);
   }
   current->setCurrPos(24);
}

void Space_Chance::AdvanceToCharles(user* current)
{
   cout << "Advance to St. Charles Place\n";
   if(current->getCurrPos() == 22 || current->getCurrPos() == 36)
   {
     cout << "You passed through Go. Collect $200\n";
     current->addCurrency(200);
   }
   current->setCurrPos(11);
}

void Space_Chance::AdvanceToUtility(user* current)
{
   cout << "Advance to nearest Utility. If unowned you may buy it.\n";
   cout << "If owned, you must pay 10 times the value of current dice.\n";

   if(current->getCurrPos() == 36)
   {
      cout << "You passed through Go. Collect $200\n";
      current->addCurrency(200);
      current->setCurrPos(12);
   }
   else if(current->getCurrPos() == 7)
   {
      current->setCurrPos(12);
   }
   else
   {
      current->setCurrPos(28);
   }
}

void Space_Chance::AdvanceToRailroad(user* current)
{
   cout << "Advance to nearest Railroad. If unowned you may buy it.\n";
   cout << "If owned, you must pay twice the value of current rent.\n";

   if(current->getCurrPos() == 36)
   {
      cout << "You passed through Go. Collect $200\n";
      current->addCurrency(200);
      current->setCurrPos(5);
   }
   else if(current->getCurrPos() == 7)
   {
      current->setCurrPos(15);
   }
   else
   {
      current->setCurrPos(25);
   }
}

void Space_Chance::Dividend(user* current)
{
   cout << "Bank pays you a dividend of $50\n";
   current->addCurrency(50);
}

void Space_Chance::GetOutJail(user* current)
{
   cout << "Got a 'Get Out Of Jail Card'. Kept until needed or sold\n";
   current->setChanceCard(true);
   isJailCard = false;
}

void Space_Chance::GoBack(user* current)
{
   cout << "Go Back 3 spaces\n";
   current->setCurrPos((current->getCurrPos() - 3) % NUM_SPACES);
}

void Space_Chance::GoToJail(user* current)
{
   cout << "Go to Jail.\n";
   gojailSpace->action(current);
}

void Space_Chance::Repairs(user* current)
{
   cout << "Make general reparations on all your property. $25 per house, $100 per hotel.\n";
   int repairCosts = (25 * current->getNumHouses()) + (100 * current->getNumHotels());
   if(!current->subtractCurrency(repairCosts))
   {
      current->setDebt(true);
      current->setDebtCost(repairCosts);
      //future method
   }
}

void Space_Chance::PoorTax(user* current)
{
   cout << "Pay a poor tax of $15\n";
   if(!current->subtractCurrency(15))
   {
      current->setDebt(true);
      current->setDebtCost(15);
      //future method
   }
}

void Space_Chance::TripReading(user* current)
{
   cout << "Take a trip to Reading Railroad\n";
   cout << "You passed through Go. Collect $200\n";
   current->addCurrency(200);
   current->setCurrPos(5);
   current->setChanceFlag(false);
}

void Space_Chance::ToBoardwalk(user* current)
{
   cout << "Take a walk on the Boardwalk\n";
   current->setCurrPos(39);
}

void Space_Chance::Chairman(user* current)
{
   cout << "You have been elected Chairman of the Board. Pay $50 to each player\n";
   users->nextCurrent();
   user* ite = users->getCurrent()->getUser();
   while(ite != current)
   {
      if(current->subtractCurrency(50))
      {
         ite->addCurrency(50);
      }
      else
      {
         current->setDebt(true);
	 current->setDebter(ite);
	 current->setDebtCost(50);
	 if(Menu(current, users, true, true)) 
	 {
            current->inBankrupt();
	    break;
	 }
	 //future method
      }
      users->nextCurrent();
      ite = users->getCurrent()->getUser();
   }
}

void Space_Chance::LoanMatures(user* current)
{
   cout << "Your building and loan matures. Collect $150\n";
   current->addCurrency(150);
}

void Space_Chance::action(user* current)
{
   cout << "In " << name << endl;
   current->setChanceFlag(true);

   if(order[currentCard] == 6 && !isJailCard)
   {
       currentCard = (currentCard + 1) % CHANCE_CARDS;
   }

   switch(order[currentCard])
   {
       case 0:
          AdvanceToGo(current);
	  break;
       
       case 1:
          AdvanceToIllinois(current);
	  break;

       case 2:
          AdvanceToCharles(current);
	  break;
       
       case 3:
          AdvanceToUtility(current);
	  break;
       
       case 4:
          AdvanceToRailroad(current);
	  break;
       
       case 5:
          Dividend(current);
	  break;

       case 6:
          GetOutJail(current);
	  break;

       case 7:
          GoBack(current);
	  break;

       case 8:
          GoToJail(current);
	  break;
	
       case 9:
          Repairs(current);
	  break;
       
       case 10:
          PoorTax(current);
	  break;

       case 11:
          TripReading(current);
	  break;
       
       case 12:
          ToBoardwalk(current);
	  break;

       case 13:
          Chairman(current);
	  break;

       case 14:
          LoanMatures(current);
	  break;
   }

   currentCard = (currentCard + 1) % CHANCE_CARDS;
}

Space_Community_Chest::Space_Community_Chest(LinkedUser* players, Space* goJail)
{
   name  = "Community Chest";
   users = players;
   gojailSpace = goJail;
   isJailCard = true;
   currentCard = 0;
   order.resize(CHEST_CARDS);
   
   
   bool picked[CHEST_CARDS];
   for(unsigned int i = 0; i < CHEST_CARDS; ++i)
   {
      picked[i] = false;
   }

   int chosen = rand() % CHEST_CARDS;
   for(unsigned int i = 0; i < CHEST_CARDS; ++i)
   {
      while(picked[chosen])
      {
         chosen = rand() % CHEST_CARDS;
      }
      
      picked[chosen] = true;
      order[i] = chosen;
   }

}

void Space_Community_Chest::setJailCard(bool flag)
{
   isJailCard = flag;
}

void Space_Community_Chest::AdvanceToGo(user* current)
{
   cout << "Advance to Go and collect $200\n";
   current->setCurrPos(0);
}

void Space_Community_Chest::BankError(user* current)
{
   cout << "Bank error in your favor, collect $200\n";
   current->addCurrency(200);
}

void Space_Community_Chest::DoctorFee(user* current)
{
   cout << "Doctor's fee. Pay $50\n";
   if(!current->subtractCurrency(50))
   {
      current->setDebt(true);
      current->setDebtCost(50);
      //future method
   }
}

void Space_Community_Chest::StockSale(user* current)
{
   cout << "From sale of stocks you get $45\n";
   current->addCurrency(45);
}

void Space_Community_Chest::GetOutJail(user* current)
{
   cout << "Got a 'Get Out Of Jail Card'. Kept until needed or sold\n";
   current->setChestCard(true);
   isJailCard = false;
}

void Space_Community_Chest::GoToJail(user* current)
{
   cout << "Go to Jail.\n";
   gojailSpace->action(current);
}


void Space_Community_Chest::OperaNight(user* current)
{
   cout << "Grand Opera Night Opening. Collect $50 from each player\n";
   users->nextCurrent();
   user* ite = users->getCurrent()->getUser();
   while(ite != current)
   {
      if(ite->subtractCurrency(50))
      {
         current->addCurrency(50);
      }
      else
      {
         ite->setDebt(true);
	 ite->setDebter(current);
	 ite->setDebtCost(50);
	 if(Menu(ite, users, true, true)) //Last param doesn't matter when 3rd is true
	 {
            ite->inBankrupt();
	    break;
	 }
	 //future method
      }
      users->nextCurrent();
      ite = users->getCurrent()->getUser();
   }
}


void Space_Community_Chest::FundMatures(user* current)
{
   cout << "Xmas. Fund Matures. Collect $100";
   current->addCurrency(100);
}


void Space_Community_Chest::TaxRefund(user* current)
{
   cout << "Income Tax Refund. Collect $20\n";
   current->addCurrency(20);
}

void Space_Community_Chest::LifeInsurance(user* current)
{
   cout << "Life Insurance Mature. Collect $100\n";
   current->addCurrency(100);
}

void Space_Community_Chest::HospitalFees(user* current)
{
   cout << "Pay Hospital fees of $100.\n";
   if(!current->subtractCurrency(100))
   {
      current->setDebt(true);
      current->setDebtCost(100);
      //future method
   }
}

void Space_Community_Chest::SchoolFees(user* current)
{
   cout << "Pay School Fees of $150\n";
   if(!current->subtractCurrency(150))
   {
      current->setDebt(true);
      current->setDebtCost(150);
      //future method
   }
}

void Space_Community_Chest::ConsultancyFee(user* current)
{
   cout << "Receive $25 consultancy fee.\n";
   current->addCurrency(25);
}

void Space_Community_Chest::StreetRepairs(user* current)
{
   cout << "You are assessed for street repairs. $40 per house, $115 per hotel.\n";
   int repairCosts = (40 * current->getNumHouses()) + (115 * current->getNumHotels());
   if(!current->subtractCurrency(repairCosts))
   {
      current->setDebt(true);
      current->setDebtCost(repairCosts);
      //future method
   }
}

void Space_Community_Chest::BeautyContest(user* current)
{
   cout << "Won second prize in beauty contest. Collect $10\n";
   current->addCurrency(10);
}

void Space_Community_Chest::Inheritance(user* current)
{
   cout << "You inherit $100\n";
   current->addCurrency(100);
}

void Space_Community_Chest::action(user* current)
{
   cout << "In " << name << endl;

   if(order[currentCard] == 4 && !isJailCard)
   {
       currentCard = (currentCard + 1) % CHEST_CARDS;
   }

   switch(order[currentCard])
   {
       case 0:
          AdvanceToGo(current);
	  break;
       
       case 1:
          BankError(current);
	  break;

       case 2:
          DoctorFee(current);
	  break;
       
       case 3:
          StockSale(current);
	  break;
       
       case 4:
          GetOutJail(current);
	  break;
       
       case 5:
          GoToJail(current);
	  break;

       case 6:
          OperaNight(current);
	  break;

       case 7:
          FundMatures(current);
	  break;

       case 8:
          TaxRefund(current);
	  break;
	
       case 9:
          LifeInsurance(current);
	  break;
       
       case 10:
          HospitalFees(current);
	  break;

       case 11:
          SchoolFees(current);
	  break;

       case 12:
          ConsultancyFee(current);
	  break;

       case 13:
          StreetRepairs(current);
	  break;

       case 14:
          BeautyContest(current);
	  break;

       case 15:
          Inheritance(current);
	  break;
   }
   
   currentCard = (currentCard + 1) % CHEST_CARDS;
}

Board::Board()
{
   players = opening();
   curr_player = players->getCurrent()->getUser();
   DB = new property_database();
   
   
   board.resize(NUM_SPACES);
   board[0]  = new Space_Go();
   board[1]  = new Space_Property(DB->colors[0][0]);
   board[10] = new Space_Jail();
   board[30] = new Space_Go_Jail(10, board[10]); 
   board[2]  = new Space_Community_Chest(players, board[30]);
   board[3]  = new Space_Property(DB->colors[0][1]);
   board[4]  = new Space_Income_Tax();
   board[5]  = new Space_Property(DB->rails[0]);
   board[6]  = new Space_Property(DB->colors[1][0]);
   board[7]  = new Space_Chance(players, board[30]);
   board[8]  = new Space_Property(DB->colors[1][1]); 
   board[9]  = new Space_Property(DB->colors[1][2]); 

   board[11] = new Space_Property(DB->colors[2][0]); 
   board[12] = new Space_Property(DB->utilities[0]); 
   board[13] = new Space_Property(DB->colors[2][1]); 
   board[14] = new Space_Property(DB->colors[2][2]); 
   board[15] = new Space_Property(DB->rails[1]);
   board[16] = new Space_Property(DB->colors[3][0]); 
   board[17] = board[2];
   board[18] = new Space_Property(DB->colors[3][1]); 
   board[19] = new Space_Property(DB->colors[3][2]); 
   board[20] = new Space_Free_Parking();
   board[21] = new Space_Property(DB->colors[4][0]); 
   board[22] = board[7]; 
   board[23] = new Space_Property(DB->colors[4][1]); 
   board[24] = new Space_Property(DB->colors[4][2]); 
   board[25] = new Space_Property(DB->rails[2]); 
   board[26] = new Space_Property(DB->colors[5][0]); 
   board[27] = new Space_Property(DB->colors[5][1]); 
   board[28] = new Space_Property(DB->utilities[1]); 
   board[29] = new Space_Property(DB->colors[5][2]); 
   board[31] = new Space_Property(DB->colors[6][0]); 
   board[32] = new Space_Property(DB->colors[6][1]); 
   board[33] = board[2]; 
   board[34] = new Space_Property(DB->colors[6][2]); 
   board[35] = new Space_Property(DB->rails[3]); 
   board[36] = board[7]; 
   board[37] = new Space_Property(DB->colors[7][0]); 
   board[38] = new Space_Luxury_Tax();
   board[39] = new Space_Property(DB->colors[7][1]); 

   prop_map[DB->colors[0][0]] = board[1];
   prop_map[DB->colors[0][1]] = board[3];
   prop_map[DB->rails[0]]     = board[5];
   prop_map[DB->colors[1][0]] = board[6];
   prop_map[DB->colors[1][1]] = board[8];
   prop_map[DB->colors[1][2]] = board[9];
   prop_map[DB->colors[2][0]] = board[11];
   prop_map[DB->colors[2][1]] = board[13];
   prop_map[DB->colors[2][2]] = board[14];
   prop_map[DB->colors[3][0]] = board[16];
   prop_map[DB->colors[3][1]] = board[18];
   prop_map[DB->colors[3][2]] = board[19];
   prop_map[DB->colors[4][0]] = board[21];
   prop_map[DB->colors[4][1]] = board[23];
   prop_map[DB->colors[4][2]] = board[24];
   prop_map[DB->colors[5][0]] = board[26];
   prop_map[DB->colors[5][1]] = board[27];
   prop_map[DB->colors[5][2]] = board[29];
   prop_map[DB->colors[6][0]] = board[31];
   prop_map[DB->colors[6][1]] = board[32];
   prop_map[DB->colors[6][2]] = board[34];
   prop_map[DB->colors[7][0]] = board[37];
   prop_map[DB->colors[7][1]] = board[39];
   prop_map[DB->rails[1]]     = board[15];
   prop_map[DB->rails[2]]     = board[25];
   prop_map[DB->rails[3]]     = board[35];
   prop_map[DB->utilities[0]] = board[12];
   prop_map[DB->utilities[1]] = board[28];

}


Board::~Board()
{
   for(unsigned int i = 0; i < board.size(); ++i)
   {
      if(i != 17 && i!= 22 && i != 33 && i != 36)
      {
         delete board[i];
      }
   }

   delete DB;
   delete players;
}

void Board::updateProp()
{
   user* ite = players->getCurrent()->getUser();
   do
   {
    if(ite->recentlyFlag)
    {
       while(!ite->recently.empty())
       {
          Space_Property* prop = dynamic_cast<Space_Property*>(prop_map[ite->recently.front()]);
          assert(prop != NULL);
          prop->owner = ite;
          ite->recently.pop();
       }

       ite->recentlyFlag = false;
    }

    players->nextCurrent();
    ite = players->getCurrent()->getUser();
   } while(ite != curr_player);

}

void Board::returnAllProperties()
{
   user* current = curr_player;
   vector<color*> colorTemp;
   vector<railroad*> railTemp;
   vector<utility*> utilityTemp;

   string currentColor[] = { PURPLE, SKY, MAGENTA, ORANGE, RED, YELLOW, GREEN, BLUE };

   for (int i = 0; i < 8; ++i)
   {
      colorTemp = current->getColorProperties(currentColor[i]);

      for (int j = 0; j < colorTemp.size(); ++j)
      {
         colorTemp[j]->setMortage(false);
	 colorTemp[j]->setOwned(false);
	 current->removeColorProperty(colorTemp[j]);
	 Space_Property* prop_space = dynamic_cast<Space_Property*>(prop_map[colorTemp[j]]);
	 assert(prop_space != NULL);
	 prop_space->owner = nullptr;
      }
   }

   railTemp = current->getRailroadProperties();
   for (int i = 0; i < railTemp.size(); ++i)
   {
      railTemp[i]->setMortage(false);
      railTemp[i]->setOwned(false);
      current->removeRailroadProperty(railTemp[i]);
      Space_Property* prop_space = dynamic_cast<Space_Property*>(prop_map[railTemp[i]]);
      assert(prop_space != NULL); 
      prop_space->owner = nullptr;
   }

   utilityTemp = current->getUtilityProperties();
   for (int i = 0; i < utilityTemp.size(); ++i)
   {
      utilityTemp[i]->setMortage(false);
      utilityTemp[i]->setOwned(false);
      current->removeUtilityProperty(utilityTemp[i]);
      Space_Property* prop_space = dynamic_cast<Space_Property*>(prop_map[utilityTemp[i]]);
      assert(prop_space != NULL); 
      prop_space->owner = nullptr;
   }
}



unsigned int Board::moveSpace(int steps, int curr)
{
   int ite = curr;
   if(steps > 0)
   {
      ite += steps;
      if(ite > NUM_SPACES)
      {
         board[0]->action(curr_player);
      }
      ite = ite % NUM_SPACES;
   }
   else if(steps < 0)
   {
      ite = ite - steps;

      if(ite < 0)
      {
         board[0]->action(curr_player);
	 ite += NUM_SPACES;
      }
   }

   curr_player->setCurrPos(ite);
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
bool Board::isBankrupt()
{
   updateProp();
   if(curr_player->inDebt && !curr_player->bankrupt)
   {
      if(Menu(curr_player, players, true, true)) // Last parameter doesn't matter
      {
         curr_player->inBankrupt();
	 updateProp();
      }
   }

   if(curr_player->bankrupt)
   {
       returnAllProperties();
       players->removeUser(players->getCurrent());
       curr_player = players->getCurrent()->getUser();
       return true;
   }
   else
   {
      return false;
   }
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
      curr_player->setCurrPos(index);

      Space* curr_space = getSpace_Index(index);
      cerr << curr_space->getName() << endl;
      curr_space->action(curr_player);
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

void Board::test_3()
{
   int index;
   string str;
   curr_player->subtractCurrency(1400);
   do
   { 
      bool flag_1 = curr_player->isChestCard();
      bool flag_2 = curr_player->isChanceCard();

      if(curr_player->isJailed())
      {
         board[10]->action(curr_player);
      }
      
      if(flag_1 && !curr_player->isChestCard())
      {
         dynamic_cast<Space_Community_Chest*>(board[2])->setJailCard(true);
      }

      if(flag_2 && !curr_player->isChanceCard())
      {
         dynamic_cast<Space_Chance*>(board[7])->setJailCard(true);   
      }

      if(!curr_player->isJailed())
      {
      //   moveSpace(moves[index], curr_player->getCurrPos());
         cout << "Do you want to buy?\n";
	 if(yes_no_question())
	 {
            buySellProperty(curr_player, players);
	    updateProp();
	 }

	 cout << "Where you want to go\n";
         getline(cin, str);
         index = strToInt(str) % NUM_SPACES;
         
	 curr_player->setCurrPos(index);
	 int new_pos = curr_player->getCurrPos();
	 cerr << "In " << board[curr_player->getCurrPos()]->getName() << endl;
	 
	 board[curr_player->getCurrPos()]->setDice(index);
	 board[curr_player->getCurrPos()]->action(curr_player);

         if(isBankrupt())
	 {
            continue;
	 }

	 if(curr_player->getCurrPos() != new_pos && curr_player->getCurrPos() != 10)
	 {
	    cerr << "In " << board[curr_player->getCurrPos()]->getName() << endl;
	    board[curr_player->getCurrPos()]->setDice(index);
	    board[curr_player->getCurrPos()]->action(curr_player);
	 }
	 curr_player->setChanceFlag(false);

         if(isBankrupt())
	 {
            continue;
	 }
      }
      
      curr_player->displayBalance();

      cout << "Do you want to change player?\n";
      if(yes_no_question())
      {
         players->nextCurrent();
	 curr_player = players->getCurrent()->getUser();
      }

      cout << "Do you want to continue\n";
   }while(yes_no_question());
}


void Board::start_game()
{
   int doubles = 0;
   while(players->getCurrent() != players->getCurrent()->getNext())
   {
      ClearScreen();
      int dice_1;
      int dice_2;
      bool dice_throwed = false;

      bool flag_1 = curr_player->isChestCard();
      bool flag_2 = curr_player->isChanceCard();

      if(curr_player->isJailed())
      {
         board[10]->action(curr_player);
      }
      
      if(flag_1 && !curr_player->isChestCard())
      {
         dynamic_cast<Space_Community_Chest*>(board[2])->setJailCard(true);
      }

      if(flag_2 && !curr_player->isChanceCard())
      {
         dynamic_cast<Space_Chance*>(board[7])->setJailCard(true);   
      }
      
      if(Menu(curr_player, players, false, false))
      {
         curr_player->bankrupt = true;
      }

      if(isBankrupt())
      {
	 continue;
      }

      if(!curr_player->isJailed())
      {
         //dice_1 = (rand() % 6) + 1;
         //dice_2 = (rand() % 6) + 1;
	 
	 string ans;
	 cout << "Getting dice 1\n";
	 getline(cin, ans);
	 dice_1 = strToInt(ans);
	 cout << "Getting dice 2\n";
	 getline(cin, ans);
	 dice_2 = strToInt(ans);
         
	 int move   = dice_1 + dice_2;
         dice_throwed = true;

	 cout << "Dice 1: " << dice_1 << endl;
	 cout << "Dice 2: " << dice_2 << endl;
       
         doubles = dice_1 == dice_2 ? (doubles + 1) : doubles;
	 if(doubles == 3)
	 {
            string ans;
	    board[30]->action(curr_player);
            players->nextCurrent();
	    curr_player = players->getCurrent()->getUser();
	    doubles = 0;
	    cout << "Going to next turn\n";
	    getline(cin, ans);
	    continue;
	 }
	 unsigned int position = moveSpace(move, curr_player->getCurrPos());

	 board[curr_player->getCurrPos()]->setDice(move);
	 board[curr_player->getCurrPos()]->action(curr_player);

         if(isBankrupt())
	 {
            continue;
	 }

	 if(curr_player->getCurrPos() != position && curr_player->getCurrPos() != 10)
	 {
	    board[curr_player->getCurrPos()]->setDice(move);
	    board[curr_player->getCurrPos()]->action(curr_player);
	 }
	 curr_player->setChanceFlag(false);

         if(isBankrupt())
	 {
            continue;
	 }

	 if(Menu(curr_player, players, false, true))
	 {
            curr_player->bankrupt = true;
	 }

	 if(isBankrupt())
	 {
            continue;
	 }
      }

      if((curr_player->isJailed() && (dice_throwed && dice_1 != dice_2))
      {
         players->nextCurrent();
	 curr_player = players->getCurrent()->getUser();
	 doubles = 0;
      }

   }

   cout << "Congratulations to " << curr_player->getName() <<endl;
   cout << "You won\n";
}
