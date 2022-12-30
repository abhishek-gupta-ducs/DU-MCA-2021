#include<bits/stdc++.h>
using namespace std;
void insertionSort(int* arr , int n){
    for(int k=1;k<n;k++){
        int key = arr[k];
        int i = k-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i-=1;
        }
        arr[i+1]=key;
    }
}
int main(){
    int arr[5]={8,6,2,4,5};
    int n = 5;
    cout<<"Array before sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    insertionSort(arr,n);
    cout<<"\nArray after sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}