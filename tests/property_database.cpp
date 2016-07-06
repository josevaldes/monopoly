#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "color.h"
#include "railroad.h"
#include "utility.h"
#include "strings.h"
#include "property_database.h"
#include "helping_methods.h"

using namespace std;

property_database::property_database()
{
	colors[0][0] = color(PURPLE_1_COST, PURPLE_1_RENT, PURPLE_1_COST_HOUSE,
		                 PURPLE_1_HOUSE_1, PURPLE_1_HOUSE_2, PURPLE_1_HOUSE_3,
		                 PURPLE_1_HOUSE_4, PURPLE_1_HOTEL, PURPLE, PURPLE_1_NAME);

	colors[0][1] = color(PURPLE_2_COST, PURPLE_2_RENT, PURPLE_2_COST_HOUSE,
		                 PURPLE_2_HOUSE_1, PURPLE_2_HOUSE_2, PURPLE_2_HOUSE_3,
		                 PURPLE_2_HOUSE_4, PURPLE_2_HOTEL, PURPLE, PURPLE_2_NAME);

	colors[0][2] = color();

	colors[1][0] = color(SKY_1_COST, SKY_1_RENT, SKY_1_COST_HOUSE, SKY_1_HOUSE_1,
		                 SKY_1_HOUSE_2, SKY_1_HOUSE_3, SKY_1_HOUSE_4, SKY_1_HOTEL,
		                 SKY, SKY_1_NAME);
	
	colors[1][1] = color(SKY_2_COST, SKY_2_RENT, SKY_2_COST_HOUSE, SKY_2_HOUSE_1,
		                 SKY_2_HOUSE_2, SKY_2_HOUSE_3, SKY_2_HOUSE_4, SKY_2_HOTEL,
		                 SKY, SKY_2_NAME);
	
	colors[1][2] = color(SKY_3_COST, SKY_3_RENT, SKY_3_COST_HOUSE, SKY_3_HOUSE_1,
		                 SKY_3_HOUSE_2, SKY_3_HOUSE_3, SKY_3_HOUSE_4, SKY_3_HOTEL,
		                 SKY, SKY_3_NAME);
	
	colors[2][0] = color(MAGENTA_1_COST, MAGENTA_1_RENT, MAGENTA_1_COST_HOUSE,
		                 MAGENTA_1_HOUSE_1, MAGENTA_1_HOUSE_2, MAGENTA_1_HOUSE_3,
		                 MAGENTA_1_HOUSE_4, MAGENTA_1_HOTEL, MAGENTA, MAGENTA_1_NAME);
	
	colors[2][1] = color(MAGENTA_2_COST, MAGENTA_2_RENT, MAGENTA_2_COST_HOUSE,
	    	             MAGENTA_2_HOUSE_1, MAGENTA_2_HOUSE_2, MAGENTA_2_HOUSE_3,
		                 MAGENTA_2_HOUSE_4, MAGENTA_2_HOTEL, MAGENTA, MAGENTA_2_NAME);
	
	colors[2][2] = color(MAGENTA_3_COST, MAGENTA_3_RENT, MAGENTA_3_COST_HOUSE,
		                 MAGENTA_3_HOUSE_1, MAGENTA_3_HOUSE_2, MAGENTA_3_HOUSE_3,
		                 MAGENTA_3_HOUSE_4, MAGENTA_3_HOTEL, MAGENTA, MAGENTA_3_NAME);
	
	colors[3][0] = color(ORANGE_1_COST, ORANGE_1_RENT, ORANGE_1_COST_HOUSE,
		                 ORANGE_1_HOUSE_1, ORANGE_1_HOUSE_2, ORANGE_1_HOUSE_3,
		                 ORANGE_1_HOUSE_4, ORANGE_1_HOTEL, ORANGE, ORANGE_1_NAME);
	
	colors[3][1] = color(ORANGE_2_COST, ORANGE_2_RENT, ORANGE_2_COST_HOUSE,
		                 ORANGE_2_HOUSE_1, ORANGE_2_HOUSE_2, ORANGE_2_HOUSE_3,
		                 ORANGE_2_HOUSE_4, ORANGE_2_HOTEL, ORANGE, ORANGE_2_NAME);

	colors[3][2] = color(ORANGE_3_COST, ORANGE_3_RENT, ORANGE_3_COST_HOUSE,
		                 ORANGE_3_HOUSE_1, ORANGE_3_HOUSE_2, ORANGE_3_HOUSE_3,
		                 ORANGE_3_HOUSE_4, ORANGE_3_HOTEL, ORANGE, ORANGE_3_NAME);
	
	colors[4][0] = color(RED_1_COST, RED_1_RENT, RED_1_COST_HOUSE,
		                 RED_1_HOUSE_1, RED_1_HOUSE_2, RED_1_HOUSE_3,
		                 RED_1_HOUSE_4, RED_1_HOTEL, RED, RED_1_NAME);
	
	colors[4][1] = color(RED_2_COST, RED_2_RENT, RED_2_COST_HOUSE,
		                 RED_2_HOUSE_1, RED_2_HOUSE_2, RED_2_HOUSE_3,
		                 RED_2_HOUSE_4, RED_2_HOTEL, RED, RED_2_NAME);
	
	colors[4][2] = color(RED_3_COST, RED_3_RENT, RED_3_COST_HOUSE,
		                 RED_3_HOUSE_1, RED_3_HOUSE_2, RED_3_HOUSE_3,
		                 RED_3_HOUSE_4, RED_3_HOTEL, RED, RED_3_NAME);
	
	colors[5][0] = color(YELLOW_1_COST, YELLOW_1_RENT, YELLOW_1_COST_HOUSE,
		                 YELLOW_1_HOUSE_1, YELLOW_1_HOUSE_2, YELLOW_1_HOUSE_3,
		                 YELLOW_1_HOUSE_4, YELLOW_1_HOTEL, YELLOW, YELLOW_1_NAME);
	
	colors[5][1] = color(YELLOW_2_COST, YELLOW_2_RENT, YELLOW_2_COST_HOUSE,
		                 YELLOW_2_HOUSE_1, YELLOW_2_HOUSE_2, YELLOW_2_HOUSE_3,
		                 YELLOW_2_HOUSE_4, YELLOW_2_HOTEL, YELLOW, YELLOW_2_NAME);

	colors[5][2] = color(YELLOW_3_COST, YELLOW_3_RENT, YELLOW_3_COST_HOUSE,
		                 YELLOW_3_HOUSE_1, YELLOW_3_HOUSE_2, YELLOW_3_HOUSE_3,
		                 YELLOW_3_HOUSE_4, YELLOW_3_HOTEL, YELLOW, YELLOW_3_NAME);
	
	colors[6][0] = color(GREEN_1_COST, GREEN_1_RENT, GREEN_1_COST_HOUSE,
		                 GREEN_1_HOUSE_1, GREEN_1_HOUSE_2, GREEN_1_HOUSE_3,
		                 GREEN_1_HOUSE_4, GREEN_1_HOTEL, GREEN, GREEN_1_NAME);

	colors[6][1] = color(GREEN_2_COST, GREEN_2_RENT, GREEN_2_COST_HOUSE,
 		                 GREEN_2_HOUSE_1, GREEN_2_HOUSE_2, GREEN_2_HOUSE_3,
		                 GREEN_2_HOUSE_4, GREEN_2_HOTEL, GREEN, GREEN_2_NAME);

	colors[6][2] = color(GREEN_3_COST, GREEN_3_RENT, GREEN_3_COST_HOUSE,
		                 GREEN_3_HOUSE_1, GREEN_3_HOUSE_2, GREEN_3_HOUSE_3,
		                 GREEN_3_HOUSE_4, GREEN_3_HOTEL, GREEN, GREEN_3_NAME);

	colors[7][0] = color(BLUE_1_COST, BLUE_1_RENT, BLUE_1_COST_HOUSE,
		                 BLUE_1_HOUSE_1, BLUE_1_HOUSE_2, BLUE_1_HOUSE_3,
		                 BLUE_1_HOUSE_4, BLUE_1_HOTEL, BLUE, BLUE_1_NAME);

	colors[7][1] = color(BLUE_2_COST, BLUE_2_RENT, BLUE_2_COST_HOUSE,
		                 BLUE_2_HOUSE_1, BLUE_2_HOUSE_2, BLUE_2_HOUSE_3,
		                 BLUE_2_HOUSE_4, BLUE_2_HOTEL, BLUE, BLUE_2_NAME);

	colors[7][2] = color();

	rails[0] = railroad(RAILROAD_1_NAME);

	rails[1] = railroad(RAILROAD_2_NAME);

	rails[2] = railroad(RAILROAD_3_NAME);

	rails[3] = railroad(RAILROAD_4_NAME);

	utilities[0] = utility(UTILITY_1_NAME);

	utilities[1] = utility(UTILITY_2_NAME);

}

color property_database::getColorProperty(string colorName)
{
	int propertyIndex;
	int colorIndex;
	bool validColor;
	int numProperty = 3;
	string ans;

	colorIndex = categoryColor(colorName);

	validColor = false;

	do
	{
		cout << "Choose the appropiate property by pressing its number and press enter" << endl;
		cout << "(If there is no available property, just write exit)" << endl;
		
		for (int i = 0; i < numProperty; ++i)
		{
			if (colors[colorIndex][i].isOwned() == false)
				cout << (i + 1) << ". " << colors[colorIndex][i].getName() << endl;
		}
		
		getline(cin, ans);
		
		propertyIndex = strToInt(ans);
		--propertyIndex;

		if (propertyIndex == -1)
		{
			cerr << "No property available" << endl;
			return color();
		}

		if (propertyIndex >= 0 && propertyIndex < 3 &&
			colors[colorIndex][propertyIndex].isOwned() == false)
		{
			validColor = true;
			colors[colorIndex][propertyIndex].setOwned(true);
		}
		
		if (!validColor)
		    cerr << "Your election wasn't a valid one" << endl;

	} while (!validColor);

	return colors[colorIndex][propertyIndex];
}

railroad property_database::getRailroadProperty()
{
	string ans;
	int propertyIndex;
	bool validRail = false;
    
	do
	{
	    cout << "Choose the appropiate property by pressing its number and press enter" << endl;
		cout << "(If there is no available property, write exit)" << endl;

	    for (int i = 0; i < 4; ++i)
	    {
		    if (rails[i].isOwned() == false)
			    cout << (i + 1) << ". " << rails[i].getName() << endl;
	    }

	    getline(cin, ans);

   	    propertyIndex = strToInt(ans);
	    --propertyIndex;

		if (propertyIndex == -1)
		{
			cerr << "No property available" << endl;
			return railroad();
		}
	   
		if (propertyIndex >= 0 && propertyIndex < 4 &&
		    rails[propertyIndex].isOwned() == false)
	    {
		    validRail = true;
		    rails[propertyIndex].setOwned(true);
	    }

	    if (!validRail)
		    cerr << "Your number wasn't a valid one" << endl;

        } while (!validRail);

	return rails[propertyIndex];
}

utility property_database::getUtilityProperty()
{
	string ans;
	int propertyIndex;
	bool validUtility = false;

	do
	{
		cout << "Choose the appropiate property by pressing its number and press enter" << endl;
		cout << "(If there is no available property, just write exit)" << endl;

		for (int i = 0; i < 2; ++i)
		{
			if (utilities[i].isOwned() == false)
				cout << (i + 1) << ". " << utilities[i].getName() << endl;
		}

		getline(cin, ans);

		propertyIndex = strToInt(ans);
		--propertyIndex;

		if (propertyIndex == -1)
		{
			cerr << "No property available" << endl;
			return utility();
		}

		if (propertyIndex >= 0 && propertyIndex < 2 &&
			utilities[propertyIndex].isOwned() == false)
		{
			validUtility = true;
			utilities[propertyIndex].setOwned(true);
		}

		if (!validUtility)
			cerr << "Your number wasn't a valid one" << endl;

	} while (!validUtility);

	return utilities[propertyIndex];
}

void property_database::returnColorProperty(color colorProperty)
{
	int colorIndex = categoryColor(colorProperty.getColor());
	int numProperties = 3;
	
	if (colorIndex == 0 || colorIndex == 7)
		numProperties = 2;

	for (int i = 0; i < numProperties; ++i)
	{
		if (colorProperty == colors[colorIndex][i])
			colors[colorIndex][i].setOwned(false);
	}
}

void property_database::returnRailroadProperty(railroad railroadProperty)
{
	int numProperties = 4;
	for (int i = 0; i < numProperties; ++i)
	{
		if (railroadProperty == rails[i])
			rails[i].setOwned(false);
	}
}

void property_database::returnUtilityProperty(utility utilityProperty)
{
	int numProperties = 2;
	for (int i = 0; i < numProperties; ++i)
	{
		if (utilityProperty == utilities[i])
			utilities[i].setOwned(false);
	}
}

