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
	bool search(int rollno, Node** cahya, Node** atama);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { 
	int rollNo;
	string name;

	cout << "\nEnter roll number: ";
	cin >> rollNo;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);

	Node* newNode = new Node();
	newNode->rollNumber = rollNo;
	newNode->name = name;

	if (listEmpty()) {
		newNode->next = newNode;
		LAST = newNode;
	}
	else {
		Node* atama;
		Node* cahya = LAST;
		atama = LAST->next;

		while (atama != LAST && atama->rollNumber < rollNo) {
			cahya = atama;
			atama = atama->next;
		}

		cahya->next = newNode;
		newNode->next = atama;

		if (atama == LAST && atama->rollNumber < rollNo) {
			LAST = newNode;
		}
	}
}
bool CircularLinkedList::search(int rollno, Node** cahya, Node** atama) {
	*cahya = LAST->next;
	*atama = LAST->next;
	while (*atama != LAST) {
		if (rollno == (*atama)->rollNumber) {
			return true;
		}
		*cahya = *atama;
		*atama = (*atama)->next;
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
bool CircularLinkedList::delNode() {
	if (listEmpty()) {
		cout << "\nList Kosong. Penghapusan Gagal!" << endl;
		return false;
	}

	int rollNo;
	cout << "\nMasukan roll number yang ingin di hapus: ";
	cin >> rollNo;

	Node* cahya = NULL;
	Node* atama = NULL;

	if (!search(rollNo, &cahya, &atama)) {
		cout << "Node Tidak ditemukan. Penghapusan Gagal!" << endl;
		return false;
	}

	if (cahya == atama) { // hanya ada 1 node di list
		LAST = NULL;
		delete atama;
		cout << "Node Berhasil Dihapus!" << endl;
		return true;
	}

	if (atama == LAST) { // menghapus node di akhir
		LAST = cahya;
	}

	cahya->next = atama->next;
	delete atama;

	cout << "Node Berhasil Dihapus!" << endl;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList Kosong\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* atamaNode = LAST->next;
		while (atamaNode != LAST) {
			cout << atamaNode->rollNumber << " " << atamaNode->name << endl;
			atamaNode = atamaNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
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