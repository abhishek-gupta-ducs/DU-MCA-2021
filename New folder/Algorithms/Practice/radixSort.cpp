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
    int aux[10];
    int p1 = pow(10,place+1);
    int p2 = pow(10,place);
    //initialise aux with 0s
    for(int i=0; i<10;i++){
        aux[i]=0;
    }
    //filling aux with the help of main array
    for(int i=0; i<size;i++){
        int index = (arr[i]%p1)/p2;
        aux[index]+=1;
    }
    //filling comulative sum of aux array
    for(int i=1; i<10;i++){
        aux[i]=aux[i]+aux[i-1];
    }
    //sorting array
    for(int j=size-1; j>=0 ;j--){
        int index = (arr[j]%p1)/p2;
        sortArr[aux[index]-1] = arr[j];
        aux[index]-=1;
    }
}
/*int radixSort(int* arr, int* sortArr, int size){
    int maxVal = max(arr, size);
    int len = length(maxVal);
    int temp[size];
    cout<<"During sorting : \n";
    for(int i=0;i<len;i++){
        if(i%2==0){
            countSort(arr,sortArr,size,i);
            print(sortArr,size);
        }
        else{
            countSort(sortArr,arr,size,i);
            print(arr,size);
        }
    }
    return len%2;
}*/
void radixSort(int* arr, int* sortArr, int size){
    int maxVal = max(arr, size);
    int len = length(maxVal);
    int temp[size];
    cout<<"During sorting : \n";
    for(int i=0;i<len;i++){
        if(i%2==0){
            countSort(arr,sortArr,size,i);
            print(sortArr,size);
        }
        else{
            countSort(sortArr,arr,size,i);
            print(arr,size);
        }
    }
    if(len%2==0){
        sortArr = arr;
    }
    print(sortArr,size);
}
int main(){
    int arr[] = {23113,0,432,412,650};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    int sortArr[n];
    for(int i=0;i<n;i++){
        sortArr[i]=0;
    }
    radixSort(arr,sortArr,n);
    cout<<"After sorting:\n";
    print(sortArr,n);
}