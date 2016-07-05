
#include <iostream>
#include <string>
#include "user.h"
#include "property_database.h"
#include "LinkedUser.h"
#include "menu_methods.h"
#include "InterfacesMenus.h"
#include "helping_methods.h"

using namespace std;

int main()
{
	cout << "Welcome to the Monopoly Management System" << endl;
	cout << "Let's start by adding the players" << endl;
	bool repeat = true;
	bool ans;
	int answer;
	string respond;
	string secondPlayer;
	user* currentPlayer;
	user* otherPlayer;
	LinkedUser* list = opening();
	property_database DB;

	do
	{
		string currentName = list->getCurrent()->getUser()->getName();
		currentPlayer = list->getCurrent()->getUser();

		if (list->getCurrent() == list->getCurrent()->getNext())
		{
			cout << "Congratulations to " << currentName <<", you win"<<endl;
			break;
		}

		answer = Main_Menu(list);

		ClearScreen();

		switch (answer)
		{
		case 1:
			list->getCurrent()->getUser()->displayBalance();
			Custom_Clear();
			break;

		case 2:
			answer = Transaction_Menu();

			ClearScreen();

			if (answer == 1)
			{
				answer = buy_sell_transactions_menu();

				ClearScreen();

				switch (answer)
				{
				case 1:
					buyPropertyToBank(*currentPlayer, DB);
					break;

				case 2:
					ans = Are_You_Buyer();
					cout << "Who is the other player?";
					getline(cin, secondPlayer);

					otherPlayer = list->obtainUser(secondPlayer);

					while (otherPlayer == nullptr)
					{
						cerr << "Please write the correct name. Here is a list of them" << endl;
						list->displayList();
						getline(cin, secondPlayer);
						otherPlayer = list->obtainUser(secondPlayer);
					}

					if (ans)
					{
						buyPropertyToPlayer(*currentPlayer, *otherPlayer);
					}

					else
					{
						buyPropertyToPlayer(*otherPlayer, *currentPlayer);
					}

					break;

				case 3:
					buySellHouses(*currentPlayer);
					break;

				case 4:
					mortageProperty(*currentPlayer);
					break;

				case 5:
					continue;
				}
			}
			
			else if (answer == 2)
			{
				answer = pure_cash_transactions_menu();
				ClearScreen();

				if (answer == 1)
				{
					cout << "To who you are paying?" << endl;
					getline(cin, secondPlayer);
					Custom_Clear();

					otherPlayer = list->obtainUser(secondPlayer);

					while (otherPlayer == nullptr)
					{
						cerr << "Please write the correct name. Here is a list of them" << endl;
						list->displayList();
						getline(cin, secondPlayer);
						otherPlayer = list->obtainUser(secondPlayer);
					}

					payRent(*currentPlayer, *otherPlayer);
				}

				else if (answer == 2)
				{
					bankCharge(*currentPlayer);
				}

				else
					continue;
			}

			else
				continue;
			break;

		case 3:
			list->nextCurrent();
			break;

		case 4:
			cout << "Are you sure you want to declare in bankrupt?" << endl;
			getline(cin, respond);

			if (respond[0] == 'y' || respond[0] == 'Y')
			{
				if (currentPlayer->hasAnyProperty())
				{
					cerr << "Sell all your properties before declaring in bankrupt" << endl;
					cerr << "Returning to Main Menu" << endl;
					Custom_Clear();
					continue;
				}
				else
				    list->removeUser(list->getCurrent());
			}

			break;
			Custom_Clear();
		}

		ClearScreen();

	} while (repeat);
	
	return 0;
}
