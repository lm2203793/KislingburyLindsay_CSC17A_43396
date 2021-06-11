/* 
 * File:   Employee.h
 * Author: Lindsay Kislingbury
 * Purpose: Employee Class Specification
 * Created on June 10, 2021, 12:47 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee{
private:
    double Tax(float);      //Utility
    char   MyName[20];      //Property
    char   JobTitle[20];    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property
public:
    //Constructor
    Employee(char[], char[], float);
    //Procedure
    float  CalculatePay(float rate, int hours){
        getNetPay(getGrossPay(rate, hours));  
    } 
    //Procedure
    float  getGrossPay(float, int);
    //Procedure
    float  getNetPay(float); 
    //Procedure
    void   toString();
    //Procedure
    int    setHoursWorked(int hours){
        HoursWorked=hours;
        return HoursWorked;
    }     
    //Procedure
    float  setHourlyRate(float rate){
        HourlyRate=rate;
        return HourlyRate;
    }    
    //Exception Class
    class InvalidHours{
    private:
        int invHours;
    public:
        InvalidHours(int h){
            invHours=h;
        }
        int getInvHours() const{
            return invHours;
        }
    };
};


#endif /* EMPLOYEE_H */

