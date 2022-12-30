#include<bits/stdc++.h>
using namespace std;
int partition(int* arr, int p, int r){
    int x = arr[r];
    int i = p-1;
    for(int j = p ; j<=r-1 ; j++){
        if(arr[j]<x){
            i+=1;
            //swap(arr[j],arr[i])
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    //swap(arr[i+1],arr[r])
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    //return q
    return i+1;
}
int quickSelect(int* arr, int p, int r, int k){
    if(p<r){
        int q = partition(arr, p , r);
        if(k<q){ //if k lies in left side of pivot(q) index value
            quickSelect(arr,p,q-1,k);
        }
        else{ //if k lies in right side of pivot(q) index value
            quickSelect(arr,q+1,r,k);
        }
    }
    return arr[k];
}
int main(){
    int arr[]={283, 305, 527, 749, 961, 169, 196, 325, 356};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    int result = quickSelect(arr,0,n-1,k-1);
    cout<<"Kth (k = "<< k <<") ranked value is: "<<result<<endl;
    cout<<"Resultant array is: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}