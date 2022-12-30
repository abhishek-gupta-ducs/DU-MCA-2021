#include<bits/stdc++.h>
using namespace std;
void Sort(int* S,int* F, int n){
    for(int k=0;k<n-1;k++){
        int flag = 0;
        int ptr=0;
        while(ptr<n-k-1){
            if(F[ptr]>F[ptr+1]){
                int temp1 = S[ptr];
                S[ptr] = S[ptr+1];
                S[ptr+1] = temp1;
                int temp2 = F[ptr];
                F[ptr] = F[ptr+1];
                F[ptr+1] = temp2;
                flag=1;
            }
            ptr = ptr+1;
        }
        if(flag==0){
            break;
        }
    }
}
void printArr(int* S,int* F,int* system, int n){
    cout<<"Machine   "<<"S      "<<"F   "<<endl;
    for(int i=0;i<n;i++){
        cout<<system[i];
        cout<<"         ";
        cout<<S[i];
        cout<<"      ";
        cout<<F[i];
        cout<<endl;
    }
}
int machineFinder(int* S, int* F,int* system, int n){
    int machine=1;
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=i-1;j>=0;j--){
            if(S[i]>=F[j]){
                system[i]=system[j];
                flag=1;
                break;
            }
        }
        if(flag==0){
            machine+=1;
            system[i]=machine;
        }
    }
    return machine;
}
int main(){
    //start time array of all jobs
    int S[] = {1,3,0,4,3,5,6,8};
    //finish time array of all jobs
    int F[] = {4,5,6,7,8,9,10,11};
    int n = sizeof(S)/sizeof(S[0]);
    int system[n];
    for(int i=0;i<n;i++){
        system[i]=1;
    }
    cout<<"Before sorting"<<endl;
    printArr(S,F,system,n);
    Sort(S,F,n);
    int machine = machineFinder(S,F,system,n);
    cout<<"After sorting"<<endl;
    printArr(S,F,system,n);
    cout<<"Total machine = "<<machine<<endl;
}