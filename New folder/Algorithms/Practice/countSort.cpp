#include<bits/stdc++.h>
using namespace std;
int max(int* arr , int size){
    int max = arr[0];
    for(int j = 1; j<size ; j++){
        if(max<arr[j]){
            max = arr[j];
        }
    }
    return max;
}
void print(int* arr, int n){
    for(int i = 0; i<n ;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    cout<<endl;
}
void countSort(int* arr,int* sortArray, int size){
    //first find maximum integer in array
    int k = max(arr,size);
    //Declaring countArray
    int countArray[k+1];
    //initialising countArray with 0s
    for(int i=0;i<=k;i++){
        countArray[i]=0;
    }
    //adding count of each integer of array 'arr' into 'countArray'
    for(int j=0;j<size;j++){
        countArray[arr[j]]+=1;
    }
    //finding comulative sum of countArray elements
    for(int p=1;p<=k;p++){
        countArray[p]=countArray[p]+countArray[p-1];
    }
    //start sorting array
    for(int q=size-1;q>=0;q--){
        sortArray[countArray[arr[q]]-1]=arr[q];
        countArray[arr[q]]-=1;
    }
}
int main(){
    int arr[]={2,5,3,0,2,3,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sortArray[n];
    for(int i=0;i<n;i++){
        sortArray[i]=0;
    }
    cout<<"Unsorted Array :-\n";
    print(arr,n);
    countSort(arr,sortArray,n);
    cout<<"Sorted Array :-\n";
    print(sortArray,n);
}