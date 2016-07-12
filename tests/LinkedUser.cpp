#include <iostream>
#include <string>
#include "user.h"
#include "LinkedUser.h"
#include "helping_methods.h"

using namespace std;

Node::Node()
{
	player = user();
	next = nullptr;
	prev = nullptr;
}

Node::Node(user temp)
{
	player = temp;
	next = nullptr;
	prev = nullptr;
}

user* Node::getUser()
{
	return &player;
}

void Node::setUser(user temp)
{
	player = temp;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* temp)
{
	next = temp;
}

LinkedUser::LinkedUser()
{
	head = nullptr;
	current = head;
	tail = head;
}

LinkedUser::LinkedUser(user temp)
{
	head = new Node(temp);
	current = head;
	tail = head;
}


Node* LinkedUser::getHead()
{
	return head;
}

Node* LinkedUser::getTail()
{
	return tail;
}

Node* LinkedUser::getCurrent()
{
	return current;
}

void LinkedUser::nextCurrent()
{
	current = current->next;
}

void LinkedUser::prevCurrent()
{
	current = current->prev;
}

void LinkedUser::displayList()
{
	Node* ite = head->next;

	if (current != head)
	{
		cout << head->getUser()->getName() << endl;
	}

	while (ite != head)
	{
		if (current != ite)
		{
			cout << ite->getUser()->getName() << endl;
		}
		
		ite = ite->next;

	}

}

void LinkedUser::addUser(user added)
{
	Node* ite = head;
	
	if (head == nullptr)
	{
		head = new Node(added);
		current = tail = head;
		return;
	}
	else
	{
		tail->next = new Node(added);
		tail->next->prev = tail;
		tail = tail->next;
	}
}

bool LinkedUser::removeUser(Node* remove)
{
	if (remove == nullptr)
	{
		cerr << "Error: User wasn't found" << endl;
		return false;
	}

	nextCurrent();
	remove->prev->next = remove->next;
	remove->next->prev = remove->prev;

	if (remove == head)
	{
		head = head->next;
	}

	else if (remove == tail)
	{
		tail = tail->prev;
	}

	delete remove;
	createCyclicList();
	cerr << "User deleted\n";
	return true;
}

void LinkedUser::createCyclicList()
{
	tail->next = head;
	head->prev = tail;
}


user* LinkedUser::obtainUser(string name)
{
	if (head != nullptr && head->getUser()->getName() == name)
	{
		return head->getUser();
	}
	
	Node* ite = head->next;

	while (ite != nullptr)
	{
		if (ite->getUser()->getName() == name)
			return ite->getUser();

		if (ite == head)
		{
			cerr << "User wasn't found" << endl;
			return nullptr;
		}

		ite = ite->next;
	}

	cerr << "User wasn't found" << endl;
	return nullptr;
}

