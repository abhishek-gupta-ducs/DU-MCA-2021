#include<iostream>
using namespace std;
class Sort{
    public:
    int partition(int arr[],int s,int e){
        int elem = arr[s];

        int count =0;
        for(int i=s+1;i<=e;i++){
            if(arr[i]<=elem){
                count++;
            }
        }
        int pivotIndex = s+count;
        swap(arr[pivotIndex],arr[s]);
        int i=s;
        int j=e;
        while(i<pivotIndex && j>pivotIndex){
            while(arr[i]<=elem){
                i++;
            }
            while(arr[j]>elem){
                j--;
            }
            if(i<pivotIndex && j>pivotIndex){
                swap(arr[i++],arr[j--]);
            }
        }

        return pivotIndex;
    }

    void quickSort(int arr[] , int s, int e){
        //base case
        if(s>=e){
            return ;
        }
        int p = partition(arr,s,e);

        //sort left and right part after partition

        quickSort(arr, s,p-1);
        quickSort(arr,p+1,e);
    }
    void insertionSort(int arr[],int n){
        for(int i=1;i<n;i++){
            int curr = arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>curr){
                arr[j+1] = arr [j];
                j--;
            }
            arr[j+1] = curr;

        }
    }
};