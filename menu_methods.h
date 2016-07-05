#ifndef MENU_METHODS_H
#define MENU_METHODS_H

#include <string>
#include "user.h"
#include "property_database.h"
#include "LinkedUser.h"

void buyPropertyToBank(user &, property_database &);
void mortageProperty(user &);
void buyPropertyToPlayer(user &, user &);
void buySellHouses(user &);
void payRent(user &, user &);
void bankCharge(user &);
LinkedUser* opening();
void returnAllProperties(user &, property_database &);

#endif MENU_METHODS_H