#include<bits/stdc++.h>
#include "countSort.cpp"
countSort arrSort;
using namespace std;
void printArray(int* arr, int size){
    cout<<"{";
    for(int i=0; i<size;i++){
        cout<<arr[i];
        if(i!=size-1){
            cout<<",";
        }
    }
    cout<<"}\n";
}

void pairing(int* arr,int size, int c){
    vector <vector<int>> result;
    for(int i=0; i<size/2; i++){
        vector <int> pair;
        if(arr[i]+arr[size-1-i]==c){
            pair.push_back(arr[i]);
            pair.push_back(arr[size-1-i]);
        }
        result.push_back(pair);
    }
    for(int j=0;j<size/2;j++){
        cout<<"("<<result[j][0]<<","<<result[j][1]<<")"<<endl;
    }
}

int main(){
    int c = 20;
    int arr[] = {10,19,1,12,11,9,10,8,15,1,19,3,17,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sortArr[n];
    cout<<"total no of items = "<<n<<endl;
    cout<<"constant total weight = "<<c<<endl;
    arrSort.sort(arr,sortArr,n);
    cout<<"Sorted weights: \n";
    printArray(sortArr,n);
    pairing(sortArr,n,c);
}