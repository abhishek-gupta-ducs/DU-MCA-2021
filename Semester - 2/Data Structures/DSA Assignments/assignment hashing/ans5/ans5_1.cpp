#include<iostream>
#include<cmath>
using namespace std;
class hashHeight{
    float height[10]={0};
    public:
    int hashFunc(float key,int i){
        /*floor(m(kA mod 1))*/
        float A = 0.9;
        key=key*A;
        key=key-(int)key;//(kA mod 1)
        key=10*key;
        return floor(key);
    }
    void insert(float h){
        int i=0;
        int index;
        while(i!=10){
            index = hashFunc(h,i);
            if(height[index]==0){
                height[index]=h;
                cout<<"Insertion Succesfull\n";
                return;
            }
            else{
                i++;
            }
        }
        cout<<"ERROR: Hash table overflow\n";
    }
    void search(float h){
        int i=0;
        int index;
        while(i!=10){
            index = hashFunc(h,i);
            if(height[index]==h){
                cout<<"Index"<<"   "<<"Height(in feets)\n";
                cout<<index<<"       "<<h<<endl;
                return;
            }
            else{
                i++;
            }
        }
        cout<<"Element not present in hash table\n";
    }
    void remove(float h){
        int i=0;
        int index;
        while(i!=10){
            index = hashFunc(h,i);
            if(height[index]==h){
                height[index]=0;
                cout<<"Deletion succesfull\n";
                return;
            }
            else{
                i++;
            }
        }
        cout<<"Element not present in hash table\n";
    }
    void display(){
        cout<<"Index"<<"   "<<"Height(in feets)\n";
        for(int i =0;i<10;i++){
            cout<<i<<"       "<<height[i]<<endl;
        }
        return;
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
    hashHeight h1;
    int ch;
    float ht;
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
                cout<<"Enter height(in feets): ";
                cin>>ht;
                h1.insert(ht);
            }
            else if(ch==2){
                cout<<"Enter height(in feets): ";
                cin>>ht;
                h1.search(ht);
            }
            else if(ch==3){
                cout<<"Enter height(in feets): ";
                cin>>ht;
                h1.remove(ht);
            }
            else{
                h1.display();
            }
        }
    }
    return 0;
}