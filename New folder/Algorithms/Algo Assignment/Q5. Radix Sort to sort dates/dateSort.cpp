#include<bits/stdc++.h>
using namespace std;

void print(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    cout<<endl;
}
int max(int* arr, int size){
    /*max function will return the maximum value integer of an array*/
    int max = arr[0];
    for(int i=1;i<size;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}
int length(int num, int len=0){
    if(num/10==0){
        return len+1;
    }
    else{
        return length(num/10,len+1);
    }
}
void countSort(int* arr, int* sortArr , int size , int place){
    //create auxilary array of size 10
    int aux[2099]; int p1,p2;
    if(place==7||place==5){
        p1 = pow(10,place+1);
        p2 = pow(10,place-1);
    }
    else if(place==3){
        p1 = pow(10,place+1);
        p2 = 1;
    }
    //initialise aux with 0s
    for(int i=0; i<2099;i++){
        aux[i]=0;
    }
    //filling aux with the help of main array
    for(int i=0; i<size;i++){
        int index = (arr[i]%p1)/p2;
        aux[index]+=1;
    }
    //filling comulative sum of aux array
    for(int i=1; i<2099;i++){
        aux[i]=aux[i]+aux[i-1];
    }
    //sorting array
    for(int j=size-1; j>=0 ;j--){
        int index = (arr[j]%p1)/p2;
        sortArr[aux[index]-1] = arr[j];
        aux[index]-=1;
    }
}
void radixSort(int* arr, int* sortArr, int size){
    int maxVal = max(arr, size);
    int len = length(maxVal);
    int temp[size];
    cout<<"During sorting : \n";
    for(int i=len-1;i>=0;i--){
        if(i==7||i==3){
            countSort(arr,sortArr,size,i);
            //arr = sortArr;
        }
        else if(i==5){
            countSort(sortArr,arr,size,i);
        }
    }
}
int main(){
    int arr[] = {25062000,1062000,10071999,2122001,23011995};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    int sortArr[n];
    for(int i=0;i<n;i++){
        sortArr[i]=0;
    }
    radixSort(arr,sortArr,n);
    cout<<"After sorting: \n";
    print(sortArr,n);
}