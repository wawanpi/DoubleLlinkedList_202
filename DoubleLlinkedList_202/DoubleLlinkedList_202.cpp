#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs:
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
		if ()
	}
}