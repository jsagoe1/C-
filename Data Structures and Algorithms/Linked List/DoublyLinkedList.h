#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST


class Node {
    public:
    Node(){
        next = 0; prev = 0;
    }
    Node(int v) {
        val = v; next = 0; prev = 0;
    }

    int val;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    public:
        DoublyLinkedList()
        {
            head = tail = 0;
        }
        void addNodeAtIndex(int, int);
        bool isEmpty();
        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();
        void FindAndDeleteNode(int);
        bool isInList(int);
        int getSize();
        void printList();
    private:
        Node *head;
        Node *tail;
};

#endif
