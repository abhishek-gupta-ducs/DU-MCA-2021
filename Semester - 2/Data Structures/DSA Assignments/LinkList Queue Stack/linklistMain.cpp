#include<iostream>
using namespace std;
class node{
    //node class to create a node
    public:
        int data;
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
class linkList{
    //linklist ADT
    node* head;
    public:
    linkList(){ //non-perameterised constructor
        *head = node();
        cout<<"Link List Created \n";
    }
    linkList(int num){;//perameterised constructor
        *head=node(num);
        cout<<"Link List Created \n";
    }
    int size(){
        //function to check the size of the link list at any instance
        int linkSize=0;
        node* temp = head;
        while(temp!=NULL){ //traversing through link list
            temp=temp->next;
            linkSize++;
        }
        return linkSize;
    }
    void insertAtBeg(int num){ //function to add an element at the head of list
        node* newNode = new node(num);
        newNode->next = head;
        head=newNode;
        cout<<"Insertion in begining succesfull \n";
    }
    void insertAtTail(int num){ //function to add an element at the tail of list
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        node* newNode = new node(num);
        temp->next=newNode;
        cout<<"Insertion at end succesfull \n";
    }
    void insertAtPos(int pos,int num){ //inseting at any position in the link list
        node* temp=head;
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
            node* newNode = new node(num);
            newNode->next=temp->next;
            temp->next=newNode;
            cout<<"Insertion at position "<<pos<<" succesfull\n";
        }
        else{//if position is not between head and tail
            cout<<"Position does not exist."<<endl;
        }
    }
    void deleteFromHead(){
        //function to delete a node from head of list
        node* temp = head->next;
        head=temp;
        cout<<"Node Delete from head \n";
    }
    void deleteFromTail(){
        //function to delete a node from tail of list
        node* temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        cout<<"Deletion succesfull at tail. \n";
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
            node* temp=head;
            for(int i = 0;i<pos-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            cout<<"Deletion succesfull at position "<<pos<<endl;
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
    int search(int ele){
        //function to search an element in list , and return the index of the element
        int n = size();
        node* temp = head;
        for(int i=0;i<n;i++){
            if(temp->data==ele){
                return i;
            }
            temp=temp->next;
        }
        return -1;
    }
    int getElementAtPos(int pos){
        //function to get element at any position
        node* temp = head;
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
    void display(){
        //function to display the list
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL){
                cout<<"-->";
            }
        }
        cout<<endl;
    }
    void shorting(){
        node* current = head;
        node* index;
        int temp;
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
int main(){
    linkList ll(5);
    ll.insertAtBeg(6);
    ll.display();
    ll.insertAtTail(3);
    ll.display();
    ll.insertAtPos(1,4);
    ll.display();
    ll.shorting();
    ll.display();
    int n = ll.size();
    cout<<"Size of link list is = "<<n<<endl;
    ll.deleteFromHead();
    ll.display();
    ll.deleteFromTail();
    ll.display();
    ll.deleteAtPos(3);
    int m = ll.getElementAtPos(3);
    cout<<m<<endl;
}
