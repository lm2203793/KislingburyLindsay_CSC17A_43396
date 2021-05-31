/* 
 * File:   Date.h
 * Author: Lindsay Kislingbury
 * Purpose: Specification for Date class]
 *          Includes Exception Classes that store error data
 * Created on May 30, 2021, 9:34 PM
 */

#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date{
private:
    int     month,  //Month
            day,    //Day
            year;   //Year
public:
    //Default constructor initializes values to 0
    Date(){ 
        month=0;
        day=0;
        year=0;
    }
    //Exception Class for an Invalid Day
    class InvDay{
    private:
        int value; //hold invalid day
    public:
        InvDay(int val){
            value=val;
        }
        int getVal() const{
            return value;
        }
    };
    //Exception Class for Invalid Month
    class InvMnth{
    private:
        int value; //hold invalid month
    public:
        InvMnth(int val){ 
            value=val; 
        }
        int getVal() const{
            return value;
        }
    };
    //Exception Class for Invalid Year
    class InvYr{
    private:
        int value; //hold invalid year
    public:
        InvYr(int val){
            value=val;
        }
        int getVal() const{
            return value;
        }
    };
    //Set Functions
    void setDay(int); //Defined in Date.cpp
    void setMnth(int);//Defined in Date.cpp
    void setYr(int);  //Defined in Date.cpp
    //Get functions
    int getMnth() const{ //Get month
        return month;
    }
    int getDay() const{ //Get day
        return day;
    }
    int getYear() const{ //Get year
        return year;
    }
    //Convert Month to English
    string cnvMnth(int);//Defined in Date.cpp  
};


#endif /* DATE_H */

