/* 
 * File:   Date.h
 * Author: Lindsay Kislingbury
 * Purpose: Date Class Set Function Definitions
 *          Demonstrates Exception Handling
 * Created on May 30, 2021, 9:34 PM
 */

#include "Date.h"
#include <string>
using namespace std;

//Set day with exception handling
void Date::setDay(int d){
    if(d>=1&&d<=31){
        day=d;
    }
    else
        throw InvDay(d);
}

//Set month with exception handling
void Date::setMnth(int m){
    if(m>=1&&m<=12){
        month=m;
    }
    else 
        throw InvMnth(m);
}

//Set year with exception handling
void Date::setYr(int y){
    if(y>=1870&&y<=2021){
        year=y;
    }
    else 
        throw InvYr(y);
}

string Date::cnvMnth(int m){
    string name;
    name=(m==1)?"January":
         (m==2)?"February":
         (m==3)?"March":
         (m==4)?"April":
         (m==5)?"May":
         (m==6)?"June":
         (m==7)?"July":
         (m==8)?"August":
         (m==9)?"September":
         (m==10)?"October":
         (m==11)?"November":"December";
    return name;
}