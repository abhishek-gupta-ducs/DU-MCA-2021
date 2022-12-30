#include "linklist.cpp"
#include<iostream>
using namespace std;
class stack{
    private:
    linkList ll;
    
    public:
    stack(){
        ll = linkList();
        cout<<"Stack Created\n";
    }
    stack(int num){
        ll = linkList(num);
        cout<<"Stack Created\n";
    }
    void push(int num){
        ll.insertAtBeg(num);
    }
    void pop(){
        ll.deleteFromHead();
    }
    void top(){
        int n = ll.showHead();
        cout<<"Value at top is: "<<n<<endl;
    }
    bool isEmpty(){
        return ll.isEmpty();
    }
    void stackDisplay(){
        int n = ll.size();
        cout<<"-----------\n";
        for(int i = 0; i<n ;i++){
            cout<<"|     "<<ll.getElementAtPos(i)<<"   |"<<endl;
            cout<<"-----------\n";
        }
    }
};