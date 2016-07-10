#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "strings.h"
#include "menu_methods.h"
#include "color.h"
#include "railroad.h"
#include "utility.h"
#include "helping_methods.h"

using namespace std;

void buyPropertyToBank(user & buyer, property_database & DB)
{
	int category = getCategory();
	string colorName;
	string ans;
	color* colorSelected;
	railroad* railSelected;
	utility* utilitySelected;

	switch(category)
	{
	case 1:
		cout << "Type the color of the property that you are going to buy" << endl;
		getline(cin, colorName);
		//transform(colorName.begin(), colorName.end(), colorName.begin(), toupper);
                toUpperString(colorName);
		colorSelected = DB.getColorProperty(colorName);
		
		if (colorSelected == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, ans);
			return;
		}

		if (buyer.subtractCurrency(colorSelected->getCost()))
			buyer.addColorProperty(colorSelected);

		break;

	case 2:
		railSelected = DB.getRailroadProperty();

		if (railSelected  == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, ans);
			return;
		}

		if (buyer.subtractCurrency(railSelected->getCost()))
			buyer.addRailroadProperty(railSelected);

		break;

	default:
		utilitySelected = DB.getUtilityProperty();

		if (utilitySelected == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, ans);
			return;
		}

		if (buyer.subtractCurrency(utilitySelected->getCost()))
			buyer.addUtilityProperty(utilitySelected);
	}
}

void buyPropertyToPlayer(user & buyer, user & seller)
{
	int sellerPrice;
	int category = getCategory();
	bool confirmation;
	string colorName;
	string price;
	string ans;
	color* colorSelected;
	railroad* railSelected;
	utility* utilitySelected;


	switch (category)
	{
	case 1:
		cout << "Select the color of the property you want to buy" << endl;
		getline(cin, colorName);
                toUpperString(colorName);
		colorSelected = seller.getColorProperty(colorName);
		
		if (colorSelected == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, ans);
			return;
		}

		do{
			cout << "For how much is sold this property" << endl;
			getline(cin, price);
			sellerPrice = strToInt(price);

			cout << "The asking price is " << sellerPrice << endl
				<< "Do you want to continue with the transaction" << endl
				<< "Yes: I agree with the price " << endl
				<< "No: I want to negotiate the price" << endl
				<< "Cancel: I want to cancel the transaction" << endl;

			getline(cin, ans);

			if (ans[0] == 'Y' || ans[0] == 'y')
			{
				if (buyer.subtractCurrency(sellerPrice))
				{
					buyer.addColorProperty(colorSelected);
					seller.removeColorProperty(colorSelected);
					seller.addCurrency(sellerPrice);
				}

				confirmation = true;
			}

			else if (ans[0] == 'N' || ans[0] == 'n')
				confirmation = false;

			else if (ans[0] == 'C' || ans[0] == 'c')
				return;

			else
			{
				cerr << "Your typed option is not valid, please try again" << endl;
			}

		} while (!confirmation);
		
		break;
	case 2:
		railSelected = seller.getRailroadProperty();

		if (railSelected  == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, ans);
			return;
		}

		do{
			cout << "For how much is sold this property" << endl;
			getline(cin, price);
			sellerPrice = strToInt(price);

			cout << "The asking price is " << sellerPrice << endl
				<< "Do you want to continue with the transaction" << endl
				<< "Yes: I agree with the price " << endl
				<< "No: I want to negotiate the price" << endl
				<< "Cancel: I want to cancel the transaction" << endl;

			getline(cin, ans);

			if (ans[0] == 'Y' || ans[0] == 'y')
			{
				if (buyer.subtractCurrency(sellerPrice))
				{
					buyer.addRailroadProperty(railSelected);
					seller.removeRailroadProperty(railSelected);
					seller.addCurrency(sellerPrice);
				}
				
				confirmation = true;
			}

			else if (ans[0] == 'N' || ans[0] == 'n')
				confirmation = false;

			else if (ans[0] == 'C' || ans[0] == 'c')
				return;

			else
			{
				cerr << "Your typed option is not valid, please try again" << endl;
			}

		} while (!confirmation);

		break;

	case 3:
		utilitySelected = seller.getUtilityProperty();

		if (utilitySelected == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, ans);
			return;
		}

		do{
			cout << "For how much is sold this property" << endl;
			getline(cin, price);
			sellerPrice = strToInt(price);

			cout << "The asking price is " << sellerPrice << endl
				<< "Do you want to continue with the transaction" << endl
				<< "Yes: I agree with the price " << endl
				<< "No: I want to negotiate the price" << endl
				<< "Cancel: I want to cancel the transaction" << endl;

			getline(cin, ans);

			if (ans[0] == 'Y' || ans[0] == 'y')
			{
				if (buyer.subtractCurrency(sellerPrice))
				{
					buyer.addUtilityProperty(utilitySelected);
					seller.removeUtilityProperty(utilitySelected);
					seller.addCurrency(sellerPrice);
				}
				
				confirmation = true;
			}

			else if (ans[0] == 'N' || ans[0] == 'n')
				confirmation = false;

			else if (ans[0] == 'C' || ans[0] == 'c')
				return;

			else
			{
				cerr << "Your typed option is not valid, please try again" << endl;
			}

		} while (!confirmation);

		break;
	}
}

void mortageProperty(user & client)
{
	string colorName;
	color* colorSelected;
	railroad* railSelected;
	utility* utilitySelected;

	int category = getCategory();

	switch (category)
	{
	case 1:
		cout << "Select the color of the property you want to mortage or free mortage" << endl;
		getline(cin, colorName);
		//transform(colorName.begin(), colorName.end(), colorName.begin(), toupper);
                toUpperString(colorName);
		colorSelected = client.getColorProperty(colorName);

		if (colorSelected == nullptr)
		{
			cerr << "No property was selected, please press enter to return to main menu" << endl;
			getline(cin, colorName);
			return;
		}

		if (colorSelected->isMortaged())
		{
			int payment = colorSelected->getMortage() * 1.1;

			if (client.subtractCurrency(payment))
			{
				client.removeColorProperty(colorSelected);
				colorSelected->setMortage(false);
				client.addColorProperty(colorSelected);
			}

		}

		else
		{
			client.removeColorProperty(colorSelected);
			colorSelected->setMortage(true);
			client.addColorProperty(colorSelected);
			client.addCurrency(colorSelected->getMortage());
		}

		break;

	case 2:
		cout << "Select the property to be mortage or free" << endl;

		railSelected = client.getRailroadProperty();

		if (railSelected == nullptr)
		{
			cerr << "No property was selected, returning to main menu" << endl;
			getline(cin, colorName);
			return;
		}

		if (railSelected->isMortaged())
		{
			int payment = railSelected->getMortage() * 1.1;

			if (client.subtractCurrency(payment))
			{
				client.removeRailroadProperty(railSelected);
				railSelected->setMortage(false);
				client.addRailroadProperty(railSelected);
			}
		}
		
		else
		{
			client.removeRailroadProperty(railSelected);
			railSelected->setMortage(true);
			client.addRailroadProperty(railSelected);
			client.addCurrency(railSelected->getMortage());
		}
		

		break;

	default:
		cout << "Select the property to be mortage or free" << endl;

		utilitySelected = client.getUtilityProperty();

		if (utilitySelected == nullptr)
		{
			cerr << "No property was selected, returning to main menu" << endl;
			getline(cin, colorName);
			return;
		}

		if (utilitySelected->isMortaged())
		{
			int payment = utilitySelected->getMortage() * 1.1;

			if (client.subtractCurrency(payment))
			{
				client.removeUtilityProperty(utilitySelected);
				utilitySelected->setMortage(false);
				client.addUtilityProperty(utilitySelected);
			}
		}

		else
		{
			client.removeUtilityProperty(utilitySelected);
			utilitySelected->setMortage(true);
			client.addUtilityProperty(utilitySelected);
			client.addCurrency(utilitySelected->getMortage());
		}
		
	}
}

void buySellHouses(user & client)
{
	bool repeat;
	int numHouses;
	string colorName;
	string ans;

	cout << "Are you: " << endl
		 << "A. Buying houses " << endl
		 << "B. Selling houses " << endl;

	getline(cin, ans);

	while (ans[0] != 'A' && ans[0] != 'a' &&
		   ans[0] != 'B' && ans[0] != 'b')
	{
		cout << "Your last input wasn't recognixed, please try again" << endl;
		cout << "Are you: " << endl
		     << "A. Buying houses " << endl
			 << "B. Selling houses " << endl;

		getline(cin, ans);
	}
	
	if (ans[0] == 'a' || ans[0] == 'A')
	{
		
		cout << "In which color you want to invest" << endl;
		getline(cin, colorName);
		//transform(colorName.begin(), colorName.end(), colorName.begin(), toupper);
		toUpperString(colorName);
		vector<color*> proposed = client.getColorProperties(colorName);

		if (proposed.size() <= 2)
		{
			if (proposed.size() != 2 || (proposed[0]->getColor() != PURPLE
				&& proposed[0]->getColor() != BLUE))

			{
				cerr << "You still don't have all the color properties" << endl
					<< "Press enter to return to main menu" << endl;
				getline(cin, ans);
				return;
			}
		}
		do{
			repeat = false;
			bool priorityList[] = { false, false, false };

			for (int i = 0; i < proposed.size(); ++i)
			{
			    if (proposed[i]->getHouses() == 0)
				    priorityList[i] = true;

				if (i == 0)
				{
				    priorityList[i] = true;
				    continue;
				}

				if (proposed[i]->getHouses() < proposed[i - 1]->getHouses())
				{
				    priorityList[i] = true;
				    priorityList[i - 1] = false;
				}

				if (proposed[i]->getHouses() == proposed[i - 1]->getHouses())
				    priorityList[i] = priorityList[i - 1];
			 }

			 cout << "Do you want to invest in: " << endl;
			
			 char indicator = 'A';
			 for (int i = 0; i < proposed.size(); ++i)
			 {
			    if (priorityList[i])
			    {
				    cout << char(indicator + i) << ". " << proposed[i]->getName() << endl
					    << "If so, type yes. Otherwise, just type enter" << endl;
					
					getline(cin, ans);

					if (ans[0] == 'Y' || ans[0] == 'y')
					{
						if (client.subtractCurrency(proposed[i]->getCostHouse()))
						{
							client.removeColorProperty(proposed[i]);
							proposed[i]->updateRent(false, true);
							client.addColorProperty(proposed[i]);
							priorityList[i] = false;
						}
					 }
						
				}
			 }

			 cout << "Do you want to keep investing in the current color?" << endl;
			 getline(cin, ans);

			 if (ans[0] == 'Y' || ans[0] == 'y')
				 repeat = true;
		
		} while (repeat);
	}

	else if (ans[0] == 'b' || ans[0] == 'B')
	{
		do{
			cout << "Select the color of the properties in which you want to sell" << endl;
			getline(cin, colorName);
			//transform(colorName.begin(), colorName.end(), colorName.begin(), toupper);
                        toUpperString(colorName);
			color* selected = client.getColorProperty(colorName);
			
			if (selected == nullptr)
			{
				cerr << "No property was selected, press enter to return to main menu" << endl;
				getline(cin, ans);
				return;
			}

			cout << "How many houses you want to sell from this property (max: "<< selected->getHouses() 
				 << " house(s))"<<endl;
			getline(cin, ans);
			
			numHouses = strToInt(ans);

			while (selected->getHouses() < numHouses)
			{
				cerr << "Not enough houses to sell, please type an appropiate number" << endl;
				getline(cin, ans);
				numHouses = strToInt(ans);
			}

			client.removeColorProperty(selected);

			for (int i = 0; i < numHouses; ++i)
				selected->updateRent(false, false);

			client.addCurrency(numHouses * (selected->getCostHouse() / 2));
			
			client.addColorProperty(selected);

			cout << "Do you want to keep selling houses?" << endl
				<< "If so, type yes and press enter. Otherwise just type enter" << endl;

			getline(cin, ans);
			
			if (ans[0] == 'Y' || ans[0] == 'y')
				repeat = true;

			else
				repeat = false;
		
		} while (repeat);
	}

}

void payRent(user & rentee, user & renter)
{
	int category = getCategory();
	string colorName;
	color* colorSelected;
	railroad* railSelected;
	utility* utilitySelected;

	switch (category)
	{
	case 1:
		cout << "Write the color of the property" << endl;
		
		getline(cin, colorName);
		//transform(colorName.begin(), colorName.end(), colorName.begin(), toupper);
                toUpperString(colorName);
		colorSelected = renter.getColorProperty(colorName);

		if (colorSelected  == nullptr)
		{
			cerr << "No property was selected, returning to main menu" << endl;
			Custom_Clear();
			return;
		}

		cerr << "Rent charge: " << colorSelected->getRent()<<endl;

		if (colorSelected->isMortaged())
		{
			cout << "Property in mortage, you renter cannot charge the rent cost" << endl;
			cout << "Press enter to return to main menu";
			getline(cin, colorName);
			break;

		}

		if (rentee.subtractCurrency(colorSelected->getRent()) == false)
			rentee.setDebt(true);

		else
		{
			renter.addCurrency(colorSelected->getRent());
			rentee.setDebt(false);
		}

		Custom_Clear();
		break;

	case 2:
		cout << "Select the property to be charged" << endl;

		railSelected = renter.getRailroadProperty();

		if(railSelected == nullptr)
		{
                   cout << "No property was selected, returning to main menu\n";
		   Custom_Clear();
		   break;
		}

		cerr << "Rent charge: " << railSelected->getRent() << endl;

		if (railSelected->isMortaged())
		{
			cout << "Property in mortage, renter cannot charge the rent cost" << endl;
			cout << "Press enter to return to main menu";
			getline(cin, colorName);
			break;
		}


		if (rentee.subtractCurrency(railSelected->getRent()) == false)
			rentee.setDebt(true);

		else
		{
			rentee.setDebt(false);
			renter.addCurrency(railSelected->getRent());
		}
		
		break;

	case 3:
		cout << "Select the property to be charged" << endl;

		utilitySelected = renter.getUtilityProperty();
		
		if(utilitySelected == nullptr)
		{
                   cout << "No property selected, returning to main menu\n";
		   Custom_Clear();
		   break;
		}

		int utilityCharge = utilitySelected->getRent();

		cerr << "Rent Charge: " << utilityCharge << endl;

		if (utilitySelected->isMortaged())
		{
			cout << "Property in mortage, you renter cannot charge the rent cost" << endl;
			cout << "Press enter to return to main menu";
			getline(cin, colorName);
			break;
		}

		if (rentee.subtractCurrency(utilityCharge) == false)
			rentee.setDebt(true);

		else
		{
			rentee.setDebt(false);
			renter.addCurrency(utilityCharge);
		}
		break;
	}
}

void bankCharge(user & player)
{
	string ans;
	int charge;

	cout << "Are you getting revenue or losses?" << endl;
	cout << "Write 'revenue' or 'losses'. Otherwise, press any other key to return to main menu" << endl;
	getline(cin, ans);

	if (ans[0] == 'r' || ans[0] == 'R')
	{
		cout << "How much revenue are you getting?" << endl;
		getline(cin, ans);
		charge = strToInt(ans);
		player.addCurrency(charge);
	}

	else if (ans[0] == 'l' || ans[0] == 'L')
	{
		cout << "How much losses are you getting?" << endl;
		getline(cin, ans);
		charge = strToInt(ans);

		if (player.subtractCurrency(charge))
			player.setDebt(false);

		else
			player.setDebt(true);
	}

	else
		return;

}

LinkedUser* opening()
{
	bool repeat = false;
	string ans;
	vector<string> names;

	do
	{
		cout << "Please write the name of a player and press enter" << endl;
		getline(cin, ans);

		for (int i = 0; i < names.size(); ++i)
		{
			if (names[i] == ans)
			{
				cerr << "The name you wrote is already in the system. Names must be unique" << endl;
				cerr << "Enter your chosen name";
				getline(cin, ans);
				i = -1;
			}
		}
		names.push_back(ans);

		if (names.size() > 1)
		{
			cout << "Do you want to keep adding players?" << endl;
			getline(cin, ans);
		}

		else
		{
			cout << "Second player, ";
			ans[0] = 'y';
		}

		while (ans[0] != 'y' && ans[0] != 'Y' && ans[0] != 'n' && ans[0] != 'N')
		{
			cerr << "Your answer is not a valid one, please write it again";
			getline(cin, ans);
		}

		if (ans[0] == 'Y' || ans[0] == 'y')
			repeat = true;

		else if (ans[0] == 'n' || ans[0] == 'N')
			repeat = false;

	} while (repeat);
        
	user first = user(names[0]);
	LinkedUser* list = new LinkedUser(first);
	for (int i = 1; i < names.size(); ++i)
	{
	        user ite = user(names[i]);
		list->addUser(ite);
	}

	list->createCyclicList();

	Custom_Clear();

	return list;
}

void returnAllProperties(user & current, property_database & DB)
{
	vector<color*> colorTemp;
	vector<railroad*> railTemp;
	vector<utility*> utilityTemp;

	string currentColor[] = { PURPLE, SKY, MAGENTA, ORANGE, RED, YELLOW, GREEN, BLUE };

	for (int i = 0; i < 8; ++i)
	{
		colorTemp = current.getColorProperties(currentColor[i]);
		
		for (int j = 0; j < colorTemp.size(); ++i)
		{
			DB.returnColorProperty(colorTemp[j]);
		}
	}

	for (int i = 0; i < railTemp.size(); ++i)
	{
		DB.returnRailroadProperty(railTemp[i]);
	}

	for (int i = 0; i < utilityTemp.size(); ++i)
	{
		DB.returnUtilityProperty(utilityTemp[i]);
	}
}
