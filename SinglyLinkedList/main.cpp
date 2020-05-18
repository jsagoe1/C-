#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
#include "mySinglyLinkedList.cpp"

using namespace std;


int main()
{
    vector<int> vec{23,12,4,6,2,8,19,10};

    SinglyLinkedList ls;
    ls.printList();
    cout << "current size: " << ls.getSize() < <endl;
    ls.addNodeAtIndex(5);
    cout << "current size: " << ls.getSize() << endl;
    ls.printList();
    ls.addToHead(6);
    cout << "current size: " << ls.getSize() << endl;
    ls.addToTail(8);
    cout << "current size: " << ls.getSize() << endl;
    ls.printList();
    for (int x:vec){
        ls.addToTail(x);
    }
    ls.printList();
    cout << "size: " << ls.getSize() << endl;
    cout << ls.deleteFromTail() << endl;
    cout<<ls.deleteFromHead()<<endl;
    ls.printList();
    ls.addNodeAtIndex(17, 4);
    ls.printList();
    ls.FindAndDeleteNode(10);
    ls.printList();
    cout << "current size: " << ls.getSize() << endl;
    return 0;
}
