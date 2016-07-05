/*
#include <iostream>
#include <string>
#include "utility.h"

using namespace std;

int main()
{
	utility test("Element");

	if (test.getCost() != 150)
		cerr << "Error in accesing of cost" << endl;

	if (test.isOwned())
		cerr << "Error in accesing status" << endl;

	if (test.isMortaged())
		cerr << "Error in accesing mortage" << endl;

	if (test.getCategory() != "UTILITY")
		cerr << "Error in the setting of category" << endl;

	if (test.getName() != "Element")
		cerr << "Error in the setting of name" << endl;

	for (int i = 1; i < 3; ++i)
	{
		int testRent = 20 * i;
		if (test.getRent() != testRent)
			cerr << "Error in setting the rent" << endl;
	}

	test.updateFactor(2);
	if (test.getRent() != 120)
		cerr << "Error in setting the rent" << endl;

	cout << "End of test" << endl;

	return 0;
}*/