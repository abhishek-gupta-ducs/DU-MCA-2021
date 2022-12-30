#include<bits/stdc++.h>
using namespace std;
void print(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}
int func(int* arr, int n){
    int k=0;
    for(int i=n-1;i>0;i--){
        if(arr[i]>arr[i-1]){
            k++;
        }
        else{
            return n-k-1;
        }
    }
    return 0;
}
int main(){
    //int arr[]={36, 41, 7, 18, 29, 31};
    int arr[]={29, 31, 36, 41, 7, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = func(arr,n);
    cout<<"For array: ";
    print(arr,n);
    cout<<"\nK = "<<k<<endl;
}