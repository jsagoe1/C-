#include <iostream>
#include "LinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
	head = NULL;
}

SinglyLinkedList::SinglyLinkedList(int data) {
	head = new Node(data);
}

SinglyLinkedList::~SinglyLinkedList() {
	deallocateList(head);
	std::cout << "Linked List deleted!!" << std::endl;
}

void SinglyLinkedList::prepend(int data) {
	if (head == NULL) {
		head = new Node(data);
		return;
	}
	else {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return;
	}
}

void SinglyLinkedList::append(int data) {
	if (head == NULL) {
		head = new Node(data);
		return;
	}
	else {
		Node* newNode = new Node(data);
		Node* curNode = head;
		while (curNode->next != NULL) {
			curNode = curNode->next;
		}
		//at this point, cur->next is NULL (at last Node)
		curNode->next = newNode;
		return;
	}
}

void SinglyLinkedList::insertAfterNode(int existing_data, int data) {
	if (find(existing_data)) {
		for (Node* cur = head; cur != NULL; cur=cur->next) {
			if (cur->n_data == existing_data) {
				Node* newNode = new Node(data);
				newNode->next = cur->next;
				cur->next = newNode;
				return;
			}
		}
	}
	else {
		append(data);
	}
}

bool SinglyLinkedList::find(int data) {
	if (isEmpty()) {
		return false;
	}
	else {
		for (Node* cur = head; cur != NULL; cur = cur->next) {
			if (cur->n_data == data) {
				return true;
			}
		}
		return false;
	}
}

void SinglyLinkedList::deleteNode(int data) {
	if (isEmpty() || !find(data)) {
		return;
	}
	else {
		if (head->n_data == data) {
			Node* cur = head->next;
			//cleanup floating Node after dereferencing
			delete head;
			head = cur;
			return;
		}
		else {
			Node* cur = head;
			Node* prev = NULL;

			while (cur != NULL && cur->n_data!=data){
				prev = cur;
				cur = cur->next;
			}
			//at this point, either cur is null and prev is tail or 
			//cur->n_data = data and prev is node just before cur
			prev->next = cur->next;
			//clean up floating Node after dereferencing
			delete cur;
			return;
		}
	}
}

void SinglyLinkedList::printList() {
	if (isEmpty()) {
		std::cout << "List is Empty" << std::endl;
		return;
	}
	else {
		Node* cur = head;
		while (cur != NULL) {
			std::cout << cur->n_data << std::endl;
			cur = cur->next;
		}
		return;
	}
}

bool SinglyLinkedList::isEmpty() {
	return (head == NULL);
}

void SinglyLinkedList::deallocateList(Node* n_ptr) {
	if (n_ptr != NULL) {
		Node* cur = n_ptr->next;
		delete n_ptr;
		//recursive deletion
		deallocateList(cur);
	}
}

