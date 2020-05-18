
using namespace std;

class Node {
    public:
    Node(int v, Node* n = 0) {
        val = v; next = n;
    }

    int val;
    Node* next;
};

class SinglyLinkedList {
    public:
        SinglyLinkedList()
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
