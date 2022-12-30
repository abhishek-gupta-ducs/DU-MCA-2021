#include<bits/stdc++.h>
using namespace std;
#include "customerStruct.cpp"
/*Queue(using link list) of customer standing in a row for ticket booking*/
class nodeC{
    /*Node of Queue Customer*/
    public:
        customer c;
        nodeC* next;
        nodeC(string name,int n,string pref1,string pref2){
            c.name=name;
            c.ticketNo=n;
            c.pref1=pref1;
            c.pref2=pref2;
            next=NULL;
        }
};
class Queue{
    public:
    nodeC* head;
    Queue(string name,int n,string pref1,string pref2){
        head = new nodeC(name,n,pref1,pref2);
    }
    int size(){
        //customers standing in queue
        int nodeC_num=0;
        nodeC* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            nodeC_num++;
        }
        return nodeC_num-1;
    }
    void enqueue(string name,int n,string pref1,string pref2){
        //customer coming to stand in queue
            nodeC* newNodeC = new nodeC(name,n,pref1,pref2);
            nodeC* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNodeC;
    }
    customer dequeue(){
        //customer going to counter for ticket booking
            customer c = head->c;
            nodeC* temp=head->next;
            head=temp;
            return c;
    }
    void display(){
        //display of customer queue
        nodeC* temp = head->next;
        cout<<"======================================================================\n";
        cout<<"Name                Tickets Required  Preference 1        Preference 2\n";
        cout<<"======================================================================\n";
        while(temp!=NULL){
            cout<<temp->c.name;
            space(temp->c.name.length());
            cout<<temp->c.ticketNo;
            space(3);
            cout<<temp->c.pref1;
            space(temp->c.pref1.length());
            cout<<temp->c.pref2;
            space(temp->c.pref2.length());
            cout<<endl;
            temp=temp->next;
        }
    }
    private:
        void space(int size){
            for(int k=0;k<20-size;k++){
                cout<<" ";
            }
        }
};