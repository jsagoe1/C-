#include <iostream>
#include "SinglyLinkedList.cpp"
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList<int> s;
	SinglyLinkedList<int> q;
	for (int i = 0; i < 5; i += 1) {
		s.insertFront(i);
	}
	cout << "s:" << s << endl;
	s.insertAtIndex(4, 10);
	cout << "s:" << s << endl;
	s.erase(2);
	cout << "s:" << s << endl;
	s.sort();
	cout << "s:" << s << endl;
	s.erase(4);
	q.assign(s);
	cout << "s:" << s << endl;
	cout << "q:" << q << endl;
	s.erase(10);
	cout << "s:" << s << endl;
	cout << "q:" << q << endl;
	return 0;
}
