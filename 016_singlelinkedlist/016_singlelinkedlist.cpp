#include <iostream>
using namespace std;

struct Node {
	int noMhs;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();

	cout << "Masukan Nim  : ";
	cin >> nim;
	cout << "Masukan nama : ";
	cin >> nama;

	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nNim sudah ada!" << endl;
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->noMhs)) {
		if (nim == current->noMhs) {
			cout << "\nNim sudah ada!" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool searchNode(int nim, Node* current, Node* previous) {
	previous = START;
	current = START;

	while (current != NULL && nim > current->noMhs) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		return false;
	}
	else if (current->noMhs == nim) {
		return true;
	}
	else {
		return false;
	}
}

bool deleteNode(int nim) {
	Node* current = START;
	Node* previous = START;

	if (searchNode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = current->next;
	return true;
}

int main(){

}