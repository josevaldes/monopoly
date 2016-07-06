CC=g++
CFLAGS = -lncurses
CXXFLAGS = -std=c++11

testRailroad: testRailroad.cpp  
	$(CC) $(CXXFLAGS) -o testRailroad testRailroad.cpp
	./testRailroad

testUtility: testUtility.cpp  
	$(CC) $(CXXFLAGS) -o testUtility testUtility.cpp
	./testUtility

testColor: testColor.cpp color.cpp 
	$(CC) $(CXXFLAGS) -o testColor testColor.cpp color.cpp
	./testColor

testPropertyDB: testPropertyDatabase.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp
	$(CC) $(CXXFLAGS) -o testPropertyDB testPropertyDatabase.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp $(CFLAGS)
	./testPropertyDB
