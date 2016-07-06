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
   int cost;
   int rent;
   int mortage;
   string category;
   string name;

   public:
      explicit Property(string n)
      {
         name = n;
      }

      Property()
      {
         name = "";
      }

      ~Property() {}
      
      virtual bool isOwned() const 
      {
         return owned;
      }
      
      virtual bool isMortaged() const
      {
         return mortaged;
      }

      virtual int getCost() const
      {
         return cost;
      }

      virtual int getRent() const
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

      virtual void setMortaged(bool flag)
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
