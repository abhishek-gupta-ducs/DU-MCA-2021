// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;\
class node{
  public:
    int value;
    node* next;
    node(int v){
        value = v;
        next = NULL;
    }
};
class linkList{
    public:
    node* head;
    linkList(int val=0){
        head = new node(val);
    }
    void insertAtTail(int ele){
        node* temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        node* newNode = new node(ele);
        temp->next = newNode;
    }
    void deleteFromHead(){
        if(head->next!=NULL){
            head = head->next;
        }
    }
    void print(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->value;
            if(temp->next!=NULL){
                cout<<"->";
            }
            temp = temp->next;
        }
        cout<<endl;
    }
};
class solution{
    void addTwoNumbers(node* l1, node l2){
        linkList* l3 = new linkList();
        int result =0, carry =0;
        do{
            if(l1->next==NULL){
                result = l2->value + carry;
                l2 = l2->next;
            }
            else if(l2->next==NULL){
                result = l1->value + carry;
                l1 = l1->next;
            }
            else{
                result = l1->value + l2->value + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(result/10>0){
                carry = result/10;
                result = result%10;
            }
            l3.insertAtTail(result);
        }while(l1->next!=NULL || l2->next!=NULL);
        l3.deleteFromHead();
        l3.print();
    }
};
int main(){
    solution s;
    linkList l1 = new linkList(2);
    l1.insertAtTail(4);
    l1.insertAtTail(3);
    linkList l2 = new linkList(5);
    l1.insertAtTail(6);
    l1.insertAtTail(4);
    s.addTwoNumbers(l1.head,l2.head);
}