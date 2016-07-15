#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include <queue>
#include "Property.h"
#include "color.h"
#include "railroad.h"
#include "utility.h"
#include "property_database.h"
#include "user.h"
#include "LinkedUser.h"

#define NUM_SPACES 40
#define CHEST_CARDS 16
#define CHANCE_CARDS 15

using namespace std;

class Board;

class Space
{
   friend class Board;

   protected:
      bool call_delete;
      string name;
      int dice;
      

   public:
      Space() {name = "Space"; call_delete = false;}
      virtual ~Space(){}
      virtual string getName() { return name; }
      virtual void action(user* current){}
      virtual void setDice(int d) { dice = d;}
};

class Space_Community_Chest: public Space
{
  // typedef void (Space_Community_Chest CardActions) (user* a);

   protected:
      LinkedUser* users;
      Space* gojailSpace;
      bool isJailCard;
      int currentCard;

      vector<unsigned int> order;

      void AdvanceToGo(user* current);
      void BankError(user* current);
      void DoctorFee(user* current);
      void StockSale(user* current);
      void GetOutJail(user* current);
      void GoToJail(user* current);
      void OperaNight(user* current);
      void FundMatures(user* current);
      void TaxRefund(user* current);
      void LifeInsurance(user* current);
      void HospitalFees(user* current);
      void SchoolFees(user* current);
      void ConsultancyFee(user* current);
      void StreetRepairs(user* current);
      void BeautyContest(user* current);
      void Inheritance(user* current);

   
   public:
      Space_Community_Chest(LinkedUser* players, Space* gojail);
      void action(user* current);
      void setJailCard(bool);
      

};

class Space_Chance : public Space
{
   protected:
      LinkedUser* users;
      Space* gojailSpace;
      bool isJailCard;
      int currentCard;

      vector<unsigned int> order;

      void AdvanceToGo(user* current);
      void AdvanceToIllinois(user* current);
      void AdvanceToCharles(user* current);
      void AdvanceToUtility(user* current);
      void AdvanceToRailroad(user* current);
      void Dividend(user* current);
      void GetOutJail(user* current);
      void GoBack(user* current);
      void GoToJail(user* current);
      void Repairs(user* current);
      void PoorTax(user* current);
      void TripReading(user* current);
      void ToBoardwalk(user* current);
      void Chairman(user* current);
      void LoanMatures(user* current);
   
   public:
      Space_Chance(LinkedUser* players, Space* gojail);
      void action(user* current);
      void setJailCard(bool);
};

class Space_Property : public Space
{
   friend class Board;

   protected:
      Property* this_property;
      user* owner;

   public:
      Space_Property(Property* init);
      void action(user* current);
      void setOwner(user* other) {owner = other;}
};

class Space_Luxury_Tax: public Space
{
   public:
      Space_Luxury_Tax() {name = "Luxury Tax";}
      void action(user* current);
};

class Space_Income_Tax: public Space
{
   public:
      Space_Income_Tax() {name = "Income Tax";}
      void action(user* current);
};

class Space_Jail: public Space
{
   friend class Space_Go_Jail;

   protected:
      map<user*, int> turns_left;
      Space* chest_space;
      Space* chance_space;
   
   public:
      Space_Jail();
      void action(user* current);
};

class Space_Go_Jail: public Space
{   
   protected:
      unsigned int jail_index;
      Space* jail_space;

   public: 
      Space_Go_Jail(unsigned int index, Space*);
      void action(user* current);
};

class Space_Free_Parking: public Space
{
   public:
      Space_Free_Parking() {name = "Free Parking";}
      void action(user* current) {cout << "In " << name << endl;}
};

class Space_Go: public Space
{
   public:
      Space_Go() { name = "Go";}
      void action(user* current);
};


class property_database;

class Board
{
private:
  vector<Space*> board;
  map<Property*, Space*> prop_map;
  LinkedUser* players;
  property_database* DB;
  user* curr_player;
	
	
public:
	explicit Board();
  ~Board();

  unsigned int moveSpace(int, int);
	void displayList();
  Space* getSpace_Name(string);
  Space* getSpace_Index(unsigned int);
  void returnAllProperties();
  void updateProp();
  bool isBankrupt();
  void start_game();
  void test_1();
  void test_2();
  void test_3();
};


#endif
