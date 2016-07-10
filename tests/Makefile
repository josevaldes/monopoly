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

testUser: testUser.cpp color.cpp  property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testUser testUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testUser

testBuyToBank: testBuyToBank.cpp menu_methods.cpp color.cpp LinkedUser.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testBuyToBank testBuyToBank.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testBuyToBank

testBuySellHouses: testBuySellHouses.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testBuySellHouses testBuySellHouses.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testBuySellHouses

testOpening: testOpening.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testOpening testOpening.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testOpening


testBuyToPlayer: testBuyPropertyToPlayer.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testBuyToPlayer testBuyPropertyToPlayer.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testBuyToPlayer

testMortage: testMortageProperty.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testMortage testMortageProperty.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testMortage

testReturnAll: testReturnAllProperties.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp
	$(CC) $(CXXFLAGS) -o testReturnAll testReturnAllProperties.cpp menu_methods.cpp LinkedUser.cpp color.cpp property_database.cpp helping_methods.cpp clrscreen_linux.cpp user.cpp $(CFLAGS)
	./testReturnAll
