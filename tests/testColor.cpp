/*
#include <iostream>
#include <string>
#include "color.h"

using namespace std;

int main()
{
	color test(100, 10, 50, 25, 50, 75, 100, 200, "YELLOW", "VERACRUZ");

	// Testing the accessors:
	if (test.getCost() != 100)
		cerr << "Error in the setting of cost" << endl;

	if (test.getCostHouse() != 50)
		cerr << "Error in the setting of cost of a house" << endl;
	
	if (test.getRent() != 10)
		cerr << "Error in the setting of rent" << endl;
	
	if (test.getHasHotel())
		cerr << "Error in the number of  houses" << endl;

	if (test.isMortaged())
		cerr << "Error in the setting of mortage" << endl;

	if (test.getColor() != "YELLOW")
		cerr << "Error in the setting of cost" << endl;
	
	if (test.getName() != "VERACRUZ")
		cerr << "Error in the setting of cost" << endl;

	// Testing allColorRent()

	test.allColorRent();
	if (test.getRent() != 20)
		cerr << "Error in allColorRent()"<<endl;

	//Testing updateRent() increase
	for (int i = 0; i < 6; ++i)
	{
		int testRent;
		switch (i)
		{
		    case 0:
				testRent = 25;
				break;

			case 1:
				testRent = 50;
				break;

			case 2:
				testRent = 75;
				break;

			case 3:
				testRent = 100;
				break;

			default:
				testRent = 200;
		}

		test.updateRent(true);
		if (test.getRent() != testRent)
			cerr << "Error in updateRent() increase" << endl;
	}

	//Testing updateRent() decrease
	for (int i = 0; i < 6; ++i)
	{
		int testRent;
		switch (i)
		{
		case 0:
			testRent = 100;
			break;

		case 1:
			testRent = 75;
			break;

		case 2:
			testRent = 50;
			break;

		case 3:
			testRent = 25;
			break;

		default:
			testRent = 20;
		}

		test.updateRent(false);
		if (test.getRent() != testRent)
			cerr << "Error in updateRent() decrease" << endl;
	}
	color test_2 = test;
	if (test_2.getName() != test.getName())
		cerr << "Error in copy" << endl;
	
	if (test_2 != test)
		cerr << "Error in comparison" << endl;

	color test_3(100, 10, 50, 25, 50, 75, 100, 200, "YELLOW", "VERACRUX");

	if (test_3 == test)
		cerr << "Error in comparison" << endl;

	cout << "End of test" << endl;
	return 0;
}*/