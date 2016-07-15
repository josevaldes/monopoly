CC=g++
CFLAGS = -lncurses
CXXFLAGS = -std=c++11

make: clrscreen_linux.cpp color.cpp helping_methods.cpp Interfaces_Menu.cpp LinkedUser.cpp main.cpp menu_methods.cpp property_database.cpp user.cpp Board.cpp 
	$(CC) $(CXXFLAGS) -o monopoly clrscreen_linux.cpp color.cpp helping_methods.cpp Interfaces_Menu.cpp LinkedUser.cpp main.cpp menu_methods.cpp property_database.cpp user.cpp Board.cpp $(CFLAGS)
