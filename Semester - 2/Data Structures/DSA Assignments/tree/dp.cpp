#include<bits/stdc++.h>
using namespace std;
int free_space = 50;
class node{
    public:
        int data[50],size;
        node* next;
        node(int n){
            size=n;
            for(int i=0;i<size;i++){
                data[i]=0;
            }
            next = NULL;
            free_space-=size;
        }
};
class linklist{
    public:
        node* C;
        linklist(int n){
            if(n>50 || n<0){
                n=50;
            }
            C = new node(n);
            cout<<"Free Space : "<<free_space<<endl;
        }
        void add_partittion(int n){
            if(free_space<=0){
                cout<<"Space Full\n";
                return;
            }
            else if(n>free_space){
                cout<<"Only "<<free_space<<" space left \n";
                n=free_space;
            }
            node* temp = C;
            node* newNode = new node(n);
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            cout<<"Free Space : "<<free_space<<endl;
        }
        
        void display(){
            node* temp = C;
            char z='C';
            while(temp!=NULL){
                cout<<"Partition "<<z<<" : \n";
                if(temp->data[0]==0){
                    cout<<"EMPTY PARTITION\n";
                }
                else{
                    for(int i=0;i<temp->size;i++){
                        if(temp->data[i]==0){
                            continue;
                        }
                        cout<<i<<"=="<<temp->data[i]<<endl;
                    }
                }
                z++;
                temp=temp->next;
            }
        }
};
int main(){
    linklist dp(20);
    dp.add_partittion(12);
    dp.add_partittion(19);
    dp.display();
}