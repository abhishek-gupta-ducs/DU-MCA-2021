#include "linklist.cpp"
#include<iostream>
using namespace std;
class queue{
    private:
    linkList ll;
    
    public:
    queue(){
        //parameterised constructor for class stack
        ll = linkList();
        cout<<"Queue Created\n";
    }
    queue(int num){
        //parameterised constructor for class stack
        ll = linkList(num);
        cout<<"Queue Created\n";
    }
    void enqueue(int num){
        ll.insertAtTail(num);
    }
    void dequeue(){
        ll.deleteFromHead();
    }
    void front(){
        int n = ll.showHead();
        cout<<"Value at front is: "<<n<<endl;
    }
    bool isEmpty(){
        return ll.isEmpty();
    }
    void queueDisplay(){
        int n = ll.size();
        for(int i = 0; i<n ;i++){
            cout<<ll.getElementAtPos(i);
            if(i!=n-1){
                cout<<"<---";
            }
        }
        cout<<endl;
    }
    void queueSort(){
        ll.sorting();
    }
};