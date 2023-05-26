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
	void hapus();
	void searchData();
};