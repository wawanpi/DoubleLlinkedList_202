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
	Node*
}