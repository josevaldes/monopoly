#ifndef INTERFACES_MENUS_H
#define INTERFACES_MENUS_H

#include <string>
#include "LinkedUser.h"
#include "helping_methods.h"

int Main_Menu(LinkedUser*);
int Transaction_Menu();
int buy_sell_transactions_menu();
int pure_cash_transactions_menu();
bool Are_You_Buyer();

#endif