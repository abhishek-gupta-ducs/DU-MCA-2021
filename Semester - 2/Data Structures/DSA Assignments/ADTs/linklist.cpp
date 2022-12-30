#include<iostream>
using namespace std;
template<typename T>
class node{
    //node class to create a node
    public:
        T data;
        node* next;
    node(){
        data=-1;
        next=NULL;
    }
    node(int ele){
        data=ele;
        next=NULL;
    }
};
template<typename T>
class linkList{
    //linklist ADT
    node <T>* head;
    public:
    linkList(){ //non-perameterised constructor
        head = new node<T>();
    }
    linkList(T num){;//perameterised constructor
        head= new node<T>(num);
    }
    int size(){
        //function to check the size of the link list at any instance
        int linkSize=0;
        node <T>* temp = head;
        while(temp!=NULL){ //traversing through link list
            temp=temp->next;
            linkSize++;
        }
        return linkSize;
    }
    void insertAtBeg(T num){ //function to add an element at the head of list
        node <T>* newNode = new node<T>(num);
        newNode->next = head;
        head=newNode;
    }
    void insertAtPos(int pos,T num){ //inseting at any position in the link list
        node <T>* temp=head;
        if(pos==0){//if position is head
            insertAtBeg(num);
        }
        else if(pos>0 && pos<size()-1){//if position is between head and tail
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            node <T>* newNode = new node<T>(num);
            newNode->next=temp->next;
            temp->next=newNode;
        }
        else{//if position is not between head and tail
            cout<<"Position does not exist."<<endl;
        }
    }
    void deleteFromHead(){
        //function to delete a node from head of list
        node <T>* temp = head->next;
        head=temp;
    }
    void display(){
        //function to display the list
        node<T>* temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL){
                cout<<"-->";
            }
        }
        cout<<endl;
    }
    void selection_sort(){
        node<T>* current = head;
        node<T>* index;
        T temp;
        if(isEmpty()){
            return; 
        }
        else{
            while(current!=NULL){
                //display();
                index = current->next;
  	            while (index != NULL) {
                    if (current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
    	            }
    	            index = index->next;
  	            }
                
  	            current = current->next;
            }
        }
    }
};
