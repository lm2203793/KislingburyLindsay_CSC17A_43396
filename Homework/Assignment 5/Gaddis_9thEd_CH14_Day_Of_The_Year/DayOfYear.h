/* 
 * File:   DayOfYear.h
 * Author: Lindsay Kislingbury
 * Purpose: DayOfYear Class Specification
 * Created on May 23, 2021, 7:38 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class DayOfYear{
private:
    static const string MNTHNMS[]; 
    static const int MNTHDYS[];
    int num;
public:
    //Constructor
    DayOfYear(int n){
        num=n;
    }
    
    //Convert Date
    string cnvDate();
    
    //Print
    void print(){
        cout<<"That is: ";
        cout<<cnvDate()<<endl;
    }
};


#endif /* DAYOFYEAR_H */

