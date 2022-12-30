#include<bits/stdc++.h>
using namespace std;
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
int main(){
    double name;
    cout<<"Enter Number: ";
    cin>>name;
    int n = sum(long(name));
    cout<<n<<endl;
}