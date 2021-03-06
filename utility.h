
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <cstring>
#include "Property.h"

using namespace std;

class utility: public Property
{
private:
	int factor;
  int dice;

public:
	explicit utility(string n) : Property(n)
	{
		cost = 150;
		mortage = 75;
		category = "UTILITY";
		factor = 4;
		owned = false;
		mortaged = false;
	}


	utility(): Property()
	{
		//name = "";
	}


	~utility(){}
/*
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
*/
	void setDice(int d)
  {
     dice = d;
  }

  int getRent() 
	{
	/*	
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
*/
		int fact = factor;
    if(chanceFlag)
    {
       fact = 10;
       chanceFlag = false;
    }
    rent = dice * fact;
		return rent;
	}

	void updateFactor(int num)
	{
		if (num == 2)
			factor = 10;
		else
			factor = 4;
	}
/*
	bool operator==(const utility & rhs)
	{
		return name == rhs.getName();
	}

	bool operator!=(const utility & rhs)
	{
		return name != rhs.getName();
	}
  */
};
#endif //UTILITY_H
