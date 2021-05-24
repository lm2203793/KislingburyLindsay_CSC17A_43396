/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Day of Year 
 * Created on May 23, 2021, 7:37 PM
 */

#include <cstdlib>
#include "DayOfYear.h"
using namespace std;

int main(int argc, char** argv) {
    int n;      //Hold number input
    bool error; //Input Validation Flag
    //Input day
    do{
        error=false;
        cout<<"Input a day of the year, 1 to 365: ";
        cin>>n;
        if(n>=365||n<0||!cin||cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Error! Input a day 1 to 365"<<endl;
            error=true;
        }
    }while(error);
    //Create DayOfYear object
    DayOfYear date(n);
    
    //Output Date
    date.print();
        
    return 0;
}

