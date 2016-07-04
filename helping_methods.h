#ifndef HELPING_METHODS_H
#define HELPING_METHODS_H

#include <string>
#include "clrscreen_linux.h"
//#include "clrscreen.h" for Windows

using namespace std;

//Helping methods

int strToInt(string);       // Transforms the string into a number

int getCategory();          // Ask to the user about which category (Color, 
                            // Railroad, or Utility) will be involved in a
                            // transaction

int categoryColor(string);  // Get the specific color of a category

void ClearScreen();

void Custom_Clear();

void toUpperString(string& str);

#endif //HELPING_METHODS_H
