#include<bits/stdc++.h>
using namespace std;
/*structure of customer who is standing in row for ticket booking */
struct customer
{
    string name="NULL"; //name of customer
    int ticketNo=0; //no of tickets
    string pref1="NULL"; //first preference of stall(Front/Middle/Balcony)
    string pref2="NULL"; //second preference of stall(Front/Middle/Balcony)
};