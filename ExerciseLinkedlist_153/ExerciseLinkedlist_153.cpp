#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();

	bool search(int rollno, Node** previous, Node** current);

	bool listEmpty();

	bool delNode();

	void traverse();
};
void CircularLinkedList::addNode() { //Write answer here
	int nim;
	string name;
	cout << "\nEnter the roll number";
	cin >> nim;
	cout << "\nEnter the name";
	cin >> name;
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = name;
	if (LAST == NULL || nim <= LAST->rollNumber) {
		cout << "\nDuplicate number not allowed" << endl;
		return;
	}
	newNode->next = LAST;
	if (LAST != NULL)
		LAST->next = newNode;
	newNode->next = NULL;
	LAST = newNode;
	return;

}
bool CircularLinkedList::search(int rollno, Node** Anshari, Node** Azmi) {
	*Anshari = LAST->next;
	*Azmi = LAST->next;

	while (*Azmi != LAST) {
		if (rollno == (*Azmi)->rollNumber) {
			return true;
		}
		*Anshari = *Azmi;
		*Azmi = (*Azmi)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(){ // Write answer here
	Node* Anshari, * Azmi;
	Anshari = Azmi = NULL;
	if (search(&Anshari, &Azmi) == false)
		return false;
	if (Azmi->next != NULL)
		Azmi->next= Anshari;		
	if (Anshari != NULL)
		Anshari->next = Azmi->next;		
	else
		LAST = Azmi->next;

	delete Azmi;							
	return true;
	
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is Empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << "	" << currentNode->name << endl;
		}
		cout << LAST->rollNumber << "" << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the record in the list" << endl;
			cout << "4. exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1' :{
				obj.addNode();
				break;
				}
			case '2': {
				obj.delNode();
				break;
			}
			case '3':{
				obj.traverse();
				break;
				}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}