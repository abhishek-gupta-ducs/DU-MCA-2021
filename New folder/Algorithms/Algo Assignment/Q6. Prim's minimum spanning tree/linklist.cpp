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
    node(T ele){
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
    void insertAtTail(T num){ //function to add an element at the tail of list
        node <T>* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        node<T>* newNode = new node<T>(num);
        temp->next=newNode;
    }
    void insertAtPos(int pos,T num){ //inseting at any position in the link list
        node <T>* temp=head;
        if(pos==0){//if position is head
            insertAtBeg(num);
        }
        else if(pos==size()-1){//if position is tail
            insertAtTail(num);
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
    void deleteFromTail(){
        //function to delete a node from tail of list
        int n = size();
        if(n==1){
            deleteFromHead();
        }
        else{
            node <T>* temp = head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
        }
    }
    void deleteAtPos(int pos){
        //function to delete a node from any position
        if(pos==0){//if position is head
            deleteFromHead();
        }
        else if(pos==size()-1){//if position is tail
            deleteFromTail();
        }
        else if(pos>0 && pos<size()-1){//if position between head and tail
            node<T>* temp=head;
            for(int i = 0;i<pos-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
        else{//if position does not exist
            cout<<"Position does not exist.\n";
        }       
    }
    bool isEmpty(){
        //function to check if function is empty or not
        if(head==NULL){
            return true;
        }
        return false;
    }
    int search(T ele){
        //function to search an element in list , and return the index of the element
        int n = size();
        node<T>* temp = head;
        for(int i=0;i<n;i++){
            if(temp->data==ele){
                return i;
            }
            temp=temp->next;
        }
        return -1;
    }
    T getElementAtPos(int pos){
        //function to get element at any position
        node<T>* temp = head;
        if(pos>=0 && pos<=size()-1){
            int i=0;
            while(i!=pos){
                temp=temp->next;
                i++;
            }
            return temp->data;
        }
        else{
            return -1;
        }
    }
    bool elementBelongsTo(T ele){
        int n = size();
        node<T>* temp = head;
        for(int i = 0; i<n ; i++){
            if(temp->data == ele){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    int deleteElement(T ele){
        //function to delete any element from link list
        int flag = 0;
        if(head->data == ele){
            //if element at head node
            deleteFromHead();
            return 1;
        }
        else{
            node<T>* temp = head;
            while(temp->next!=NULL && flag!=1){
                //traversing linklist
                if(temp->next->data == ele){
                    if(temp->next->next != NULL){
                        //deleteing element from list
                        temp->next = temp->next->next;
                        flag=1;
                    }
                    else{
                        //if deleted element is tail of list
                        temp->next = NULL;
                        flag=1;
                    }
                }
                else{
                    temp = temp->next;
                }
            }
            return flag;
        }
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
    T showHead(){
        //showHead function to retrive head of list
        return head->data;
    }
    void sorting(){
        node<T>* current = head;
        node<T>* index;
        T temp;
        if(isEmpty()){
            return; 
        }
        else{
            while(current!=NULL){
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