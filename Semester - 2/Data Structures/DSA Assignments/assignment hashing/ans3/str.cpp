#include<bits/stdc++.h>
using namespace std;
int main(){
    string name;
    cout<<"Enter Name: ";
    cin>>name;
    int sum=0;
    for(int i = 0;i<name.length();i++){
        int x = 31;
        sum+=(int(name[i]))*pow(x,i);
    }
    cout<<sum<<endl;
}