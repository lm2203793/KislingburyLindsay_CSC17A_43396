/* 
 * File:   MilTime.h
 * Author: Lindsay Kislingbury
 * Purpose: MilTime Class Member Function definitions
 * Created on May 30, 2021
 */

#include "MilTime.h"
#include <string>
using namespace std;

void MilTime::cnv(){
    string hours, minuts;   //Hold hours and minutes to convert
    int hrs, mins;          //Hold hours and minutes as ints

    //Convert to int parts
    hours+=milHrs[0];
    hours+=milHrs[1];
    minuts+=milHrs[2];
    minuts+=milHrs[3];
    hrs=stoi(hours);
    mins=stoi(minuts);
    
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
