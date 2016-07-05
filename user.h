/*
 * Class name: user
 * Description: Representation of the player that will be interacting with 
 *              the game
 */
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "color.h"
#include "railroad.h"
#include "utility.h"

using namespace std;

class user
{
    private:
		bool allPurple;
		bool allSky;
		bool allMagenta;
		bool allOrange;
		bool allRed;
		bool allYellow;
		bool allGreen;
		bool allBlue;
		
		bool inDebt; // Boolean that will indicate if the user is in debt with
		             // someone else
		
		int currency; // The ammount of currency that the player has
		
		string player; // The name of the player
		
		// Vectors that will be storing the properties of the user
		vector<color> purple;  
		vector<color> sky;
		vector<color> magenta;
		vector<color> orange;
		vector<color> red;
		vector<color> yellow;
		vector<color> green;
		vector<color> blue;

		vector<railroad> rails;

		vector<utility> utilities;

    public:
		explicit user(string);   // Constructor
		user(); // Default constructor

		~user(){} // Destructor

		string getName() const       // Name accessor
		{
			return player;
		}

		int getCurrency() const     // Currency accessor
		{
			return currency;
		}

		bool isInDebt() const       // Debt status accessor
		{
			return inDebt;
		}
        
		/* User Methods*/

		void displayBalance(); // It displays the current balance, and properties in possesion

		void setDebt(bool);    // It mutates the status of the debt status

		void updateColorRent(vector<color>&, bool); // It updates the rent of a property without houses


		void addCurrency(int money);     // It adds currency of the player

		bool subtractCurrency(int money); // It subtract currency to the user if the user has enough currency

		void addColorProperty(color);     // It adds a color property to player's repertory

		void removeColorProperty(color);  // It removes a property from player's repertory

		color getColorProperty(string);   // It gives access to one color property of the player

		vector<color> getColorProperties(string); // Get all properties of an specific color

		void addRailroadProperty(railroad);  // Adds a railroad property to player's repertory

		void removeRailroadProperty(railroad); // It removes a railroad property from the user

		railroad getRailroadProperty();        // It gives access to one railroad property

		vector<railroad> getRailroadProperties(); // It gives access to all railroad properties
		
		void addUtilityProperty(utility);         // It adds a utility property

		void removeUtilityProperty(utility);      // It removes a utility property

		utility getUtilityProperty();             // It gives access to one utility property

		vector<utility> getUtilityProperties();   // It gives access to all utility property

		bool hasAnyProperty();

};

#endif USER_H