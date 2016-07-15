#ifndef MENU_METHODS_H
#define MENU_METHODS_H

#include <string>
#include <queue>
#include <map>
#include "user.h"
#include "Property.h"
#include "property_database.h"
#include "LinkedUser.h"

using namespace std;

void buyPropertyToBank(user &, property_database &);
void mortageProperty(user &);
void buyPropertyToPlayer(user *, user* );
void buySellHouses(user &);
void payRent(user &, user &);
void bankCharge(user &);
LinkedUser* opening();
void returnAllProperties(user &, property_database &);
void buySellProperty(user*, LinkedUser* );
bool Menu(user*, LinkedUser*, bool, bool);
#endif //MENU_METHODS_H
