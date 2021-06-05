/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Absolute Value Template
 * Created on June 1, 2021, 1:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Function Prototypes
template <class T>
T aVal(T &val); //Get absolute value 

int main(int argc, char** argv) {
    //Declare Variables
    int iVal; float fVal;
    char choice;
    
    cout<<"Get the absolute value of a float or an int? Enter i or f: ";
    cin>>choice;
    if(choice=='i'){
        cout<<"Enter the number: ";
        cin>>iVal;
        aVal(iVal);
        cout<<"absolute value is: "<<iVal;
    }
    else if(choice=='f'){
        cout<<"Enter the number: ";
        cin>>fVal;
        aVal(fVal);
        cout<<"absolute value is: "<<fVal;
    }
    
    return 0;
}

//Absolute Value
template <class T>
T aVal(T &val){
    if (signbit(val))
        val*=-1;
    return val;
}