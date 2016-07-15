#include <string>
#include "helping_methods.h"
#include "LinkedUser.h"
#include "Interfaces_Menu.h"

using namespace std;

int Actions_Menu(user* current, string opt_3)
{
	int ans;
	string answer;

	cout << "Current turn: " << current->getName() << endl;
	cout << "Currency: " << current->getCurrency() << endl;
	cout << "In position: " << current->getCurrPos() << endl;
	cerr << endl << endl;

	cout << "Actions:" << endl;
	cout << "    1. View Balance" << endl;
	cout << "    2. Make a transaction" << endl;
	cout << "    3. "<<  opt_3 << endl;
	cout << "    4. Declare yourself in bankrupt" << endl;
	
	cerr << endl;
	cout << "Type a number and press enter" << endl;
	getline(cin, answer);

	ans = strToInt(answer);

	while (ans < 1 && ans > 4)
	{
		cerr << "Number is not valid, please type your number again"<<endl;
		getline(cin, answer);
		ans = strToInt(answer);
	}

	return ans;
}

int Transaction_Menu()
{
	string answer;
	int ans;
	cout << "Transaction menu:" << endl;
	cout << "    1. Buying-Selling properies/goods" << endl;
	cout << "    2. Pure cash transactions" << endl;
	cout << "    3. Return to Main Menu" << endl;

	cerr << endl;
	cout << "Type a number and press enter" << endl;
	getline(cin, answer);

	ans = strToInt(answer);

	while (ans < 1 && ans > 3)
	{
		cerr << "Number is not valid, please type your number again" << endl;
		getline(cin, answer);
		ans = strToInt(answer);
	}

	return ans;
}

int pure_cash_transactions_menu()
{
	string answer;
	int ans;
	cout << "Select a specific transaction:" << endl;
	cout << "    1. Pay rent" << endl;
	cout << "    2. Receiving/Paying to bank" << endl;
	cout << "    3. Return to Main Menu" << endl;

	cerr << endl;
	cout << "Type a number and press enter" << endl;
	getline(cin, answer);

	ans = strToInt(answer);

	while (ans < 1 && ans > 3)
	{
		cerr << "Number is not valid, please type your number again" << endl;
		getline(cin, answer);
		ans = strToInt(answer);
	}
	return ans;
}

int buy_sell_transactions_menu()
{
	string answer;
	int ans;
	cout << "Select a specific transaction:" << endl;
//	cout << "    1. Buy a property from the bank" << endl;
	cout << "    1. Buy or sell property from another player" << endl;
	cout << "    2. Buy or sell houses" << endl;
	cout << "    3. Take or pay mortage" << endl;
	cout << "    4. Return to Main Menu" << endl;

	cerr << endl;
	cout << "Type a number and press enter" << endl;
	getline(cin, answer);

	ans = strToInt(answer);

	while (ans < 1 && ans > 4)
	{
		cerr << "Number is not valid, please type your number again" << endl;
		getline(cin, answer);
		ans = strToInt(answer);
	}
	return ans;
}

bool Are_You_Buyer()
{
	bool repeat = false;
	string ans;
	cout << "Are you a buyer or seller?" << endl;
	cout << "Write your answer" << endl;
	do{
		getline(cin, ans);

		if (ans[0] == 'B' || ans[0] == 'b')
			return true;

		else if (ans[0] == 's' || ans[0] == 'S')
			return false;

		else
		{
			cerr << "Option not available, please try again";
			repeat = true;
		}
	} while (repeat);
}

