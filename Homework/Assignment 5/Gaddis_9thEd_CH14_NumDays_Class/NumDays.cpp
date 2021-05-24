/* 
 * File:   NumDays.h
 * Author: Lindsay Kislingbury
 * Purpose: NumDays Member Function Definitions
 * Created on May 23, 2021, 10:56 PM
 */

#include <cstdlib>
#include "NumDays.h"

//Overloaded + (add hours and convert to days/hours)
NumDays NumDays::operator +(const NumDays &right){
    NumDays nDays;
    int temp;
    nDays.hours=hours+right.hours;
    nDays.days=nDays.hours/8;
    return nDays;
}
//Overloaded + (subtract hours and convert to days/hours)
NumDays NumDays::operator -(const NumDays &right){
    NumDays nDays;
    nDays.hours=hours-right.hours;
    nDays.days=nDays.hours/8;
    return nDays;
}
//Overloaded ++ (increment hours and convert to days/hours)
NumDays NumDays::operator ++(int){
    NumDays nDays;
    hours++;
    nDays.days=nDays.hours/8;
    return hours;
}
//Overloaded -- (decrement hours and convert to days/hours)
NumDays NumDays::operator --(int){
    NumDays nDays;
    hours--;
    nDays.days=nDays.hours/8;
    return hours;
}


