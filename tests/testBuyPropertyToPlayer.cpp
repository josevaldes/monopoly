/*
#include <iostream>
#include <string>
#include "user.h"
#include "property_database.h"
#include "menu_methods.h"
#include "helping_methods.h"

using namespace std;

int main()
{
	string enter;

	user player_1("Starker");
	user player_2("Novastrom");
	property_database DB;

	player_1.displayBalance();
	Custom_Clear();

	player_2.displayBalance();
	Custom_Clear();

	for (int i = 0; i < 1; ++i)
	{
		buyPropertyToBank(player_1, DB);
		buyPropertyToBank(player_2, DB);
	}

	player_1.displayBalance();
	Custom_Clear();

	player_2.displayBalance();
	Custom_Clear();
	
	buyPropertyToPlayer(player_1, player_2);
	Custom_Clear();

	player_1.displayBalance();
	Custom_Clear();

	player_2.displayBalance();
	Custom_Clear();

	return 0;
}
*/