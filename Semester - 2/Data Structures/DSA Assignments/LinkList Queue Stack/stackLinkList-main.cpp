#include<iostream>
#include"stackLinkList.cpp"
using namespace std;
void menu(){
    //menu function to print menu
    cout<<"****************************\n";
    cout<<"       STACK MENU\n";
    cout<<"****************************\n";
    cout<<"       1. Push.\n";
    cout<<"       2. Pop.\n";
    cout<<"       3. Top.\n";
    cout<<"       4. IsEmpty.\n";
    cout<<"       5. Display Stack.\n";
    cout<<"       6. Exit\n";
    cout<<"****************************\n";
}
int inpVal(){
    //function to user input node value
    int val;
    cout<<"Enter value to push: ";
    cin>>val;
    cout<<endl;
    return val;
}
int main(){
    int sVal,ch,val;
    cout<<"Enter first value to push into stack: ";
    cin>>sVal;
    cout<<endl;
    stack ss(sVal);
    bool loop = true;
    while(loop){
        menu();
        cout<<"Enter your choice: ";
        cin>>ch; //user choice for link list operation execution
        cout<<endl;
        if (ch==6){//if user want to exit.
            loop=false;
            cout<<"GoodBye\n";
        }
        else{
            if(ch==1){
                //push element
                val=inpVal();
                ss.push(val);
                cout<<"Push succesfull.\n";
                cout<<endl;
                ss.stackDisplay();
                cout<<endl;
            }
            else if(ch==2){
                //pop element
                if(ss.isEmpty()){
                    //checking if stack is empty
                    cout<<"Empty stack, pop not possible.\n";
                }
                else{
                    ss.pop();
                    cout<<"Element pop succesfull.\n";
                    cout<<endl;
                    ss.stackDisplay();
                    cout<<endl;
                }
            }
            else if(ch==3){
                //getting top element of stack
                if(ss.isEmpty()){
                    //checking if stack is empty
                    cout<<"Empty stack, top element not find.\n";
                }
                else{
                    ss.top();
                }
            }
            else if(ch==4){
                //checking if stack is empty
                if(ss.isEmpty()){
                    cout<<"Stack is empty\n";
                }
                else{
                    cout<<"Stack is not empty.\n";
                }
            }
            else if(ch==5){
                //displaying stack
                if(ss.isEmpty()){
                    //checking if stack is empty
                    cout<<"Empty stack.\n";
                }
                else{
                    ss.stackDisplay();
                    cout<<endl;
                }
            }
            else{
                cout<<"Wrong Choice\n";
            }
        }
    }
}