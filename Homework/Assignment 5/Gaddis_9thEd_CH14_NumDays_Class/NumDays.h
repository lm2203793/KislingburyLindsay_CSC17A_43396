/* 
 * File:   NumDays.h
 * Author: Lindsay Kislingbury
 * Purpose: NumDays Class Specification
 * Created on May 23, 2021, 10:56 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
private:
    float days;
    float hours;
    
public:
    //Constructor
    NumDays(float n=0){
        hours=n;
        days=n/8;
    }
    //Get hours
    float getHrs(){
        return hours;
    }
    //Get Days
    float getDays(){
        return days;
    }
    //Overloaded Operator Functions
    NumDays operator + (const NumDays &); //Overloaded +
    NumDays operator - (const NumDays &); //Overloaded -
    NumDays operator ++(int); //Overloaded ++
    NumDays operator --(int); //Overloaded --
};




#endif /* NUMDAYS_H */

