/* Filename: color.hpp
   Description: Interface for the creation of an color object that represents color properties 
 */
#ifndef COLOR_H
#define COLOR_H

#include <string>
using namespace std;

class color
{
    private:
		int cost;                   // Cost of adquiring the property from the bank
		int rent;                   // Cost of the current rent
		int originalRent;           // Cost of the starting rent
		int fullRent;               // Cost of a rent with all the property colors
		int houses;                 // Number of houses in a property
		int costHouse;              // Cost to build a house
		int mortage;                // Value of the mortage
		int house_1;                // Value of rent with one house
		int house_2;                //  "     "   "   "   two houses
		int house_3;                //  "     "   "   "   three houses
		int house_4;                //  "     "   "   "   four houses
		int hotel;                  //  "     "   "   "   a hotel
		bool hasHotel;              // Status to check if a property has hotel
		bool mortaged;              // Status to check if a property is mortaged
		bool owned;                 // Status to check if the property is owned
		string category;            // Name of the category that this property belongs
		string colorName;           // Type of color of a property
		string name;                // Name of the property

	public:
		explicit color(int, int, int, int, int, int, int, int, string, string); // Constructor
		color();
		~color(); //Destructor

		/* Accessor methods*/

		int getCost() const  // Get the cost of a property
		{
			return cost; 
		}
		
		int getRent() const  // Get the current rent of a property
		{
			return rent;
		}

		int getHouses() const // Get the number of houses of a property
		{
			return houses;
		}

		int getCostHouse() const // Get the cost of building a house 
		{
			return costHouse;
		}

		int getMortage() const // Get the value of the mortage
		{
			return mortage;
		}

		bool getHasHotel() const  // Get the status of a hotel in a property
		{
			return hasHotel;
		}

		bool isOwned() const  // Get the status if a property is owned
		{
			return owned;
		}

		bool isMortaged() const // Get the status of the mortage
		{
			return mortaged;
		}

		string getCategory() const // Get the category string of the property
		{
			return category;
		}

		string getColor() const // Get the Color of the property
		{
			return colorName;
		}

		string getName() const // Get the name of the property
		{
			return name;
		}

		/* Mutator methods */

		void setOwned(bool change) // Change the status of the own 
		{
			owned = change;
		}

		void setMortaged(bool change) // Change the status of the mortage
		{
			mortaged = change;
		}

		/* Custom methods (Details in cpp file) */

		void allColorRent(bool); // Duplicates the original rent 

		void updateRent(bool, bool); //Updates the rent by adding/removing houses

		bool operator==(const color &); // Custom == operator
		bool operator!=(const color &); // Custom != operator

};
#endif COLOR_H