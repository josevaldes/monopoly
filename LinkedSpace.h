
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

	Node* getHead();
	Node* getTail();
	Node* getCurrent();
	void nextCurrent();
	void prevCurrent();
	void addUser(user);
	bool removeUser(Node*);
	void createCyclicList();
	void clearList(LinkedUser*);
	void displayList();
};



