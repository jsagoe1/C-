#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
#include "mySinglyLinkedList.h"

using namespace std;


void SinglyLinkedList::addNodeAtIndex(int val, int idx = 0) {
    if (idx >= getSize()){
        addToTail(val);
    }
    else if (idx == 0){
        addToHead(val);
    }
    else {
        Node *new_node = new Node(val);
        Node *cur = head;
        int track = 1;          //one past the head
        while(cur) {
            if (idx == track) {
                new_node->next = cur->next;
                cur->next = new_node;
                return;
            }
            else {
                cur = cur->next;
                track += 1;
            }
        }
    }
}

bool SinglyLinkedList::isEmpty() {
    return (head == 0);
}

void SinglyLinkedList::addToHead(int val) {
    Node* new_node = new Node(val);
    if (isEmpty()){
        head = tail = new_node;
    }
    else if (head == tail and head != 0){
        new_node->next = head;
        head = new_node;
    }
}

void SinglyLinkedList::addToTail(int val) {
    Node *new_node = new Node(val);
    if (isEmpty()){
        head = tail = new_node;
    }
    else if (head == tail && head != 0) {
        head->next = new_node;
        tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
}

bool SinglyLinkedList::isInList(int val){
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

int SinglyLinkedList::deleteFromHead(){
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
        return ret;
    }
}

int SinglyLinkedList::deleteFromTail(){
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

void SinglyLinkedList::FindAndDeleteNode(int val){
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
            }
            cur = cur->next;
            prev = prev->next;
        }
    }
}

int SinglyLinkedList::getSize(){
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

void SinglyLinkedList::printList(){
    cout <<"[";
    if (head==tail && head != 0){
        cout<<head->val;
    }
    else if (!isEmpty() && head != tail){
        Node* cur = head;
        while (cur->next) {     //loop until just before tail
            cout<<cur->val<<"->";
            cur=cur->next;
        }
        cout<<cur->val;         //print the tail
    }
    cout <<"]"<<endl;
}
