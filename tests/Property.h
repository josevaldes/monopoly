#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>

using namespace std;

class Property
{
   protected:
   bool owned;
   bool mortaged;
   bool chanceFlag;
   int cost;
   int rent;
   int mortage;
   string category;
   string name;
   string owner;

   public:
      explicit Property(string n)
      {
         name = n;
         owner = "";
         chanceFlag = false;
      }

      Property()
      {
         name = "";
      }

      virtual ~Property() {}
      
      void setChanceFlag(bool flag)
      {
         chanceFlag = flag;
      }

      virtual bool isOwned() const 
      {
         return owned;
      }
      
      virtual string getOwner() const
      {
         return owner;
      }

      virtual void setOwner(string new_owner)
      {
         owner = new_owner;
      }

      virtual bool isMortaged() const
      {
         return mortaged;
      }

      virtual int getCost() const
      {
         return cost;
      }

      virtual int getRent()
      {
         return rent;
      }

      virtual int getMortage() const
      {
         return mortage;
      }
     
      virtual string getCategory() const
      {
         return category;
      }
      
      virtual string getName() const
      {
         return name;
      }

      virtual void setOwned(bool flag)
      {
         owned = flag;
      }

      virtual void setMortage(bool flag)
      {
         mortaged = flag;
      }

      bool operator==(const Property & rhs)
      {
         return name == rhs.getName();
      }

      bool operator!=(const Property & rhs)
      {
         return name != rhs.getName();
      }
};

#endif
