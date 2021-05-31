/* 
 * File:   MilTime.h
 * Author: Lindsay Kislingbury
 * Purpose: MilTime Class Member Function definitions
 *          with exception handling
 * Created on May 30, 2021
 */

#include "MilTime.h"
#include <string>
using namespace std;

void MilTime::cnv(){
    int hrs, mins;          //Hold hours and minutes as ints
    //Convert to int parts
    hrs=milHrs/100;
    mins=milHrs%100;
    
    //Convert hour to military time
    if(hrs<=12){
        hour=hrs;
        if(mins>0) amPm="PM";
        else  amPm="AM";
    }
    else{ 
        hour=(hrs-12);
        amPm="PM";
    }
    //Minutes is the same
    min=mins;
    //Seconds is the same
    sec=milSecs;
}

void MilTime::setMilHr(string strHrs){
    int hrs; //Hold hours int
    
    //Convert to int
    hrs=stoi(strHrs);
    
    //Check for hour
    if(hrs>0&&hrs<2359){
        milHrs=hrs;
    }
    else 
        throw BadHour(hrs);
}

void MilTime::setMilSec(int secs){
    if(secs>0&&secs<59)
        milSecs=secs;
    else
        throw BadSecs(secs);
}
