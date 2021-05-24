/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on May 22, 2021
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
    int m,d,y;      //Hold month,day,year inputs
    bool error;     //Flag for input validation
    
    //Get Inputs
    cout<<"ENTER YOUR BIRTHDAY!"<<endl;
    do{//Input Month
        error=false;
        cout<<"Enter the month as a numeric value (EX: January = 01):"<<endl;
        cin>>m;
        if(m<1) cout<<"Invalid! Month must be greater than 0"<<endl;
        if(m>12)cout<<"Invalid! Month must be less than 13"<<endl;
        if(!cin||cin.fail()){
            error=true;
            cout<<"Invalid!"<<endl;
            cin.clear();
            cin.ignore();
        }
    }while(m<0||m>12||error);
    
    do{//Input Day
        error=false;
        cout<<"Enter the day as a numeric value (EX: 10):"<<endl;
        cin>>d;
        if(d<1) cout<<"Invalid! Day must be greater than 0"<<endl;
        if(d>31)cout<<"Invalid! Day must be less than 32"<<endl;
        if(!cin||cin.fail()){
            error=true;
            cout<<"Invalid!"<<endl;
            cin.clear();
            cin.ignore();
        }
    }while(d<0||d>12||error);
    
    do{//Input Year
        error=false;
        cout<<"Enter the year as a numeric value (EX: 1990):"<<endl;
        cin>>y;
        if(y<1) cout<<"Invalid! year must be greater than 0"<<endl;
        if(y>2021)cout<<"Invalid! year must be less than 2022"<<endl;
        if(!cin||cin.fail()){
            error=true;
            cout<<"Invalid!"<<endl;
            cin.clear();
            cin.ignore();
        }
    }while(y<0||y>2022||error);

    //Create Birth Day object
    Date brthdy(m,d,y);
    
    //Display outputs
    cout<<"Your birthday is:"<<endl;
    //Format #1
    cout<<brthdy.getDay()<<"/"<<brthdy.getMnth()<<"/"<<brthdy.getYear()<<endl;
    //Format #2
    cout<<brthdy.cnvMnth(m)<<" "<<brthdy.getDay()<<", "<<brthdy.getYear()<<endl;
    //Format #3
    cout<<brthdy.getDay()<<" "<<brthdy.cnvMnth(m)<<" "<<brthdy.getYear()<<endl;
        
    return 0;
}