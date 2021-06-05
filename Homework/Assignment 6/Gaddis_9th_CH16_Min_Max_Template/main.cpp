/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Min Max Templates
 *          Utilizes one Class MinMax to get the min and max 
 *          of char or int array
 * Created on June 1, 2021, 11:18 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "MinMax.h"


int main(int argc, char** argv) {
    int arysize;
    int modnum;
    char choice;
    
    //Choose int or char array
    cout<<"INT or CHAR array? Enter i or c: ";
    cin>>choice;
    
    if(choice=='i'){
        //create pointer to the array
        int *a;
        //Input array size
        cout<<"Enter the array size: ";
        cin>>arysize;
        //Input mod#
        cout<<"Enter the mod #: ";
        cin>>modnum; 
        //Create int array object
        MinMax<int,int*> ary(arysize, modnum);
        //Print before
        cout<<"Array before sorting:"<<endl;
        ary.print();
        //sort
        ary.sort();
        //print
        cout<<"Array after sorting:"<<endl;
        ary.print();
        //Print max
        cout<<"\nMaximum: "<<ary.getMax();
        //Print minimum
        cout<<"\nMinimum: "<<ary.getMin();
    }
    else if(choice=='c'){
        //create pointer to the array
        char *a;
        //Input array size
        cout<<"Enter the array size: ";
        cin>>arysize;
        //Create char array object
        MinMax<char,char*> ary(arysize);
        //Print before
        cout<<"Array before sorting:"<<endl;
        ary.print();
        //sort
        ary.sort();
        //print
        cout<<"Array after sorting:"<<endl;
        ary.print();
        //Print max
        cout<<"\nMaximum: "<<ary.getMax();
        //Print minimum
        cout<<"\nMinimum: "<<ary.getMin();
    }

    return 0;
}






