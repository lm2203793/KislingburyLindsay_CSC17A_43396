/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Time Class Specification
 * Created on May 30, 2021, 6:32 PM
 */
#ifndef TIME_H
#define TIME_H
#include <string>
using namespace std;

class Time{
protected:
    int hour;
    int min;
    int sec;
    string amPm;
public:
    //Default constructor
    Time(){
        hour=0;
        min=0;
        sec=0;
        amPm="";
    }
    
    //Constructor
    Time(int h, int m, int s, string ampm){
        hour=h;
        min=m;
        sec=s;
        amPm=ampm;
    }
    
    //Accessor functions
    int getHour() const{
        return hour;
    }
    
    int getMin() const{
        return min;
    }
    
    int getSec() const{
        return sec;
    }
    
    string getAmPm() const{
        return amPm;
    }
};
#endif /* TIME_H */

