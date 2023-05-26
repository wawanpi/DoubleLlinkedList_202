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

class DoubleLinkedList {
private:
    Node* START;
public:
    DoubleLinkedList();
    void addNode();
    bool search(int rollNo, Node** previous, Node** current);
    bool deleteNode(int rollNo);
    bool listEmpty();
    void traverse();
    void revtraverse();
    void hapus();
    void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
    START = NULL;
}

void DoubleLinkedList::addNode() {
    int nim;
    string nm;
    cout << "\nEnter the roll number of the student : ";
    cin >> nim;
    cout << "\nEnter the name of student : ";
    cin >> nm;
    Node* newNode = new Node();                                 //Step 1
    newNode->noMhs = nim;                                       //Step 2
    newNode->name = nm;                                         //Step 2

    /*Insert a node in the beginning of a doubly - linked list*/
    if (START == NULL || nim <= START->noMhs) {
        if (START != NULL && nim == START->noMhs) {
            cout << "\nDuplicate number not Allowed" << endl;
            return;
        }
        newNode->next = START;                                  //Step 3
        if (START != NULL)
            START->prev = newNode;                              //Step 4
        newNode->prev = NULL;                                   //Step 5
        START = newNode;                                        //Step 6
        return;
    }

    /*Inserting a node between Two Node in the List*/
    Node* current = START;                                          //Step 1.a
    Node* previous = NULL;                                          //Step 1.b
    while (current->next != NULL && current->next->noMhs < nim)     //Step 1.c
    {
        previous = current;                                         //1.d
        current = current->next;                                    // 1.e
    }

    if (current->next != NULL && nim == current->next->noMhs) {
        cout << "\nDuplicate roll number not allowed" << endl;
        return;
    }

    newNode->next = current->next;                                  //Step 4
    newNode->prev = current;                                        //Step 5
    if (current->next != NULL)
        current->next->prev = newNode;                              //Step 6
    current->next = newNode;                                         //Step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
    *previous = NULL;                                               //Step 1.a
    *current = START;                                               //Step 1.b
    while (*current != NULL && (*current)->noMhs != rollNo) {       //Step 1.c
        *previous = *current;                                   //Step 1.d
        *current = (*current)->next;                            //Step 1.e
    }
    return(*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
    Node* previous, * current;
    previous = current = NULL;
    if (search(rollNo, &previous, &current) == false)
        return false;
    if (current->next != NULL)
        current->next->prev = previous;                         //Step 2
    if (previous != NULL)
        previous->next = current->next;                         //Step 3
    else
        START = current->next;

    delete current;                                             //Step 4
    return true;
}

bool DoubleLinkedList::listEmpty() {
    return (START == NULL);
}

void DoubleLinkedList::traverse() {
    if (listEmpty())
        cout << "\nList is Empty" << endl;
    else {
        cout << "\nRecords in Ascending order of roll number are : " << endl;
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void DoubleLinkedList::revtraverse() {
    if (listEmpty()) {
        cout << "\nList is Empty" << endl;
    }

    else {
        cout << "\nRecords in Descending order of roll number are : " << endl;
        Node* currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL) {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void DoubleLinkedList::hapus() {
    if (listEmpty()) {
        cout << "\nList is Empty" << endl;
    }

    cout << "\nEnter the roll number of the student whose record is to be deleted : ";
    int rollNo;
    cin >> rollNo;
    cout << endl;
    if (DoubleLinkedList::deleteNode(rollNo) == false)
        cout << "Record Not Found" << endl;
    else
        cout << "Record with roll number " << rollNo << " deleted" << endl;
}

void DoubleLinkedList::searchData() {
    if (listEmpty() == true) {
        cout << "\nList is Empty" << endl;
    }

    Node* prev, * curr;
    prev = curr = NULL;
    cout << "\nEnter The Roll Number of the Student whose Record you want to Search : ";
    int num;
    cin >> num;
    if (DoubleLinkedList::search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else {
        cout << "\nRecord found" << endl;
        cout << "\nRoll Number : " << curr->noMhs << endl;
        cout << "\nName : " << curr->name << endl;
    }
}

int main()
{
    DoubleLinkedList obj;
    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View All records in the ascending order of roll numbers" << endl;
            cout << "4. View All records in the descending order of roll numbers" << endl;
            cout << "5. Search for a record in the list" << endl;
            cout << "6. Exit" << endl;
            cout << "\nEnter Your Choice(1 - 6) : ";
            char ch;
            cin >> ch;

            switch (ch) {
            case '1':
                obj.addNode();
                break;
            case '2':
                obj.hapus();
                break;
            case '3':
                obj.traverse();
                break;
            case '4':
                obj.revtraverse();
                break;
            case '5':
                obj.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
    }
}