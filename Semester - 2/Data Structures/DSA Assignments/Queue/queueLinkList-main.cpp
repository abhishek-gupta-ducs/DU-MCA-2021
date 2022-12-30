#include<iostream>
#include"queueLinkList.cpp"
using namespace std;
void menu(){
    //menu function to print menu
    cout<<"****************************\n";
    cout<<"       QUEUE MENU\n";
    cout<<"****************************\n";
    cout<<"       1. Enqueue.\n";
    cout<<"       2. Dequeue.\n";
    cout<<"       3. Front element.\n";
    cout<<"       4. IsEmpty.\n";
    cout<<"       5. Display Queue.\n";
    cout<<"       6. Sort Queue.\n";
    cout<<"       7. Exit\n";
    cout<<"****************************\n";
}
int inpVal(){
    //function to user input node value
    int val;
    cout<<"Enter value to enqueue: ";
    cin>>val;
    cout<<endl;
    return val;
}
int main(){
    int sVal,ch,val;
    cout<<"Enter first value to enqueue into queue: ";
    cin>>sVal;
    cout<<endl;
    queue qq(sVal);
    bool loop = true;
    while(loop){
        menu();
        cout<<"Enter your choice: ";
        cin>>ch; //user choice for link list operation execution
        cout<<endl;
        if (ch==7){//if user want to exit.
            loop=false;
            cout<<"GoodBye\n";
        }
        else{
            if(ch==1){
                //enqueue element
                val=inpVal();
                qq.enqueue(val);
                cout<<"Enqueue succesfull.\n";
                cout<<endl;
                qq.queueDisplay();
                cout<<endl;
            }
            else if(ch==2){
                //dequeue element
                if(qq.isEmpty()){
                    //checking if queue is empty
                    cout<<"Empty queue, dequeue not possible.\n";
                }
                else{
                    qq.dequeue();
                    cout<<"Element dequeue succesfull.\n";
                    cout<<endl;
                    qq.queueDisplay();
                    cout<<endl;
                }
            }
            else if(ch==3){
                //getting front element of queue
                if(qq.isEmpty()){
                    //checking if queue is empty
                    cout<<"Empty queue, dequeue not possible.\n";
                }
                else{
                    qq.front();
                }
            }
            else if(ch==4){
                //checking if queue is empty
                if(qq.isEmpty()){
                    cout<<"Queue is empty\n";
                }
                else{
                    cout<<"Queue is not empty.\n";
                }
            }
            else if(ch==5){
                //displaying queue
                if(qq.isEmpty()){
                    //checking if queue is empty
                    cout<<"Empty Queue.\n";
                }
                else{
                    qq.queueDisplay();
                    cout<<endl;
                }
            }
            else if(ch==6){
                //sorting the queue
                if(qq.isEmpty()){
                    //checking if queue is empty
                    cout<<"Empty Queue, Sorting not possible.\n";
                }
                else{
                    cout<<"Queue before sorting: ";
                    qq.queueDisplay();
                    cout<<endl;
                    qq.queueSort();
                    cout<<"Queue after sorting: ";
                    qq.queueDisplay();
                    cout<<endl;
                }
            }
            else{
                cout<<"Wrong Choice\n";
            }
        }
    }
}