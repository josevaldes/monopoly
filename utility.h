
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class utility
{
private:
	int rent;
	int cost;
	int mortage;
	int factor;
	bool owned;
	bool mortaged;
	string category;
	string name;

public:
	explicit utility(string n) : name(n)
	{
		cost = 150;
		mortage = 75;
		category = "UTILITY";
		factor = 4;
		owned = false;
		mortaged = false;
	}

	utility()
	{
		name = "";
	}

	~utility(){}

	int getCost() const
	{
		return cost;
	}

	int getMortage() const
	{
		return mortage;
	}

	bool isOwned() const
	{
		return owned;
	}

	bool isMortaged() const
	{
		return mortaged;
	}

	string getCategory() const
	{
		return category;
	}

	string getName() const
	{
		return name;
	}

	void setOwned(bool change)
	{
		owned = change;
	}

	void setMortage(bool change)
	{
		mortaged = change;
	}

	int getRent() 
	{
		int dice;
		bool error = false;
		do{
			if (error)
				cerr << "Your last input isn't a valid dice number" << endl;

			cout << "Please enter the number given by the dice" << endl;
			string ans;
			getline(cin, ans);

			for (int i = 0; i < ans.size(); ++i)
			{
				if (isdigit(ans[i]) == 0)
				{
					cerr << "Your last input wasn't a number, please try again" << endl;
					getline(cin, ans);
					i = -1;
					continue;
				}
			}

			dice = atoi(ans.c_str());
			error = (dice < 1 || dice > 12);

		} while (error);

		rent = dice * factor;
		return rent;
	}

	void updateFactor(int num)
	{
		if (num == 2)
			factor = 10;
		else
			factor = 4;
	}

	bool operator==(const utility & rhs)
	{
		return name == rhs.getName();
	}

	bool operator!=(const utility & rhs)
	{
		return name != rhs.getName();
	}
};
#endif UTILITY_H