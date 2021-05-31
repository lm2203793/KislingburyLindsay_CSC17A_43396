/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Convert military time to standard time
 *          with exception handling
 * Created on May 30, 2021
 */

#include <cstdlib>
#include <iostream>
#include "MilTime.h"
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    string  mHrsStr;    //Hold input hours in string for validation
    int     mSecs;      //Hold input seconds
    bool    again=true; //Input Validation Flag
    MilTime input;      //Military Time object
    
    //Print Welcome Message
    cout<<"This program converts military time to standard time!"<<endl;
    
    //Get the hours
    cout<<"Enter the Military Time Hours (1 to 2359): ";
    getline(cin,mHrsStr); 
    while(again){
        try{
            input.setMilHr(mHrsStr);
            again=false;
        }
        catch(MilTime::BadHour e){
            cout<<"Error! "<<e.getVal()<<" is not in range"<<endl;
            cout<<"Enter the Hours (1 to 2359): ";
            cin>>mHrsStr;
        }
    }
    
    //Get the seconds
    again=true;
    cout<<"Enter the seconds (1 to 59): ";
    cin>>mSecs;
    while(again){
        try{
            input.setMilSec(mSecs);
            again=false;
        }
        catch(MilTime::BadSecs e){
                cout<<"Error! "<<e.getVal()<<" is not in range!"<<endl;
                cout<<"Enter the Seconds (1 to 59): ";
                cin>>mSecs;
            }
        }
        
    //Display Inputs
    cout<<"You entered: "<<input.getMilHr()<<":"<<input.getMilSecs()<<endl;
    //Convert
    input.cnv();

    //Display
    cout<<"Converted to Standard Time, that is:"<<endl;
    cout<<input.getHour()<<":"<<input.getMin()<<":"<<input.getSec()
        <<" "<<input.getAmPm()<<endl;

    
    return 0;
}

