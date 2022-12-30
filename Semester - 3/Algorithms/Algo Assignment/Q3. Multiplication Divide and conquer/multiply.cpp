#include<bits/stdc++.h>
using namespace std;

int length(int num, int len=0){
    if(num/10==0){
        return len+1;
    }
    else{
        return length(num/10,len+1);
    }
}
int max(int x, int y){
    if(length(x)>length(y)){
        return length(x);
    }
    else{
        return length(y);
    }
}
int multiply(int x , int y){
    if(x<10 || y<10){
        return x*y;
    }
    else{
        int n = max(x,y);
        int half = n/2;
        int a = x / pow(10,half);
        int b = x % int(pow(10,half));
        int c = y / pow(10,half);
        int d = y % int(pow(10,half));
        int ac = multiply(a,c);
        int bd = multiply(b,d);
        int ad_plus_bc = multiply(a+b,c+d)-ac-bd;
        return ac*(pow(10,(2*half)))+(ad_plus_bc)*(pow(10,half))+bd;
    }
}
int main(){
    int a,b;
    cout<<"Enter first number : ";
    //cin>>a;
    cout<<"Enter second number : ";
    //cin>>b;
    int result = multiply(243,102445);
    cout<<243*102445<<endl;
    cout<<a<<" * "<<b<<" = "<<result<<endl;
}