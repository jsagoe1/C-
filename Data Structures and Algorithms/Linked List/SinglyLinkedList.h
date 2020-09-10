/* 
Singly Linked List Class template
using smart pointers
*/

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <memory>
#include <iostream>

template <typename T>
class ListNode {
public:
	ListNode<T>() { next = nullptr; };
	ListNode<T>(T val) { data = val; next = nullptr; };

	T data;
	std::shared_ptr<ListNode<T>> next;
};

template <typename T>
class SinglyLinkedList {
public:
	SinglyLinkedList<T>() { head = nullptr; tail = nullptr; };	
	void insertFront(T value);								//insertfront
	void insertBack(T value);								//insertback
	void insertAtIndex(int idx, T value);							//insertAtindex
	void erase(T value);									//remove Node
	bool searchElement(T value);								//searchElement
	bool isEmpty() const;
	void clear();
	void assign(const SinglyLinkedList<T>& s);
	void sort();
	int size();

	template <typename T>
	friend std::ostream& operator <<(std::ostream& os, const SinglyLinkedList<T>& s);	//ostream overload 
	T&  operator[](int i);									//subscripting operator overload
											
	
private:
	std::shared_ptr<ListNode<T>> head, tail;
	void removeHead();
	void removeTail();
};

#endif
