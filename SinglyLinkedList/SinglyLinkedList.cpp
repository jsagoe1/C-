
#include "SinglyLinkedList.h"
#include <iostream>
#include <memory>
#include <set>

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
	return (head == nullptr);
}

template <typename T>
int SinglyLinkedList<T>::size() {
	if (isEmpty()) { return 0; }
	int count = 0;
	std::shared_ptr<ListNode<T>> cur = head;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}

template <typename T>
void SinglyLinkedList<T>::insertFront(T value) {
	if (isEmpty()) {
		head = std::make_shared<ListNode<T>>(value);
		tail = head;
		return;
	}
	std::shared_ptr<ListNode<T>> cur = std::make_shared<ListNode<T>>(value);
	cur->next = head;
	head = cur;
}

template <typename T>
void SinglyLinkedList<T>::insertBack(T value) {
	if (isEmpty()) {
		head = std::make_shared<ListNode<T>>(value);
		tail = head;
		return;
	}
	std::shared_ptr<ListNode<T>> cur = std::make_shared<ListNode<T>>(value);
	tail->next = cur;
	tail = cur;
}

template <typename T>
void SinglyLinkedList<T>::insertAtIndex(int idx, T value) {
	try {
		if (idx > size() - 1) { //if out of range
			throw std::out_of_range("Index out of range!");
		}
		if (idx == 0) { //inserting at head
			insertFront(value);
			return;
		}
		if (idx == size() - 1) { // to be sure tail is set
			std::shared_ptr<ListNode<T>> new_node = std::make_shared<ListNode<T>>(value);
			std::shared_ptr<ListNode<T>> cur = head;
			while (cur->next != tail) {
				cur = cur->next;
			}
			cur->next = new_node;
			new_node->next = tail;
			return;
		}
		int cur_idx = 1;
		std::shared_ptr<ListNode<T>> prev = head;
		std::shared_ptr<ListNode<T>> cur = head->next;
		std::shared_ptr<ListNode<T>> new_node = std::make_shared<ListNode<T>>(value);
		while (cur) {
			if (cur_idx == idx) {
				prev->next = new_node;
				new_node->next = cur;
				return;
			}
			cur = cur->next;
			prev = prev->next;
			cur_idx++;
		}
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
std::ostream& operator <<(std::ostream& os, const SinglyLinkedList<T>& s) {
	//if its empty, return []
	if (s.isEmpty()) {
		os << "[]";
		return os;
	}
	os << "[";
	if (!s.isEmpty() && (s.head == s.tail)) {
		os << s.head->data << "]";
		return os;
	}
	std::shared_ptr<ListNode<T>> cur = s.head;
	while (cur != s.tail) {
		os << cur->data << ", ";
		cur = cur->next;
	}
	os << s.tail->data << "]";
	return os;
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int i) {
	try {
		if (i > size() - 1) {
			throw std::out_of_range("Index out of range");
		}
		int idx = 0;
		std::shared_ptr<ListNode<T>> cur = head;
		while (cur) {
			if (idx == i) {
				return cur->data;
			}
			cur=cur->next;
			idx++;
		}
	}
	catch (std::out_of_range& e) {
			std::cerr << e.what() << std::endl;
	}
}

template <typename T>
void SinglyLinkedList<T>::erase(T value) {
	if (!searchElement(value)) { return; }
	if (value == head->data) {
		removeHead();
		return;
	}
	if (value == tail->data) {
		removeTail();
		return;
	}
	std::shared_ptr<ListNode<T>> prev = head;
	std::shared_ptr<ListNode<T>> cur = head->next;
	while (cur) {
		if (cur->next->data == value) {
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

template <typename T>
void SinglyLinkedList<T>::removeHead() {
	if (size() == 0) { return; }
	if (size() == 1) {
		head = tail = nullptr;
		return;
	}
	std::shared_ptr<ListNode<T>> cur = head->next;
	head = cur;
}

template <typename T>
void SinglyLinkedList<T>::removeTail() {
	if (size() == 0) { return; }
	if (size() == 1) {
		head = tail = nullptr;
		return;
	}
	std::shared_ptr<ListNode<T>> cur = head;
	while (cur->next != tail) {
		cur = cur->next;
	}
	cur->next = nullptr;
	tail = cur;
}

template <typename T>
bool SinglyLinkedList<T>::searchElement(T value) {
	if (isEmpty()) { return false; }
	std::shared_ptr<ListNode<T>> cur = head;
	while (cur) {
		if (cur->data == value) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
	while (size() != 0) {
		removeHead();
	}
}

template <typename T>
void SinglyLinkedList<T>::sort() {
	std::set<T> s;
	while (head != nullptr) {
		s.insert(head->data);
		removeHead();
	}
	if (!s.empty()) {
		typedef std::set<T>::iterator iter;
		for (iter it = s.begin(); it != s.end();  it++) {
			insertBack(*it);
		}
	}
	s.clear();			// to save some memory, instead of delete
}

template <typename T>
void SinglyLinkedList<T>::assign(const SinglyLinkedList<T>& s) {
	std::cout << "copy constructor called" << std::endl;
	if (s.isEmpty()) { return; }
	std::shared_ptr<ListNode<T>> source = s.head;   //returns the stored pointer
	std::cout << "Head copied<<" << source->data << std::endl;
	while (source != nullptr) {
		insertBack(source->data);
		source = source->next;
	}
}
