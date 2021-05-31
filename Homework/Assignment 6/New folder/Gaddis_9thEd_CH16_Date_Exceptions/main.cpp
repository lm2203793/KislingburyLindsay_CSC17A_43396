/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on May 30, 2021
 * Purpose:  Design a class called Date.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;
//User Libraries
#include "Date.h"

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int day, month, year;   //Hold user input for day, month, year
    bool again=true;             //Input Validation Flag
    
    //Create a date object
    Date brthDay;
    
    //Input the Day    
    cout<<"Enter the day of your birthday: ";
    cin>>day;
    while(again){
        try{  
            brthDay.setDay(day);
            again=false;
        }
        catch(Date::InvDay error){
            cout<<"Error: "<<error.getVal()<<" is an invalid value"
                <<" for the day.\nPlease enter a value between 1 and 31: ";
            cin>>day;
        }
    }
    
    //Input the Month
    again=true;
    cout<<"Enter the month of your birthday as an integer: ";
    cin>>month;
    while(again){
        try{
            brthDay.setMnth(month);
            again=false;
        }
        catch(Date::InvMnth error){
            cout<<"Error: "<<error.getVal()<<" is an invalid value"
                <<" for the month.\nPlease enter a value between 1 and 12: ";
            cin>>month;
        }
    }
    
    //Input the year
    again=true;
    cout<<"Enter the year of your birthday: ";
    cin>>year;
    while(again){
        try{
            brthDay.setYr(year);
            again=false;
        }
        catch(Date::InvYr error){
            cout<<"Error: "<<error.getVal()<<" is an invalid value"
                <<" for the month.\nPlease enter a value between "
                <<"1870 and 2021: ";
            cin>>year;
        }
    }
    
    
    //Display outputs
    cout<<endl;
    cout<<"Your birthday is:"<<endl;
    //Format #1
    cout<<brthDay.getDay()<<"/"<<brthDay.getMnth()
            <<"/"<<brthDay.getYear()<<endl;
    //Format #2
    cout<<brthDay.cnvMnth(month)<<" "<<brthDay.getDay()
            <<", "<<brthDay.getYear()<<endl;
    //Format #3
    cout<<brthDay.getDay()<<" "<<brthDay.cnvMnth(month)
            <<" "<<brthDay.getYear()<<endl;
   
    return 0;
}