#include<bits/stdc++.h>
using namespace std;
//stack of tickets for any particular stall(front/middle/balcony)
class node{
    public:
    //ticket with seat number
        int seat;
        node* next;
        node(int n){
            seat=n;
            next=NULL;
        }
};
class stall{
    public:
    //stack of tickets
        node* top;
        int size=0;
        stall(int start,int end){
            /*Constructor of class stall, it will take starting no of ticket
            and last no of ticket and genrate the stack of tickets.
            (1-30) for front stall,
            (31-70) for middle stall,
            (71,100) for balcony stall*/
            top = new node(start);
            size++;
            for(int seat=start+1;seat<end+1;seat++){
                size++;
                push(seat);
            }
        }
        void push(int n){
            //pushing ticket into stack
            node* newNode = new node(n);
            newNode->next=top;
            top=newNode;
        }
        int pop(){
            //popping ticket from stack for issuinng it to customer
            int n = top->seat;
            node* temp = top->next;
            top=temp;
            size--;
            return n;
        }
};