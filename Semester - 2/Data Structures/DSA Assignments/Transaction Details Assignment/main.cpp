#include<bits/stdc++.h>
#include "customerArray.cpp"
using namespace std;
int main(){
    c_array list;
    ifstream fin;
    ofstream fout;
    int n;
    string details,t_no,key,word;
    //Creatig array(implemented using LinkList) of indexes 
    fin.open("DSA.csv");
    while(getline(fin,details)){
        stringstream s(details);
        while(getline(s,t_no,',')){
            list.nextValue(t_no);
            break;
        }
    }
    fin.close();
    //sorting array (implemented using linklist) of indexes
    list.sort();

    n = list.length();

    //creating and writig data in sorted file
    fout.open("Sorted_DSA.csv");
    fout.clear(); 
    for(int i=0;i<n;i++){
        int status=0; 
        key = list.at(i);
        fin.open("DSA.csv");
        while(getline(fin,details) && status==0){
            stringstream s(details);
            while(getline(s,word,',')){
                if(word==key){
                    status=1;
                    fout<<details;
                    if(i<99){fout<<endl;}
                }
                break;
            }
        }
        fin.close();
    }
    fout.close();
    list.end();
}