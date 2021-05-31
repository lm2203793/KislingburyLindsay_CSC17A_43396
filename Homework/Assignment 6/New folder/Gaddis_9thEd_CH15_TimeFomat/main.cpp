/* 
 * File:   MilTime.h
 * Author: Lindsay Kislingbury
 * Purpose: convert military time to standard time
 * Created on May 30, 2021
 */

#include <cstdlib>
#include <iostream>
#include "MilTime.h"
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    string  mHrsStr;
    char    mHrsCh[4];
    int     mSecs;
    bool    error;
    
    cout<<"This program converts military time to standard time!"<<endl;
    do{
        error=false;
        cout<<"Enter the Military Time Hours: ";
        getline(cin, mHrsStr); 
        if(mHrsStr.length()==4){
            error=false;
        }
        else{
             error=true;
             cout<<"Invalid! Enter a 4 digit value: ";
        }
    }while(error);
        
        //Store the hours
        for(int i=0; i<4; i++){
            mHrsCh[i]=mHrsStr[i];
        }
        
        cout<<"Enter the seconds: ";
        cin>>mSecs;
        
        //Create time object
        MilTime input(mHrsCh,mSecs);
        
        //Convert
        input.cnv();
        
        //Display
        cout<<"Converted to Standard Time, that is:"<<endl;
        cout<<input.getHour()<<":"<<input.getMin()<<":"<<input.getSec()
            <<" "<<input.getAmPm()<<endl;

    
    return 0;
}

