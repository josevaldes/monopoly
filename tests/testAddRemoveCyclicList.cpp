/*
#include <iostream>
#include <string>
#include "property_database.h"
#include "LinkedUser.h"
#include "user.h"
#include "menu_methods.h"

using namespace std;

int main()
{
	user listUser[] = { user("Starker"), user("Novastorm"), user("Alcaro"), user("Jedastla"),
		user("Sadevlet"), user("Kenshin"), user("Raiden"), user("Raika") };
	
	LinkedUser* list = new LinkedUser(listUser[0]);
	
	for (int i = 1; i < 8; ++i)
		list->addUser(listUser[i]);

	cerr << endl << "Head is: " << list->getHead()->getUser()->getName() << endl;

	list->createCyclicList();
	list->displayList();

	string command;
	Node* ite = list->getHead();
	bool keep = true;

	while (list->getCurrent() != nullptr || keep)
	{
		cerr << "Current is: " << list->getCurrent()->getUser()->getName() << endl;
		cerr << "Move backward with \'a\' and forward with \'d\'. Remove user with \'r\'. Quit with \'q\' " << endl;
		cin >> command;
		
		if (command == "a")
		{
			list->nextCurrent();
		}
		else if (command == "d")
		{
			list->prevCurrent();
		}
		
		else if (command == "r")
		{
			list->removeUser(list->getCurrent());
		}
		else if (command == "q")
		{
			keep = false;
		}
	}
	
	//list->removeUser(list->getCurrent());
	
//	cerr << endl;
	//list->displayList();

	//cerr << endl << "Head is: " << list->getHead()->getUser()->getName() << endl;
	
	/*property_database DB;
	user* test = list->obtainUser("Alcaro");
	test->displayBalance();
	cerr << endl;
	
	test->addCurrency(1500);
	buyPropertyToBank(*test, DB);
	
	user* test_2 = list->obtainUser("Alcaro");
	
	test_2->displayBalance();
	


	return 0;
}*/