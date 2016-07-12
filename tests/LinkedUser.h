#ifndef LINKED_USER_H
#define LINKED_USER_H

#include <string>
#include "user.h"

class Node
{
	friend class LinkedUser;

	private:
	  user player;
		Node* next;
		Node* prev;

    public:
		Node();
		explicit Node(user);
		
		user* getUser();
		void setUser(user);

		Node* getNext();
		void setNext(Node*);
		
};

class LinkedUser
{
private:
	Node* head;
	Node* tail;
	Node* current;
	
	
public:
	LinkedUser();
	explicit LinkedUser(user);

	//void eliminateFirst(LinkedUser*);
	Node* getHead();
	Node* getTail();
	Node* getCurrent();
	void nextCurrent();
	void prevCurrent();
	void addUser(user);
	bool removeUser(Node*);
	void createCyclicList();
	user* obtainUser(string name);
	//void opening(LinkedUser*);
	void clearList(LinkedUser*);
	void displayList();
};



#endif
