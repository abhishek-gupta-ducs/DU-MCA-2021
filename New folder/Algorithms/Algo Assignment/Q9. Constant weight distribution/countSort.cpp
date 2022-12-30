#include<bits/stdc++.h>
using namespace std;
class countSort{
    public:
    int max(int* arr , int size){
    int max = arr[0];
    for(int j = 1; j<size ; j++){
        if(max<arr[j]){
            max = arr[j];
        }
    }
    return max;
    }

    void sort(int* arr,int* sortArray, int size){
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

    int deleteItem(int* arr,int size, int item){
        int i=0,flag=0;
        for(i=0;i<size;i++){
            if(arr[i]==item){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return size;
        }
        else{
            for(int j = i ;j<size-1;j++){
                arr[j]=arr[j+1];
            }
            arr[size-1]=item;
            return size-1;
        }
    }
};