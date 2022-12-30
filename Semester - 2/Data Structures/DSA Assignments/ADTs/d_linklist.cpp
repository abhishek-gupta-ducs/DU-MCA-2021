#include<bits/stdc++.h>
using namespace std;
class nodes{
    public:
        int data;
        nodes* next;
        nodes* prev;
        nodes(int d){
            data=d;
            next = prev = NULL;
        }
};
class dlinklist{
    public: 
        nodes* head;
        nodes* tail;
        dlinklist(int d){
            head = new nodes(d);
            tail = head;
        }
        void insertAtTail(int d){
            nodes* temp = new nodes(d);
            tail->next = temp;
            temp->prev = tail;
            tail=temp;
        }
        void insertAtHead(int d){
            nodes* temp = new nodes(d);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        void deleteAtHead(){
            if(head->next==tail){
                head = head->next;
                head->next = NULL;
                return;
            }
            nodes* temp = head;
            head = head->next;
            delete temp;
        }
        void deleteAtTail(){
            if(tail->prev==head){
                tail=head;
                head->next=NULL;
                return;
            }
            nodes* temp = tail;
            tail = tail->prev;
            delete temp;
        }
        void display(){
            cout<<"\nDisplay By Head\n";
            nodes* temp = head;
            while(temp!=NULL){
                cout<<temp->data;
                if(temp->next!=NULL){
                    cout<<"-->";
                }
                temp = temp->next;
            }
            cout<<endl;
        }
        bool isEmpty(){
            if(head==NULL)
                return true;
            return false;
        }
};