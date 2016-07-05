#ifndef RAILROAD_H
#define RAILROAD_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class railroad
{
    private:
		int rent;
		int cost;
		int mortage;
		bool owned;
		bool mortaged;
		string category;
		string name;

    public:
		explicit railroad(string n) : name(n)
		{
			rent = 25;
			cost = 200;
			mortage = 100;
			category = "RAILROAD";
			owned = false;
			mortaged = false;
		}

		railroad()
		{
			name = "";
		}

		~railroad(){}

		int getRent() const
		{
			return rent;
		}

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

		void updateRent(int railroads)
		{
			switch (railroads)
			{
			    case 1:
					rent = 25;
					break;

				case 2:
					rent = 50;
					break;

				case 3:
					rent = 100;
					break;

				case 4:
					rent = 200;
			}
		}

		bool operator==(const railroad & rhs)
		{
			return name == rhs.getName();
		}

		bool operator!=(const railroad & rhs)
		{
			return name != rhs.getName();
		}
};

#endif RAILROADS_H