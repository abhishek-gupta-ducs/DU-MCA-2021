#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int p, int r){
    int x = arr[r]; //pivot element is x
    int i = p-1;
    for(int j = p; j<=r-1 ;j++){
        if(arr[j]<=x){
            i=i+1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}
void quickSort(int arr[], int p, int r){
    if(p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}
int main(){
    int arr[]={283, 305, 527, 749, 961, 169, 196, 325, 356};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    quickSort(arr,0,n-1);
    cout<<"\nArray after sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}