#include<bits/stdc++.h>
using namespace std;
//selection sort
void selection_sort(int* arr,int n){
    for(int k = 0;k<n-1;k++){
        int min = arr[k];
        int loc = k;
        for (int j = k+1 ; j<n ; j++){
            if(min>arr[j]){
                min = arr[j];
                loc = j;
            }
        }
        if(loc!=k){
            //swapping of arr[k] and arr[loc]
            int temp = arr[k];
            arr[k] = arr[loc];
            arr[loc] = temp;
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
    int arr[5]={8,6,2,4,5};
    int n = 5;
    cout<<"Array before sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    selection_sort(arr,n);
    cout<<"\nArray after sorting:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<",";
        }
    }
}