/*#include <iostream>
#include <string>
#include "railroad.h"

using namespace std;

int main()
{

	railroad test ("Element");
	
	if (test.getCost() != 200)
		cerr << "Error in the setting of cost" << endl;
		
	if (test.getRent() != 25)
		cerr << "Error in the setting of rent" << endl;

	if (test.isOwned())
		cerr << "Error in the number of  houses" << endl;

	if (test.isMortaged())
		cerr << "Error in the setting of mortage" << endl;

	if (test.getCategory() != "RAILROAD")
		cerr << "Error in the setting of cost" << endl;

	if (test.getName() != "Element")
		cerr << "Error in the setting of cost" << endl;

	for (int i = 1; i < 6; ++i)
	{
		int testRent;
		switch (i)
		{
		case 1:
			testRent = 25;
			break;

		case 2:
			testRent = 50;
			break;

		case 3:
			testRent = 100;
			break;

		case 4:
			testRent = 200;
			break;

		case 5:
			testRent = 50;
		}

		test.updateRent(i);
		if (test.getRent() != testRent)
			cerr << "Error in updateRent() " << endl;
	}
	cout << "End of test" << endl;
	return 0;
}*/