#ifndef BOARD_H
#define BOARD_H

#include "Property.h"
#include "color.h"
#include "railroad.h"
#include "utility.h"
#include "property_database.h"
#include "user.h"

class Board;

class Space
{
   friend class Board;

   public:
      Space() {}
      virtual ~Space(){}
      virtual void action(user* current){}
};

class Space_Property : public Space
{
   friend class Board;

   protected:
      Property* this_property;

   public:
      Space_Property(Property* init);
      void action(user* current);
};

class Space_Luxury_Tax: public Space
{
   public:
      Space_Luxury_Tax() {}
      void action(user* current);
};

class Space_Income_Tax: public Space
{
   public:
      Space_Income_Tax() {}
      void action(user* current);
};

class Space_Jail: public Space
{
   public:
      Space_Jail() {}
      void action(user* current);
};

class Space_Go_Jail: public Space
{
   public: 
      Space_Go_Jail() {}
      void action(user* current);
};

class Space_Free_Parking: public Space
{
   public:
      Space_Free_Parking() {}
      void action(user* current) {}
}


class Space_Node
{
	friend class LinkedSpace;

	private:
	  Space this_space;
		Space_Node* next;
		Space_Node* prev;

    public:
		Node();
		explicit Node(Space);
		
		Space* getSpace();
		void setUser(Space);

		Space* getNext();
		void setNext(Space*);
		
}

class Board
{
private:
	Space_Node* head;
	Space_Node* tail;
  property_database DB;
	
	
public:
	explicit Board();

	Space_Node* getHead();
	Space_Node* getTail();
//	Node* getCurrent();
//	void nextCurrent();
//	void prevCurrent();
  Space_Node* moveSpace(int, Space_Node*);
	void addSpace(user);
//	bool removeUser(Node*);
	void createCyclicList();
//	void clearList(LinkedUser*);
	void displayList();
};


#endif
