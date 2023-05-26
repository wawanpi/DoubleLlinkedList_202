#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;

};
class Doublelinkedlist {
private:
	Node* START;
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rolNO, Node** previous, Node** current);
	bool deleteNode(int rolNo);
	bool listEmpty();
	void traverse();
	void retraverse();
	void hapus();
	void searchData();
};

Doublelinkedlist::Doublelinkedlist() {
	START =  NULL;
}

void Doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nm;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; //step 2
	newNode->name = nm; //step 2

	//insert a node in the begininning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL || nim <= START->noMhs) {
			cout << "\Duplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; // step 3
		if (START != NULL)
			START->prev = newNode; // step 4
		newNode->prev = NULL;	// step 5
		START = newNode; //step 6
		return;
	}

	/*inserting a node between two nodes in the list*/
	Node* current = START; //step 1.a
	Node* previouse = NULL; //step 1.b
	while (current->next != NULL && current->next->noMhs < nim) //step 1.c
	{
		previouse = current; // 1.d
		current = current->next; // 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;//step 4
	newNode->prev = current;//step 5
	if (current->next != NULL)
		current->next->prev = newNode;//step 6
	current->next = newNode;//step 7
}

bool Doublelinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = START;//step 1.a
	*current = START;//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) { //step 1.c
		*previous = START; //step 1.d
		*current = START;//step 1.e
	}
	{

	}
}