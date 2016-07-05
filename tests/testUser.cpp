/*
#include <iostream>
#include <string>
#include "property_database.h"
#include "strings.h"
#include "user.h"


using namespace std;

int main()
{
	property_database DB;
	user player("Starker");

	cout << player.getName() << endl;
	cout << player.getCurrency() << endl;
	
	/*color test = DB.getColorProperty(BLUE);
	color test2 = DB.getColorProperty(BLUE);


	player.addColorProperty(test);

	color test_1 = player.getColorProperty(BLUE);

	if (test_1.getRent() == BLUE_1_RENT )
		cerr << "Before: Normal rent valid" << test_1.getRent() << endl;

	player.addColorProperty(test2);
	

	player.displayBalance();
	
	test_1 = player.getColorProperty(BLUE);
	cerr << "After acquiring property" << test_1.getRent() << endl;


	if (test_1.getRent() == BLUE_1_RENT * 2)
		cerr << "Double of the rent valid" <<endl;

	

	player.removeColorProperty(test2);

	player.displayBalance();

	test_1 = player.getColorProperty(BLUE);
	cerr << "Rent of property 1 = " << test_1.getRent() << endl;*/
	
	
	/*
	railroad test = DB.getRailroadProperty();
	player.addRailroadProperty(test);
	player.displayBalance();

	railroad test1 = player.getRailroadProperty();
	cout << "Rent of 1st property is " << test1.getRent() << endl;

	railroad test_2 = DB.getRailroadProperty();
	player.addRailroadProperty(test_2);
	player.displayBalance();

	railroad test2 = player.getRailroadProperty();
	cout << "Rent of 2nd property is " << test2.getRent() << endl;

	railroad test_3 = DB.getRailroadProperty();
	player.addRailroadProperty(test_3);
	player.displayBalance();

	railroad test3 = player.getRailroadProperty();
	cout << "Rent of 3rd property is " << test3.getRent() << endl;

	railroad test_4 = DB.getRailroadProperty();
	player.addRailroadProperty(test_4);
	player.displayBalance();

	railroad test4 = player.getRailroadProperty();
	cout << "Rent of 4th property is " << test4.getRent() << endl;

	player.removeRailroadProperty(test);
	player.displayBalance();
	railroad finalTest = player.getRailroadProperty();
	cout << "Rent of property is " << finalTest.getRent() << endl;
	
	player.removeRailroadProperty(test_2);
	player.displayBalance();
	finalTest = player.getRailroadProperty();
	cout << "Rent of property is " << finalTest.getRent() << endl;


	player.removeRailroadProperty(test_3);
	player.displayBalance();
	finalTest = player.getRailroadProperty();
	cout << "Rent of property is " << finalTest.getRent() << endl;


	player.removeRailroadProperty(test_4);
	player.displayBalance();
	finalTest = player.getRailroadProperty();
	cout << "Rent of property is " << finalTest.getRent() << endl;
	*/

	/*
	utility test = DB.getUtilityProperty();
	player.addUtilityProperty(test);
	player.displayBalance();

	utility test1 = player.getUtilityProperty();
	cout << "Rent of 1st property is " << test1.getRent() << endl;

	utility test_2 = DB.getUtilityProperty();
	player.addUtilityProperty(test_2);
	player.displayBalance();

	test1 = player.getUtilityProperty();
	cout << "Rent of 2nd property is " << test1.getRent() << endl;

	player.removeUtilityProperty(test);
	player.displayBalance();
	test1 = player.getUtilityProperty();
	cout << "Rent of property is " << test1.getRent() << endl;
	

    player.addCurrency(500);
	player.displayBalance();

	if(player.subtractCurrency(1000) == false)
		cerr<< "There is an error"<<endl;

	player.displayBalance();

	player.subtractCurrency(2000);
	player.displayBalance();
	return 0;
}*/