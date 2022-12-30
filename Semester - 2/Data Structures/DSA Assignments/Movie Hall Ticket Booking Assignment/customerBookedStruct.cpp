#include<bits/stdc++.h>
using namespace std;
/*Structure of customer whose ticket get booked*/
struct bookedCustomer{
    string Name="NULL"; //name of customer
    string B_ID="NULL"; //booking id of customer
    int no_of_tickets=0; //no of tickets get booked
    int seat_no[6]={0}; //array of seat numbers
};