#ifndef PROPERTY_DATABASE_H
#define PROPERTY_DATABASE_H

#include <iostream>
#include <string>
#include <cstring>
#include "color.h"
#include "railroad.h"
#include "utility.h"
#include "Board.h"

using namespace std;



class property_database
{

friend class Board;

private:
	    color* colors[8][3];
	    railroad* rails[4];
	    utility* utilities[2];
      railroad* default_railroad;
      utility* default_utility;
      

public:
		explicit property_database();
		~property_database();
		color* getColorProperty(string);
		void returnColorProperty(color*);
		railroad* getRailroadProperty();
		void returnRailroadProperty(railroad*);
		utility* getUtilityProperty();
		void returnUtilityProperty(utility*);
};

#endif //PROPERTY_DATABASE_H
