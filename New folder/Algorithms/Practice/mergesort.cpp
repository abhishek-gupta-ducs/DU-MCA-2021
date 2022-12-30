#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647;
void merge(int* Arr , int p , int q , int r){
    
    int n1=q-p+1; //calculating size of partition 1
    int n2=r-q; //calculating size of partition 2
    int L[n1+1] , R[n2+1]; //creating temporary array
    //copy both partitions to these arrays
    for(int i=0;i<n1;i++){
        L[i] = Arr[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = Arr[j+1+q];
    }
    L[n1] = inf;
    R[n2] = inf;
    int i = 0;
    int j = 0;
    for(int k = p ; k<=r ;k++){
        if(L[i]<=R[j]){
            Arr[k] = L[i];
            i+=1;
        }
        else{
            Arr[k] = R[j];
            j+=1;
        }
    }
}
void mergeSort(int* Arr,int p,int r){
    if(p<r){
        int q = (r+p)/2;
        mergeSort(Arr,p,q);
        mergeSort(Arr,q+1,r);
        merge(Arr,p,q,r);
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
    mergeSort(arr,0,n-1);
    cout<<"\nArray after sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}