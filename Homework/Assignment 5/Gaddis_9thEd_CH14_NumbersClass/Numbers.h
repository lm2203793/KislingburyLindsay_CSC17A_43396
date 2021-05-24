/* 
 * File:   Numbers.h
 * Author: Lindsay Kislingbury
 * Purpose: Numbers Class specification
 * Created on May 23, 2021, 6:33 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
#include <iostream>
using namespace std;

class Numbers{
private:
    int number;
    //Convert number into english parts
    static string cnvThou(int n);
    static string cnvHund(int);
    static string cnvTen(int,int);
    
public:
    //Constructor
    Numbers(int n){
        number=n;
    } 
    //Convert
    string convert();
    //Print
    void print(){
       cout<<"The converted amount is: ";
       cout<<convert();
    }
};


#endif /* NUMBERS_H */

