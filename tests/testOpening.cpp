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
	LinkedUser* list = opening();

	list->displayList();
	cerr <<"To be eliminated: "<< list->getTail()->getUser()->getName()<<endl;
	

	list->removeUser(list->getTail());
	list->removeUser(list->getHead());
	cerr << endl;

	list->displayList();

	property_database DB;
	user* test = list->obtainUser("Alcaro");
	test->displayBalance();
	cerr << endl;

	test->addCurrency(1500);
	buyPropertyToBank(*test, DB);

	user* test_2 = list->obtainUser("Alcaro");
	test_2->displayBalance();

	return 0;
}*/