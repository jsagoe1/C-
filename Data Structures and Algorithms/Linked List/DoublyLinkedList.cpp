#include <iostream>
#include "myDoublyLinkedList.h"

using namespace std;

bool DoublyLinkedList::isEmpty()
{
    return (head == 0 && tail == 0);
}

void DoublyLinkedList::addToHead(int val)
{
    Node *new_node = new Node(val);
    if (isEmpty())          //nothing in list yet
    {
        head = tail = new_node;
    }
    else 
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void DoublyLinkedList::addToTail(int val)
{
    Node *new_node = new Node(val);
    if (isEmpty())
    {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void DoublyLinkedList::addNodeAtIndex(int val, int idx = 0) {
    if (idx >= getSize()){
        addToTail(val);
    }
    else if (idx == 0){
        addToHead(val);
    }
    else {
        Node *new_node = new Node(val);
        Node *cur = head->next;
        Node* prev = head;
        int track = 1;          //one past the head
        while(cur) {
            if (idx == track) {
                prev->next = new_node;
                new_node->next = cur;
                cur->prev = new_node;
                new_node->prev = prev;
                return;
            }
            else {
                cur = cur->next;
                prev=prev->next;
                track += 1;
            }
        }
    }
}

bool DoublyLinkedList::isInList(int val){
    if (isEmpty()) {
        return false;
    }
    else {
        Node* cur = head;
        while(cur){
            if (cur->val == val){
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
}

int DoublyLinkedList::deleteFromHead(){
    if (isEmpty()){
        cout << "List is Empty!"<<endl;
        return -11111111;
    }
    else if (head == tail) {
        int ret = head->val;
        head = tail = 0;
        return ret;
    }
    else {
        int ret = head->val;
        head = head->next;
        head->prev = 0;
        return ret;
    }
}

int DoublyLinkedList::deleteFromTail(){
    if (isEmpty()){
        cout << "List is Empty!!"<<endl;
        return -11111111;
    }
    else if (head == tail)
    {
        int ret = head->val;
        head = tail = 0;
        return ret;
    }
    else
    {
        int ret = tail->val;
        Node *cur = head;
        while (cur->next->next != 0)
        {
            cur = cur->next;
        }
        //at this point, cur is just before tail
        //because tail->next = 0 so cur->next->next = 0
        tail = cur;
        tail->next = 0;
        return ret;
    }
}

void DoublyLinkedList::FindAndDeleteNode(int val){
    if (isInList(val) == 0)
    {
        cout << val << " not in List!" << endl;
    }
    else if (val == head->val)
    {
        deleteFromHead();
    }

    else if (val == tail->val)
    {
        deleteFromTail();
    }
    else 
    {
        Node *prev = head;
        Node *cur = head->next;
        while (cur->next){
            if (cur->val == val){
                prev->next = cur->next;
                prev->next->prev = prev;
            }
            cur = cur->next;
            prev = prev->next;
        }
    }
}

int DoublyLinkedList::getSize(){
    if(isEmpty()){
        return 0;
    }
    else if (head == tail) {
        return 1;
    }
    else {
        int sz = 0;
        Node* cur = head;
        while(cur) {
            cur = cur->next;
            sz+=1;
        }
        return sz;
    }
}

void DoublyLinkedList::printList(){
    cout <<"[";
    if (head==tail && head != 0){
        cout<<head->val;
    }
    else if (!isEmpty() && head != tail){
        Node* cur = head;
        while (cur->next) {     //loop until just before tail
            cout<<cur->val<<" <--> ";
            cur=cur->next;
        }
        cout<<cur->val;         //print the tail
    }
    cout <<"]"<<endl;
}
