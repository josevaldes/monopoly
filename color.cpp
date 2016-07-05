/* Filename: Color.cpp
   Description: Implementation of the custom methods for the color class
*/
#include <iostream>
#include <string>
#include "color.h"

using namespace std;

/* Constructor method */
color::color(int ct, int rt, int ctHous, int hous_1, int hous_2, int hous_3, int hous_4, int htl, string clrName,string n)
             :cost(ct), rent(rt), costHouse(ctHous), house_1(hous_1), house_2(hous_2), house_3(hous_3), house_4(hous_4), 
			  hotel(htl), colorName(clrName), name(n)
{
	houses = 0;
	mortage = cost / 2;
	originalRent = rent;
	fullRent = rent * 2;
	hasHotel = false;
	mortaged = false;
	owned = false;
	category = "COLOR";
}

color::color()
{
	name = "";
}


/*Destructor method*/
color:: ~color(){}

/*
  Method name: allColorRent()
  Description: It changes the rent of a property into its full rent
  Parameters: None
*/
void color::allColorRent(bool flag)
{
	if (flag)
		rent = fullRent;
	else
		rent = originalRent;
}

/*
  Method name: updateRent
  Description: It adds or remove a house of a property, and then updates the 
               rent according to the number of houses left
  Parameters:
     bool buyT_sellF: It is the flag that indicates if we are going to add or remove a house
	                  If true, it will add a house
					  If false, it will remove a house

  */
void color::updateRent(bool justCheck, bool buyT_sellF)
{
	// Checking the boolean flag
	if (!justCheck)
	{
		if (buyT_sellF)
			++houses;     // If true, add a house
		else
			--houses;     // Else, remove a house
	}

	if (houses < 0)   // If the number of houses is negative, round it to zero
		houses = 0;

	// Update the rent according to the number of current houses
	switch (houses)   
	{
	    case 0:
			rent = fullRent;  // If there is none, update the rent to full rent
		    break;

		case 1:
			rent = house_1;   // If the there is one, update the rent according 
			break;            // to the value of one house

		case 2:
			rent = house_2;  // Update to value of 2 houses
			break;
		
		case 3:
			rent = house_3; // Update to value of 3 houses
			break;
		
		case 4:
			rent = house_4; // Update to value of 4 houses
			break;

		default:
			houses = 5;    // If the number of houses is greater than 4, round down to 5
			rent = hotel;  // Update rent to hotel value
	}
	
}

/* 
  Operator methods: It will be based on the name of the property
*/
bool color::operator==(const color & rhs)
{
	return name == rhs.getName();
}

bool color::operator!=(const color & rhs)
{
	return name != rhs.getName();
}