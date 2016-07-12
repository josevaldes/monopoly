#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include "Property.h"
#include "color.h"
#include "railroad.h"
#include "utility.h"
#include "property_database.h"
#include "user.h"
#include "LinkedUser.h"

#define NUM_SPACES 40

class Board;

class Space
{
   friend class Board;

   protected:
      string name;

   public:
      Space() {}
      virtual ~Space(){}
      virtual string getName() { return name; }
      virtual void action(user* current){}
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
   
   public:
      Space_Jail() {name = "Jail";}
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
      void action(user* current) {}
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
  void test_1();
  void test_2();
};


#endif
