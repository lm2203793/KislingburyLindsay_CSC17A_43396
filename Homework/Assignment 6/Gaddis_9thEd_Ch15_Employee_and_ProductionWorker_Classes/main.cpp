/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Gaddis 9thED Ch15 Problem #1
 *          Demonstrates Derived Class
 * Created on May 28, 2021, 5:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "ProWrkr.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare Variables
    string name;        //hold employee name
    string number;      //hold employee number
    int date;           //hold employee hire date
    int shift;          //hold employee shift number
    float hrPay;        //hold hourly pay
    int emplys;         //hold number of employees
    bool error;         //input validation
    
    //Input number of employees
    cout<<"Enter the number of employees: ";
    cin>>emplys;
    
    //Create pointer to array of employee objects
    ProWrkr *wrkrs[emplys];
    
    
    //Input employee Data
    cout<<"This program stores Information about Production Workers"<<endl;
    for(int e=0; e<emplys; e++){
        cout<<"Enter Employee "<<(e+1)<<"'s name: ";
        cin>>name;
        cout<<"Enter Employee #1 employee number: ";
        cin>>number;
        cout<<"Enter the year Employee #1 was hired: ";
        cin>>date;
        cout<<"Enter the employee's shift: (1: Day Shift, 2: Night Shift): ";
        do{
            error=false;
            cin>>shift;
            if(shift<0||shift>2){
                cout<<"Invalid! Enter 1 for Day Shift or 2 for Night Shift";
                error=true;
            }
        }while(error);
        cout<<"Enter the employee's hourly pay: $";
        cin>>hrPay;
        wrkrs[e]=new ProWrkr(shift,hrPay,name,number,date);
    }
    
    
    //Display employee data
    for(int e=0; e<emplys; e++){
        cout<<right<<setw(12)<<"Employee #"<<(e+1)<<":"<<endl;
        cout<<right<<setw(12)<<"Name: "<<left<<wrkrs[e]->getName()<<endl;
        cout<<right<<setw(12)<<"Emp#: "<<left<<wrkrs[e]->getNum()<<endl;
        cout<<right<<setw(12)<<"Hire Date: "<<left<<wrkrs[e]->getHireDt()<<endl;
        cout<<right<<setw(12)<<"Shift: ";
        cout<<left<<setw(12)<<(wrkrs[e]->getShft()==1?"Day":"Night")<<endl;
        cout<<right<<setw(12)<<fixed<<setprecision(2);
        cout<<right<<setw(12)<<"Hourly Pay: $"<<left<<wrkrs[e]->getHrPy()<<endl;
        cout<<endl;
    }
    
    //Clean Up
    delete []wrkrs;
    
    return 0;
}

