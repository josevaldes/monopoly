#ifndef INTERFACES_MENUS_H
#define INTERFACES_MENUS_H

#include <string>
#include "user.h"
#include "helping_methods.h"

int Actions_Menu(user*, string);
int Transaction_Menu();
int buy_sell_transactions_menu();
int pure_cash_transactions_menu();
bool Are_You_Buyer();

#endif
