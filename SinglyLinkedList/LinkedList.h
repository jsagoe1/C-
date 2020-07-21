
#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>

class Node {
public:
	Node(int data) {
		n_data = data;
	}
	~Node() {
		std::cout << "Node " << n_data << " deleted" << std::endl;
	}
	int n_data;
	Node* next = NULL;
};

class SinglyLinkedList {
public:
	//Constructors and destructors
	SinglyLinkedList();
	SinglyLinkedList(int head_data);
	~SinglyLinkedList();

	//insertion and deletion
	void prepend(int data);  //add to front
	void append(int data);    //add to tail
	void insertAfterNode(int existing_data, int data);
	bool find(int data);

	void deleteNode(int data);

	//display
	void printList();

private:
	//helper functions
	bool isEmpty();
	void deallocateList(Node* n_ptr);

	//data
	Node* head;
};



#endif // !SINGLY_LINKED_LIST
