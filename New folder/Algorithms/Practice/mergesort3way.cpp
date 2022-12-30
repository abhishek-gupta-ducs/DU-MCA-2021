#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647;
void merge(int* arr,int p, int q1, int q2, int r){
    //calculating size of partitions
    int n1 = q1-p+1;
    int n2 = q2-q1;
    int n3 = r-q2;
    //creating temporary arrays
    int L[n1+1],M[n2+1],R[n3+1];
    //filling arrays
    for(int i=0;i<n1;i++){
        L[i] = arr[i+p];
    }
    for(int j=0;j<n2;j++){
        M[j] = arr[j+q1+1];
    }
    for(int k=0;k<n3;k++){
        R[k] = arr[k+q2+1];
    }
    L[n1]=M[n2]=R[n3]=inf;
    int i=0,j=0,k=0;
    //merging array
    for(int t = p ; t<=r ; t++){
        if(L[i]<=M[j] && L[i]<=R[k]){
            arr[t]=L[i];
            i++;
        }
        else if(M[j]<=L[i] && M[j]<=R[k]){
            arr[t]=M[j];
            j++;
        }
        else{
            arr[t]=R[k];
            k++;
        }
    }

}
void mergeSort(int* arr, int p , int r){
    if(p<r){
        int q1 = p + ((r-p)/3);
        int q2 = p + 2*((r-p)/3)+1;
        mergeSort(arr,p,q1);
        mergeSort(arr,q1+1,q2);
        mergeSort(arr,q2+1,r);
        merge(arr,p,q1,q2,r);
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