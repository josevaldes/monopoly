#include <iostream>
#include "Board.h"
#include "helping_methods.h" 

Space_Property::Space_Property(Property* init)
{
   this_property = init;
}

void Space_Property::action(user* current)
{
   bool valid_ans = false;
   string ans;

   if(!current->isCPU())
   {
      cout << "Do you want to buy " << this_property->getName() << endl;
      bool answer = yes_no_question(); 
   }

   if(answer && !this_property->isOwned() && current->subtractCurrency(this_property->getCost()))
   {
      this_property->setOwned(true);
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

}
