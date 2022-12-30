#include<bits/stdc++.h>
#include "linklist.cpp"
using namespace std;
int X[][7]={{0,5,3,0,0,0,0},
                 {5,0,4,6,2,0,0},
                 {3,4,0,5,0,6,0},
                 {0,6,5,0,6,6,0},
                 {0,2,0,6,0,3,5},
                 {0,0,6,6,3,0,4},
                 {0,0,0,0,5,4,0}};
int w[9][9]={{0,3,5,7,0,0,0,0,0},
           {3,0,2,0,7,0,12,0,0},
           {5,2,0,5,9,8,0,0,0},
           {7,0,5,0,0,6,0,0,0},
           {0,7,9,0,0,0,0,8,0},
           {0,0,8,6,0,0,0,0,10},
           {0,12,0,0,0,0,0,15,0},
           {0,0,0,0,8,0,15,0,10},
           {0,0,0,0,0,10,0,10,0}};
int W[9][9]={{0,7,3,0,12,0,0,0,0},
            {7,0,0,4,0,13,0,0,0},
            {3,0,0,8,9,5,0,0,0},
            {0,4,8,0,0,15,0,0,0},
            {12,0,9,0,0,1,0,0,0},
            {0,13,5,15,1,0,0,0,0},
            {0,0,0,0,0,0,0,2,6},
            {0,0,0,0,0,0,2,0,10},
            {0,0,0,0,0,0,6,10,0}};
linkList<int> Q(0);\
void printArr(int* arr, int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ,";
    }
    cout<<endl;
}
int extract_min(int* key, int n){
    int min = key[0],loc = 0;
    //setting min and loc 
    for(int i = 0;i<n;i++){
        if(!Q.elementBelongsTo(loc)){
            loc = i;
        }
        else{
            min = key[loc];
            break;
        }
    }
    for(int j = loc+1 ; j<n ; j++){
        if(min>key[j]){
            if(Q.elementBelongsTo(j)){             
                min = key[j];
                loc = j;
            }
        }
    }
    Q.deleteElement(loc);
    return loc;
}
void printTable(int* key, int* pi ,char* G, int n){
    int sum = 0;
    cout<<"V   "<<"Pi   "<<"W"<<endl;
    for(int i=0;i<n;i++){
        cout<<G[i]<<"   "<<G[pi[i]]<<"   "<<key[i]<<endl;
    }
}
void min_span_tree(char* G, int source, int n){
    int key[n];
    int p[n];
    for(int i=0;i<n;i++){
        key[i] = INT32_MAX;
        p[i] = 9;
    }
    key[source] = 0;
    for(int i=1;i<n;i++){
        Q.insertAtTail(i);
    }
    int iter=1;
    while(Q.size()!=0){
        cout<<"Iteraton = "<<iter++<<endl;
        Q.display();
        //extract_min
        int U = extract_min(key,n);
        if(key[U]==INT32_MAX){
            key[U]=0;
        }
        //finding adjacent nodes of u
        cout<<"For U = "<<U<<"("<<G[U]<<")"<<endl;
        linkList<int> adj;
        for(int i=0 ;i<n;i++){
            if(W[U][i]!=0){
                adj.insertAtBeg(i);
            }
        }
        //finding no of adjacent edges
        int adj_size = adj.size()-1;
        cout<<"For V = |";
        for(int i = 0 ; i < adj_size ; i++){
            int V = adj.getElementAtPos(i);
            cout<<G[V]<<"|";
            if(Q.elementBelongsTo(V) && W[U][V]<key[V]){
                p[V]=U;
                key[V]=W[U][V];
            }
        }
        cout<<endl;
        printTable(key,p,G,n);
    }
    //calculating total minimum weight 
    int weight=0;
    for(int r=0;r<n;r++){
        weight+=key[r];
    }
    cout<<"Total Minimum Weight = "<<weight<<endl;
}
int main(){
    char G[]={'S','A','B','C','D','E','F','G','H','-'};
    int n = sizeof(G)/sizeof(G[0]);
    min_span_tree(G,0,n-1);
}