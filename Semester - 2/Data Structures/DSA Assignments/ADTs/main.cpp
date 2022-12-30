#include<bits/stdc++.h>
#include "linklist.cpp"
#include "d_linklist.cpp"
using namespace std;
int main(){
    linkList<int> ll(3);
    ll.insertAtTail(34);
    ll.insertAtBeg(12);
    ll.insertAtTail(5);
    ll.display();
    ll.selection_sort();

    dlinklist l1(2);
    l1.insertAtHead(5);
    l1.insertAtTail(6);
    l1.display();
    l1.deleteAtHead();
    l1.display();
    l1.deleteAtTail();
    l1.display();
    bool pos = l1.isEmpty();
    cout<<pos<<endl;
    l1.deleteAtHead();
    l1.display();
    pos = l1.isEmpty();
    cout<<pos<<endl;
}