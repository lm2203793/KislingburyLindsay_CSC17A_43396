/*
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Determines Essay Grade
 *          Demonstrates Inheritance
 * Created on May 30, 2021, 7:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "Essay.h"
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int gram, spel, len, cont;
    
    //Input Essay Points
    cout<<"Determine Your Essay Grade!"<<endl;
    cout<<"Enter Points (out of 100) Received for each category"<<endl;
    cout<<"Grammar Points: ";
    cin>>gram;
    cout<<"Spelling Points: ";
    cin>>spel;
    cout<<"Length Points: ";
    cin>>len;
    cout<<"Content Points: ";
    cin>>cont;
    
    //Create Essay object
    Essay essay1(gram,spel,len,cont);
    
    //Display 
    cout<<"Your Score: "<<essay1.getScore()<<endl;
    cout<<"Your Grade: "<<essay1.ltrGrade()<<endl;
    
    
    return 0;
}

