#include<bits/stdc++.h>
#include "customerQueue.cpp"
#include "customerBookedStruct.cpp"
#include "stallStack.cpp"
#include<cstdio>
using namespace std;
/*Main Program for ticket bbooking*/
int s_no=0; //Number of customers coming
stall front(1,30),middle(31,70),balcony(71,100);//creating stack of tickets for all stalls
void customerComing(Queue Q){
    //function to take customer data from csv file and create a queue of customers
    ifstream fin;
    fin.open("DSA.csv");
    string line;
    string arr[4];
    string word;
    while(getline(fin,line)){
        stringstream s(line);
        int i=0;
        while(getline(s,word,',')){
            arr[i]=word;
            i++;
        }
        Q.enqueue(arr[0],stoi(arr[1]),arr[2],arr[3]);
    }
}
string bookID(customer d){
    //function to genrate booking id for booked tickets
    s_no++;
    if(s_no<10){
        string id = d.name[0]+to_string(d.ticketNo)+"MYSHOW0"+to_string(s_no);
        return id;
    }
    string id = d.name[0]+to_string(d.ticketNo)+"MYSHOW0"+to_string(s_no);
    return id;
}
void space(int size){
    for(int k=0;k<20-size;k++){
        cout<<" ";
    }
}
int ticketCounter(int n,string p1,string p2="No"){
    /*ticket counter function to check if ticket is availavle for any
    customer, according to customer's first and second preference.*/
    if(p1=="Front"){
        if(front.size>n){
            return 1;
        }
        else{
            if(p2=="Middle"){
                if(middle.size>n){
                    return 2;
                }
            }
            else if(p2=="Balcony"){
                if(balcony.size>n){
                    return 3;
                }
            }
            else{
                return -1;
            }
        }
    }
    else if(p1=="Middle"){
        if(middle.size>n){
            return 2;
        }
        else{
            if(p2=="Front"){
                if(front.size>n){
                    return 1;
                }
            }
            else if(p2=="Balcony"){
                if(balcony.size>n){
                    return 3;
                }
            }
            else{
                return -1;
            }
        }
    }
    else if(p1=="Balcony"){
        if(balcony.size>n){
            return 3;
        }
        else{
            if(p2=="Middle"){
                if(middle.size>n){
                    return 2;
                }
            }
            else if(p2=="Front"){
                if(front.size>n){
                    return 1;
                }
            }
            else{
                return -1;
            }
        }
    }
    return -1;
}
void ticketBooking(int n,customer d,Queue Q,bookedCustomer table[100]){
    //function to book the ticket for customer
    cout<<"****************************************************************************\n";
    cout<<"                            Ticket Booking Open                             \n";
    cout<<"****************************************************************************\n";
    for(int j = 0;j<n+1;j++){
        d = Q.dequeue(); //customer will get dequeue from queue
        if(d.name=="NULL"){
            continue;
        }
        else{
            cout<<"============================================================================\n";
            cout<<"Next Customer\n";
            cout<<"============================================================================\n";
            //ticket counter function will check if ticket is available
            int status = ticketCounter(d.ticketNo,d.pref1,d.pref2); 
            if (status==-1){
                cout<<"Ticket Not Availavle as per customer preference for customer : "<<d.name<<endl;
                s_no++;
            }
            else{
                //if ticket available
                table[j].B_ID = bookID(d);
                table[j].Name = d.name;
                table[j].no_of_tickets = d.ticketNo;
                if(status==1){
                    for(int k=0;k<d.ticketNo;k++){
                        table[j].seat_no[k]=front.pop();
                    }
                }
                else if(status==2){
                    for(int k=0;k<d.ticketNo;k++){
                        table[j].seat_no[k]=middle.pop();
                    }
                }
                else if(status==3){
                    for(int k=0;k<d.ticketNo;k++){
                        table[j].seat_no[k]=balcony.pop();
                    }
                }
                cout<<table[j].no_of_tickets<<" Ticket Booked for customer "<<table[j].Name
                <<" with Booking ID "<<table[j].B_ID<<endl;
            }
        }
        //printing number of left tickets in each stalls
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"seat left: "<<endl;
        cout<<"front : "<<front.size<<endl;
        cout<<"middle : "<<middle.size<<endl;
        cout<<"balcony : "<<balcony.size<<endl;
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    }
    cout<<"----------------------------------------------------------------------------\n";
    cout<<"                               Booking Closed                               \n";
    cout<<"----------------------------------------------------------------------------\n";
}
void displayFinalList(bookedCustomer table[100]){
    //final list of customers whose tickets get booked
    cout<<"\n***********************************************************\n";
    cout<<"                         Final List                        \n";
    cout<<"===========================================================\n";
    cout<<"Booking ID          Name                Seats        \n";
    cout<<"===========================================================\n";
    for(int j = 0 ; j<s_no+1;j++){
        if(table[j].B_ID=="NULL"){
            continue;
        }
        else{
            cout<<table[j].B_ID;
            space(table[j].B_ID.length());
            cout<<table[j].Name;
            space(table[j].Name.length());
            cout<<"|";
            for(int x=0;x<table[j].no_of_tickets;x++){
                cout<<table[j].seat_no[x]<<"|";
            }
            cout<<endl;
        }
    }
    cout<<"===========================================================\n";
}
void sort(bookedCustomer table[100],int n=s_no){
    //bubble sort to sort final list of booked customer according to their booking id
    int x,y;
    bookedCustomer temp;
    for(x=0;x<n;x++){
        for(y=0;y<(n-1-x);y++){
            if(table[y].B_ID>table[y+1].B_ID){
                temp=table[y];
                table[y]=table[y+1];
                table[y+1]=temp;
            }
        }
    }
}


void getDetails(bookedCustomer table[100],string name){
    for(int m=0;m<s_no;m++){
        if(name==table[m].Name){
            int n=m;
            cout<<"===========================================================\n";
            cout<<"Booking ID          Name                Seats        \n";
            cout<<"===========================================================\n";
            while(name==table[n].Name){
                cout<<table[m].B_ID;
                space(table[m].B_ID.length());
                cout<<table[m].Name;
                space(table[m].Name.length());
                cout<<"|";
                for(int x=0;x<table[m].no_of_tickets;x++){
                    cout<<table[m].seat_no[x]<<"|";
                }
                cout<<endl;
                n++;
            }
            return;
        }
    }
    cout<<"User Not Found\n";
}
int main(){
    customer d; 
    bookedCustomer table[100];
    Queue Q("NULL",0,"NULL","NULL");
    customerComing(Q);
    Q.display();
    int n = Q.size();
    ticketBooking(n,d,Q,table);
    displayFinalList(table);
    sort(table);
    cout<<"***********************************************************\n";
    cout<<"                        After Sorting                      \n";
    cout<<"***********************************************************\n";
    displayFinalList(table);
    while(true){
        char ch;
        cout<<"Want to check any customer details (Y/N) : ";
        cin>>ch;
        cout<<endl;
        if(ch=='y'||ch=='Y'){
            string name,fName,lName="";
            cout<<"Enter Name of customer to get details";
            cout<<"\nFirst Name : ";
            cin>>fName;
            cout<<"Last Name(Enter .(dot) If not) : ";
            cin>>lName;
            if(lName=="."){
                name=fName;
            }
            else{
                name=fName+" "+lName;
            }
            getDetails(table,name);
        }
        else{
            cout<<"GoodBye\n";
            break;
        }
    }
}