/*
#include <iostream>
#include <string>
#include "color.h"
#include "property_database.h"
#include "strings.h"

using namespace std;

int main()
{
	property_database DB;
	
	color x = DB.getColorProperty("TETE");
	color y = x;
	
	if (x.getName() != RED_2_NAME)
		cerr << "Error in testing red 2 name" << endl;

	if (y != x)
		cerr << "Error in equivalence testing works" << endl;

	if (!y.isOwned())
		cerr << "Error in owned flag" << endl;

	
	x = DB.getColorProperty(RED);

	if (x.getName() == RED_1_NAME)
		cerr << "Error in testing red 1 name" << endl;

	railroad test = DB.getRailroadProperty();
	
	if (test.getName() == RAILROAD_4_NAME)
		cerr << "Error in testing Railroad 4 name" << endl;

	utility test_2 = DB.getUtilityProperty();
	utility test_22 = test_2;

	if (test_2.getName() == UTILITY_1_NAME)
		cerr << "Error in Utility 1 name" << endl;

	if (test_2 == test_22)
		cerr << "Error in Comparison on utilities" << endl;

	test_2 = DB.getUtilityProperty();

	color x_1 = DB.getColorProperty(BLUE);
	color x_2 = DB.getColorProperty(BLUE);
	color x_3 = DB.getColorProperty(BLUE);

	if (x_3.getName() == "")
		cerr << "Property doesn't exists" << endl;

	DB.returnColorProperty(x_1);
	DB.returnColorProperty(x_2);

	x = DB.getColorProperty(BLUE);

	

	railroad y_1 = DB.getRailroadProperty();
	railroad y_2 = DB.getRailroadProperty();
	railroad y_3 = DB.getRailroadProperty();
	railroad y_4 = DB.getRailroadProperty();
	
	if (y_4.getName() != "")
		cerr << "Error in empty property" << endl;

	DB.returnRailroadProperty(test);
	DB.returnRailroadProperty(y_1);
	DB.returnRailroadProperty(y_2);
	DB.returnRailroadProperty(y_3);
	DB.returnRailroadProperty(y_4);

	test = DB.getRailroadProperty();

	return 0;
}*/