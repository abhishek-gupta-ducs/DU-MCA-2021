#include<iostream>
#include"linklist.cpp"
using namespace std;
void menu(){
    //menu function to print menu
    cout<<"****************************\n";
    cout<<"       LINK LIST MENU\n";
    cout<<"****************************\n";
    cout<<"1. Insert into head.\n";
    cout<<"2. Insert into tail.\n";
    cout<<"3. Insert into position.\n";
    cout<<"4. Delete from head.\n";
    cout<<"5. Delete from tail.\n";
    cout<<"6. Search any element.\n";
    cout<<"7. Is link list empty.\n";
    cout<<"8. Size of link list.\n";
    cout<<"9. Exit\n";
    cout<<"****************************\n";
}
int inpVal(){
    //function to user input node value
    int val;
    cout<<"Enter node value: ";
    cin>>val;
    cout<<endl;
    return val;
}
int main(){
    bool loop = true;
    int ch,val,nVal;
    cout<<"Enter the value of head node: ";
    cin>>nVal; //taking the value of head node, to avoid the situation of garbage value
    cout<<endl;
    linkList <int>ll(nVal); //creating the link list
    while(loop){
        menu();
        cout<<"Enter your choice: ";
        cin>>ch; //user choice for link list operation execution
        cout<<endl;
        if (ch==9){//if user want to exit.
            loop=false;
            cout<<"GoodBye\n";
        }
        else{
            if(ch==1){
                //insertion at head
                val=inpVal();
                ll.insertAtBeg(val);
                cout<<"Insertion succesfull.\n";
                cout<<endl;
                ll.display();
                cout<<endl;
            }
            else if(ch==2){
                //insertion at tail
                val=inpVal();
                ll.insertAtTail(val);
                cout<<"Insertion succesfull.\n";
                cout<<endl;
                ll.display();
                cout<<endl;
            }
            else if(ch==3){
                //insertion at any position user want
                int pos;
                int n = ll.size();
                cout<<endl;
                ll.display();
                cout<<endl;
                cout<<"Enter the index you want to enter node: ";
                cin>>pos;
                val=inpVal();
                ll.insertAtPos(pos,val);
                if(n<ll.size()){
                    //if insertion succesfully take place
                    cout<<"Insertion succesfull.\n";
                    cout<<endl;
                    ll.display();
                    cout<<endl;
                }
            }
            else if(ch==4){
                //deletion from head
                if(ll.isEmpty()){
                    //checking if list is empty
                    cout<<"Not Possible, Empty List\n";
                }
                else{
                    ll.deleteFromHead();
                    cout<<"Deletion succesfull.\n";
                    cout<<endl;
                    ll.display();
                    cout<<endl;
                }
            }
            else if(ch==5){
                //deletion from tail
                if(ll.isEmpty()){
                    //checking if list is empty
                    cout<<"Not Possible, Empty List\n";
                }
                else{
                    ll.deleteFromTail();
                    cout<<"Deletion succesfull.\n";
                    cout<<endl;
                    ll.display();
                    cout<<endl;
                }
            }
            else if(ch==6){
                //searching a value in link list
                if(ll.isEmpty()){
                    //checking if list is empty
                    cout<<"Not Possible, Empty List\n";
                }
                else{
                    cout<<"Enter value you want to search : ";
                    cin>>val;
                    cout<<endl;
                    int index = ll.search(val);
                    if(index==-1){
                        cout<<"Element not found\n";
                    }
                    else{
                        cout<<"Element found at index "<<index<<endl;
                        cout<<endl;
                        ll.display();
                        cout<<endl;
                    }
                }
            }
            else if(ch==7){
                //checking if list is empty
                if(ll.isEmpty()){
                    cout<<"List is Empty\n";
                }
                else{
                    cout<<"List is not empty\n";
                    cout<<endl;
                    ll.display();
                    cout<<endl;
                }
            }
            else if(ch==8){
                //getting number of nodes in the link list
                int size = ll.size();
                cout<<"Size of link list is: "<<size<<endl;
                cout<<endl;
                ll.display();
                cout<<endl;                
            }
            else{
                cout<<"Wrong choice\n";
            }
        }
        
    }
}