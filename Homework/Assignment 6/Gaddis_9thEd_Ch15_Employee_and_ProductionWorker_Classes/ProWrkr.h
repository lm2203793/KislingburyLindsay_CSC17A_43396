/* 
 * File:   ProWrkr.h
 * Author: Lindsay Kislingbury
 * Purpose: ProWrkr Class Specification
 *          ProWrkr is derived from Employee Class
 * Created on May 30, 2021, 3:03 PM
 */

#ifndef PROWRKR_H
#define PROWRKR_H
#include "Employee.h"
#include <string>
using namespace std;

class ProWrkr : public Employee{
    private:
        int shift;      //employees shift (1=day shift, 2=night shift)
        float hrPay;    //employees hourly pay
    public:
        //Default Constructor
        ProWrkr() : Employee(){
            shift=0; hrPay=0.0;
        }
        
        //Constructor
        ProWrkr(int sh, int py, string n, string num, int dt) 
        : Employee(n, num, dt){
            shift=sh; hrPay=py;
        }
        
        //Mutators
        void setShft(int s){
            shift=s;
        }
        
        void setHrPy(float pay){
            hrPay=pay;
        }
        
        //Accessors
        int getShft() const{
            return shift;
        }
        
        float getHrPy() const{
            return hrPay;
        }
      
};


#endif /* PROWRKR_H */

