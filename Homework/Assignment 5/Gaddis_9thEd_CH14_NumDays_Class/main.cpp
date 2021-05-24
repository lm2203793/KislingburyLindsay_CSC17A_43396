/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Overloaded operators in NumDays class
 * Created on May 23, 2021, 10:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "NumDays.h"
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    float n;

    cout<<"This program demonstrates the overloaded class operators"<<endl;
    cout<<"Enter number of hours worked for week 1: ";
    cin>>n;
    NumDays week1(n);
    cout<<"Enter the number of hours worked for week 2: ";
    cin>>n;
    NumDays week2(n);
    
    //Create total NumDays object
    NumDays tot;
    //Add NumDays objects hours
    tot=week1+week2;
    //Display combined hours
    cout<<fixed<<setprecision(2);
    cout<<"Combined hours: "<<tot.getDays()<<" Days, or "
            <<tot.getHrs()<<" Hours"<<endl;
    //Increment hours
    cout<<"...Incrementing hours"<<endl;
    tot++;
    //Display new hours
    cout<<"New hours: "<<tot.getDays()<<" Days, or "
            <<tot.getHrs()<<" Hours"<<endl;
    //Subtract hours
    cout<<"...Subtracting week1 from total hours"<<endl;
    tot=tot-week1;
    cout<<"New hours: "<<tot.getDays()<<" Days, or "
            <<tot.getHrs()<<" Hours"<<endl;
    //Decrement hours
    cout<<"...Decrementing total hours"<<endl;
    tot--;
    cout<<"New hours: "<<tot.getDays()<<" Days, or "
            <<tot.getHrs()<<" Hours"<<endl;
    return 0;
}

