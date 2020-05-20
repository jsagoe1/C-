#include <iostream>
#include <vector>
#include "myDoublyLinkedList.cpp"

using namespace std;


int main()
{
    vector<int> vec{23,12,4,6,2,8,19,10};

    DoublyLinkedList ls;
    ls.printList();
    cout << "current size: " << ls.getSize() <<endl;
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

//>###################### OUTPUT #####################
//> []
//> current size: 0
//> current size: 1
//> [5]
//> current size: 2
//> current size: 3
//> [6 <--> 5 <--> 8]
//> [6 <--> 5 <--> 8 <--> 23 <--> 12 <--> 4 <--> 6 <--> 2 <--> 8 <--> 19 <--> 10]
//> size: 11
//> 10
//> 6
//> [5 <--> 8 <--> 23 <--> 12 <--> 4 <--> 6 <--> 2 <--> 8 <--> 19]
//> [5 <--> 8 <--> 23 <--> 12 <--> 17 <--> 4 <--> 6 <--> 2 <--> 8 <--> 19]
//> 10 not in List!
//> [5 <--> 8 <--> 23 <--> 12 <--> 17 <--> 4 <--> 6 <--> 2 <--> 8 <--> 19]
//> current size: 10
