#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int* arr, int n){
    for(int k=0;k<n-1;k++){
        int flag = 0;
        int ptr=0;
        while(ptr<n-k-1){
            if(arr[ptr]>arr[ptr+1]){
                int temp = arr[ptr];
                arr[ptr] = arr[ptr+1];
                arr[ptr+1] = temp;
                flag=1;
            }
            ptr = ptr+1;
        }
        if(flag==0){
            break;
        }
        cout<<"\n{After "<<k+1<<" iteration:-}\n";
        for(int i=0;i<n;i++){
            cout<<arr[i];
            if(i!=n-1){
                cout<<",";
            }
        }
    }
}
int main(){
    int arr[5]={2,3,1,4,5};
    int n = 5;
    cout<<"Array before sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    bubbleSort(arr,n);
    cout<<"\nArray after sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}