/*c_array is an array implemented using link list, functions of c_array are:
 1. nextValue :- To insert value into the array (insert at tail of link list),
 2. at :- To get the value at any index of array,
 3. length :- to get the length of array
 4. display :- to display array
 5. end :- to delete the array and free memory
 6. sort :- to sort the array */

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    string t_no;
    node* next;
    node(string t="NULL"){
        t_no=t;
        next=NULL;
    }
};
class c_array{
    public:
    node* head;
    c_array(){
        //non-parameterised constructor of class c_array
        head = new node();
    }
    c_array(string t){
        //parameterised constructor of class c_array
        head = new node(t);
    }
    void nextValue(string t){
        /*nextValue function will take the string 
        type value and insert at end the of array*/
        node* newNode = new node(t);
        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    string at(int index){
        /*at() function will take index of value as parameter and return the 
        value at the same index*/
        if(index<0 || index > length()){
            return "Index out of range";
        }
        node* temp = head;
        for(int i =0;i<index;i++){
            temp=temp->next;
        }
        return temp->t_no;
    }
    int length(){
        /*length function will return the length of array (implemented by link list)*/
        int n=0;
        node* temp = head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }
    void display(){
        //display function will print the array
        if(head==NULL){
            return;
        }
        node* temp = head;
        cout<<"List\n";
        while(temp!=NULL){
            cout<<temp->t_no<<endl;
            temp=temp->next;
        }
    }
    void end(){
        //end function will delete all nodes and free the memory
        node* temp;
        while(temp->next!=NULL){
            temp=head;
            head=head->next;
            free(temp);
        }
    }
    void sort(){
        //sort function will sort the array using bubble sort
        node* current = head;
        node* index;
        string temp;
        if(head==NULL){
            return; 
        }
        else{
            while(current!=NULL){
                index = current->next;
  	            while (index != NULL) {
                    if (current->t_no > index->t_no) {
                        temp = current->t_no;
                        current->t_no = index->t_no;
                        index->t_no = temp;
    	            }
    	            index = index->next;
  	            }
  	            current = current->next;
            }
        }
    }
};