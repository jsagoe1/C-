#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;


int main() {
	SinglyLinkedList list1(0);
	int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		list1.append(arr[i]);
	}
	list1.insertAfterNode(10, 9);
	list1.printList();
	list1.deleteNode(9);
	list1.printList();
	return 0;
}
