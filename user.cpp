#include <iostream>
#include "strings.h"
#include "user.h"
#include "helping_methods.h"

using namespace std;

user::user(string name) :player(name)
{
	currency = 1500;
	inDebt = false;
}

user::user()
{
	player = "";
}

void user::displayBalance()
{
	cout << "Player: " << player << endl;

	cout << "Cash: " << currency << endl<<endl;
	
	cout << "Properties in possesion: " << endl<<endl;

	for (int i = 0; i < purple.size(); ++i)
	{
		cout << purple[i].getName() << "  Color: " << purple[i].getColor() << endl;
		cout << "Num of Houses: " << purple[i].getHouses() << endl;
	}

	for (int i = 0; i < sky.size(); ++i)
	{
		cout << sky[i].getName() << "  Color: " << sky[i].getColor() << endl;
		cout << "Num of Houses: " << sky[i].getHouses() << endl;
	}

	for (int i = 0; i < magenta.size(); ++i)
	{
		cout << magenta[i].getName() << "  Color: " << magenta[i].getColor() << endl;
		cout << "Num of Houses: " << magenta[i].getHouses() << endl;
	}

	for (int i = 0; i < orange.size(); ++i)
	{
		cout << orange[i].getName() << "  Color: " << orange[i].getColor() << endl;
		cout << "Num of Houses: " << orange[i].getHouses() << endl;
	}

	for (int i = 0; i < red.size(); ++i)
	{
		cout << red[i].getName() << "  Color: " << red[i].getColor() << endl;
		cout << "Num of Houses: " << red[i].getHouses() << endl;
	}

	for (int i = 0; i < yellow.size(); ++i)
	{
		cout << yellow[i].getName() << "  Color: " << yellow[i].getColor() << endl;
		cout << "Num of Houses: " << yellow[i].getHouses() << endl;
	}

	for (int i = 0; i < green.size(); ++i)
	{
		cout << green[i].getName() << "  Color: " << green[i].getColor() << endl;
		cout << "Num of Houses: " << green[i].getHouses() << endl;
	}

	for (int i = 0; i < blue.size(); ++i)
	{
		cout << blue[i].getName() << "  Color: " << blue[i].getColor() << endl;
		cout << "Num of Houses: " << blue[i].getHouses() << endl;
	}

	for (int i = 0; i < rails.size(); ++i)
	{
		cout << rails[i].getName() << "  Railroad" << endl;
	}

	for (int i = 0; i < utilities.size(); ++i)
	{
		cout << utilities[i].getName() << " Utility" << endl;
	}

}

void user::setDebt(bool change)
{
	inDebt = change;
}
void user::addCurrency(int money)
{
	currency += money;
}

bool user::subtractCurrency(int money)
{
	if (currency < money)
	{
		cerr << "Transaction denied, low currency" << endl;
		return false;
	}

	else
	{
		currency -= money;
		return true;
	}
}

void user::updateColorRent(vector<color>& properties, bool flag)
{
	for (int i = 0; i < properties.size(); ++i)
	{
		properties[i].allColorRent(flag);
		properties[i].updateRent(true, true);
		
	}
}

void user::addColorProperty(color temp)
{
	if (temp.getName() == "")
		return;

	int ans = categoryColor(temp.getColor());

	switch (ans)
	{
	    case 0:
			purple.push_back(temp);
			if (purple.size() == 2)
			{
				updateColorRent(purple, true);
				allPurple = true;
			}
			break;

		case 1:
			sky.push_back(temp);
			if (sky.size() == 3)
			{
				updateColorRent(sky, true);
				allSky = true;
			}
			break;

		case 2:
			magenta.push_back(temp);
			if (magenta.size() == 3)
			{
				updateColorRent(magenta, true);
				allMagenta = true;
			}
			break;

		case 3:
			orange.push_back(temp);
			if (orange.size() == 3)
			{
				updateColorRent(orange, true);
				allOrange = true;
			}
			break;

		case 4:
			red.push_back(temp);
			if (red.size() == 3)
			{
				updateColorRent(red, true);
				allRed = true;
			}
			break;

		case 5:
			yellow.push_back(temp);
			if (yellow.size() == 3)
			{
				updateColorRent(yellow, true);
				allYellow = true;
			}
			break;

		case 6:
			green.push_back(temp);
			if (green.size() == 3)
			{
				updateColorRent(green, true);
				allGreen = true;
			}
			break;

		case 7:
			blue.push_back(temp);
			if (blue.size() == 2)
			{
				updateColorRent(blue, true);
				allBlue = true;
			}
			break;
	}
}

void user::removeColorProperty(color temp)
{
	int ans = categoryColor(temp.getColor());

	switch (ans)
	{
	case 0:
		for (int i = 0; i < purple.size(); ++i)
		{
			if (temp == purple[i])
			{
				purple.erase(purple.begin() + i);
				updateColorRent(purple, false);
				break;
			}
		}
		break;

	case 1:
		for (int i = 0; i < sky.size(); ++i)
		{
			if (temp == sky[i])
			{
				sky.erase(sky.begin() + i);
				updateColorRent(sky, false);
				break;
			}
		}
		break;

	case 2:
		for (int i = 0; i < magenta.size(); ++i)
		{
			if (temp == magenta[i])
			{
				magenta.erase(magenta.begin() + i);
				updateColorRent(magenta, false);
				break;
			}
		}
		break;

	case 3:
		for (int i = 0; i < orange.size(); ++i)
		{
			if (temp == orange[i])
			{
				orange.erase(orange.begin() + i);
				updateColorRent(orange, false);
				break;
			}
		}
		break;

	case 4:
		for (int i = 0; i < red.size(); ++i)
		{
			if (temp == red[i])
			{
				red.erase(red.begin() + i);
				updateColorRent(red, false);
				break;
			}
		}
		break;

	case 5:
		for (int i = 0; i < yellow.size(); ++i)
		{
			if (temp == yellow[i])
			{
				yellow.erase(yellow.begin() + i);
				updateColorRent(yellow, false);
				break;
			}
		}
		break;

	case 6:
		for (int i = 0; i < green.size(); ++i)
		{
			if (temp == green[i])
			{
				green.erase(green.begin() + i);
				updateColorRent(green, false);
				break;
			}
		}
		break;

	case 7:
		for (int i = 0; i < blue.size(); ++i)
		{
			if (temp == blue[i])
			{
				blue.erase(blue.begin() + i);
				updateColorRent(blue, false);
				break;
			}
		}
		break;
	}
}

color user::getColorProperty(string colorName)
{
	vector<color> election;
	string answer;
	int propertyIndex;
	int ans = categoryColor(colorName);

	switch (ans)
	{
	case 0:
		election = purple;
		break;

	case 1:
		election = sky;
		break;

	case 2:
		election = magenta;
		break;

	case 3:
		election = orange;
		break;

	case 4:
		election = red;
		break;

	case 5:
		election = yellow;
		break;

	case 6:
		election = green;
		break;

	default:
		election = blue;
	}

	bool validColor = false;

	do
	{
		cout << "Choose the appropiate property by pressing its number and press enter" << endl;
		cout << "(If there is no available property, just write exit)" << endl;

		for (int i = 0; i < election.size(); ++i)
		{
			cout << (i + 1) << ". " << election[i].getName() << endl;
		}

		getline(cin, answer);

		propertyIndex = strToInt(answer);
		--propertyIndex;

		if (propertyIndex == -1)
		{
			cerr << "No property available" << endl;
			return color();
		}

		if (propertyIndex >= 0 && propertyIndex < election.size())
		{
			validColor = true;
		}

		if (!validColor)
			cerr << "Your election wasn't a valid one" << endl;

	} while (!validColor);

	return  election[propertyIndex];
}

vector<color> user::getColorProperties(string colorName)
{
	int ans = categoryColor(colorName);
	switch (ans)
	{
	case 0:
		return purple;
		break;

	case 1:
		return sky;
		break;

	case 2:
		return magenta;
		break;

	case 3:
		return orange;
		break;

	case 4:
		return red;
		break;

	case 5:
		return yellow;
		break;

	case 6:
		return green;
		break;

	default:
		return blue;

	}
}

void user::addRailroadProperty(railroad temp)
{
	if (temp.getName() == "")
		return;
	
	rails.push_back(temp);
	
	for (int i = 0; i < rails.size(); ++i)
	{
		rails[i].updateRent(rails.size());
	}
}

void user::removeRailroadProperty(railroad temp)
{
	for (int i = 0; i < rails.size(); ++i)
	{
		if (rails[i] == temp)
		{
			rails.erase(rails.begin() + i);
			
			for (int j = 0; j < rails.size(); ++j)
			    rails[j].updateRent(rails.size());

			break;
		}
	}
}

railroad user::getRailroadProperty()
{
	bool validRail = false;
	string ans;
	int propertyIndex;

	do
	{
		cout << "Choose the appropiate property by pressing its number and press enter" << endl;
		cout << "(If there is no available property, just write exit)" << endl;

		for (int i = 0; i < rails.size(); ++i)
		{
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

		if (propertyIndex >= 0 && propertyIndex < rails.size())
		{
			validRail = true;
		}

		if (!validRail)
			cerr << "Your election wasn't a valid one" << endl;

	} while (!validRail);

	return  rails[propertyIndex];

}

vector <railroad> user::getRailroadProperties()
{
	return rails;
}

void user::addUtilityProperty(utility temp)
{
	if (temp.getName() == "")
		return;

	utilities.push_back(temp);
	
	for (int i = 0; i < utilities.size(); ++i)
	{
		utilities[i].updateFactor(utilities.size());
	}
}

void user::removeUtilityProperty(utility temp)
{
	for (int i = 0; i < utilities.size(); ++i)
	{
		if (utilities[i] == temp)
		{
			utilities.erase(utilities.begin() + i);

			for (int j = 0; j < utilities.size(); ++j)
				utilities[j].updateFactor(utilities.size());

			break;
		}
	}
}

utility user::getUtilityProperty()
{
	bool validUtility = false;
	string ans;
	int propertyIndex;

	do
	{
		cout << "Choose the appropiate property by pressing its number and press enter" << endl;
		cout << "(If there is no available property, just write exit)" << endl;

		for (int i = 0; i < utilities.size(); ++i)
		{
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

		if (propertyIndex >= 0 && propertyIndex < utilities.size())
		{
			validUtility = true;
		}

		if (!validUtility)
			cerr << "Your election wasn't a valid one" << endl;

	} while (!validUtility);

	return  utilities[propertyIndex];
}

vector<utility> user::getUtilityProperties()
{
	return utilities;
}

bool user::hasAnyProperty()
{
	if (purple.size() != 0 || sky.size() != 0 || magenta.size() != 0 || orange.size() != 0 ||
		red.size() != 0 || yellow.size() != 0 || green.size() != 0 || blue.size() != 0
		|| rails.size() != 0 || utilities.size() != 0)
	{
		return true;
	}

	else
		return false;
}