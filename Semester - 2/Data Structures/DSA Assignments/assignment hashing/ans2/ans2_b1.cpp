#include<iostream>
#include<string>
#include"linklist.cpp"
using namespace std;
class hashChain{
    public:
    int collision = 0;
    linkList <long>hashTable[17];
    int hashFunction(long number){
        int sumN = sum(number);
        return sumN%17;
    }
    int sum(long n,int sumN=0){
        if(n/10==0){
            sumN+=n;
            return sumN;
        }
        else{
            sumN+=n%10;
            return(sum(n/10,sumN));
        }
    }
    void insert(long number){
        int index = hashFunction(number);
        hashTable[index].insertAtTail(number);
        if(hashTable[index].size()>2){
            collision+=1;
        }
        cout<<"Insertion Succesfull"<<endl;
        return;
    }
    void search(long number){
        int index = hashFunction(number);
        int nodeIndex = hashTable[index].search(number);
        if(nodeIndex == -1){
            cout<<"Element not found"<<endl;
            return;
        }
        cout<<"Element found at index "<<index<<" and node "<<nodeIndex<<endl;
    }
    void remove(long number){
        int index = hashFunction(number);
        int nodeIndex = hashTable[index].search(number);
        if(nodeIndex == -1){
            cout<<"Element not in hashtable to delete"<<endl;
        }
        else{
            if(hashTable[index].size()>2){
                collision-=1;
            }
            hashTable[index].deleteAtPos(nodeIndex);
            cout<<"Deleteion Succefull"<<endl;
        }
    }
    void display(){
        cout<<"Index         Nodes"<<endl;
        for(int i = 0 ; i<17 ; i++){
            if(i>9){
                cout<<i;
                cout<<"            ";
                hashTable[i].display();
                continue;
            }
            cout<<i;
            cout<<"             ";
            hashTable[i].display();
        }
        cout<<"Total Collisions : "<<collision<<endl;
    }
};
void menu(){
    cout<<"\nMenu\n";
    cout<<"1. Add Details \n";
    cout<<"2. Show Details \n";
    cout<<"3. Delete\n";
    cout<<"4. Display table\n";
    cout<<"5. Exit\n";
    return;
}
int main(){
    hashChain hc;
    int ch;
    long number;
    while(true){
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
        if(ch==5){
            cout<<"Goodbye\n";
            break;
        }
        else{
            if(ch==1){
                cout<<"Enter a long number : ";
                cin>>number;
                hc.insert(number);
            }
            else if(ch==2){
                cout<<"Enter a long number : ";
                cin>>number;
                hc.search(number);
            }
            else if(ch==3){
                cout<<"Enter a long number : ";
                cin>>number;
                hc.remove(number);
            }
            else{
                hc.display();
            }
        }
    }
    return 0;
}
