#include<iostream>
#include<string>
#include"linklist.cpp"
using namespace std;
class hashChain{
    public:
    int collision = 0;
    linkList <string>hashTable[17];
    int hashFunction(string name){
        int n = name.length();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=int(name[i]);
        }
        return sum%17;
    }
    void insert(string name){
        int index = hashFunction(name);
        hashTable[index].insertAtTail(name);
        if(hashTable[index].size()>2){
            collision+=1;
        }
        cout<<"Insertion Succesfull"<<endl;
        return;
    }
    void search(string name){
        int index = hashFunction(name);
        int nodeIndex = hashTable[index].search(name);
        if(nodeIndex == -1){
            cout<<"Element not found"<<endl;
            return;
        }
        cout<<"Element found at index "<<index<<" and node "<<nodeIndex<<endl;
    }
    void remove(string name){
        int index = hashFunction(name);
        int nodeIndex = hashTable[index].search(name);
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
    string name;
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
                cout<<"Enter Student Name: ";
                cin>>name;
                hc.insert(name);
            }
            else if(ch==2){
                cout<<"Enter Student Name: ";
                cin>>name;
                hc.search(name);
            }
            else if(ch==3){
                cout<<"Enter Student Name: ";
                cin>>name;
                hc.remove(name);
            }
            else{
                hc.display();
            }
        }
    }
    return 0;
}
