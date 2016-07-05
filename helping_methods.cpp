#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <windows.h>
#include "strings.h"

using namespace std;

/*
 * Function name: strToInt()
 * Description: It takes a string as argument and returns an integer
 * Special condition: It returns 0 if the user enters an 'e' or 'E'
 *                    as its first character.
 *
 * Arguments:
 *    arg 1: String ans: String that the user enters
 */
int strToInt(string ans)
{
	// Variable to used to store the integer value of the string
	int answer;  

	// Loop that will go through each character of the string
	for (int i = 0; i < ans.size(); ++i)
	{
		if (isdigit(ans[i]) == 0) //This checks if the string is not a digit
		{
			// If the user enters 'e' or 'E', it exits the function
			if (ans[0] == 'e' || ans[0] == 'E') 
			{
				return 0;
			}

			/* If the user didn't enter a valid string, the program will displays an 
			 * error message
			 */
			cerr << "Your last input wasn't a number, please try again" << endl;
			
			// Get the new string from the user
			getline(cin, ans);

			//Restart the counter of the loop and go to the next iteration
			i = -1;
			continue;
		}
	}

	// If the string resulted a valid for an integer, transform the string into an integer 
	answer = atoi(ans.c_str());

	return answer;

}

/*
 * Function: categoryColor()
 * Description: Function that is responsable for checking if the string 
 *              received is a valid color, and it returns a number after it
 *              finds a valid color
 *
 * Arguments: 
 *    arg1: colorName - String that could represents a color
 */
int categoryColor(string colorName)
{
	int colorNumber; //Integer to be returned
	bool validColor; // Boolean variable that will serve as a flag for 
	                 // the next loop
	do
	{
		/* If the string is one of the following colors, assign it a code number
		   an set the flag to true*/

		if (colorName == PURPLE)
		{
			colorNumber = 0;
			validColor = true;
		}

		else if (colorName == SKY)
		{
			colorNumber = 1;
			validColor = true;
		}

		else if (colorName == MAGENTA)
		{
			colorNumber = 2;
			validColor = true;
		}

		else if (colorName == ORANGE)
		{
			colorNumber = 3;
			validColor = true;
		}

		else if (colorName == RED)
		{
			colorNumber = 4;
			validColor = true;
		}

		else if (colorName == YELLOW)
		{
			colorNumber = 5;
			validColor = true;
		}

		else if (colorName == GREEN)
		{
			colorNumber = 6;
			validColor = true;
		}

		else if (colorName == BLUE)
		{
			colorNumber = 7;
			validColor = true;
		}

		// If the string isn't one of the previous colors
		else
		{
			// Display an error message
			cerr << "Invalid color name, please write the color again" << endl;

			// Get the new string from the user
			getline(cin, colorName);

			// Use the transform method to make the string uppercase
			transform(colorName.begin(), colorName.end(), colorName.begin(), toupper);

			// Set the flag to false
			validColor = false;
		}
	} while (!validColor); // While we don't have a valid color

	return colorNumber;
}

/*
 * Function name: getCategory()
 * Description: It gets an answer for the user about which category they might 
 *              want to use for their transactions
 * Arguments: None
 */
int getCategory()
{
	// Boolean flag to be used for error checking
	bool validCategory = false; 

	// String variable that will store the user answer
	string answer;

	// do-while loop that will continue until the user enters the appropiate character
	do
	{
		// Promping for the answer
		cout << "Type the category of the property to be processed " << endl
			 << "(Color, Railroad, or Utility)" << endl;
		
		// Getting the string from the user
		getline(cin, answer);

		/* If the the first character of the answer variable is either c, r, u 
		   upper or lowercase, the method will return a number code */

		if (answer[0] == 'c' || answer[0] == 'C')
			return 1;

		else if (answer[0] == 'r' || answer[0] == 'R')
			return 2;

		else if (answer[0] == 'u' || answer[0] == 'U')
			return 3;

		/* If the string don't fall under the previous conditions, it will display an
		   error msg */
		
		else
		{
			cerr << "Your chosen category isn't valid, please write it again" << endl;
		}

	} while (!validCategory);
}



void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Custom_Clear()
{
	string enter;
	cout << "Press enter to continue" << endl;
	getline(cin, enter);
	ClearScreen();
}