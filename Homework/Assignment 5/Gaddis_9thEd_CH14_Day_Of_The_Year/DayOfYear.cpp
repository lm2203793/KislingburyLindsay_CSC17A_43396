/* 
 * File:   DayOfYear.h
 * Author: Lindsay Kislingbury
 * Purpose: DayOfYear Member Function Definitions
 * Created on May 23, 2021, 7:38 PM
 */

#include <string>
#include <cstdlib>
#include "DayOfYear.h"
using namespace std;

//Declare and Initialize static member variable outside of class declaration
const string DayOfYear::MNTHNMS[]={"January","February","March","April","May",
"June","July","August","September","October","November","December"};

const int DayOfYear::MNTHDYS[]={31,28,31,30,31,30,31,31,30,31,30,31};

//Member Functions
//Convert
string DayOfYear::cnvDate(){
    string date;            //Hold string date
    ostringstream stream;   //String Stream for converting int day to string
    string output;          //Hold string day
    int m=0;                //Month counter
    int days=num;           //Set days = input num
    
    do{ //Loop until all months are checked
        days-=MNTHDYS[m];   //Subtract # of days in each month from total
        if(days<=0){        //If days are negative, month is Jan
            days=num;           //days is number input
            date=MNTHNMS[0]+" ";
            stream<<days;       //Convert days to string
            output=stream.str();
            date+=output;
            return date;        //Return date
        }
        else if(days<MNTHDYS[m+1]){//If days < # of days in next mnth
            date=MNTHNMS[m+1]+" ";      //month is the next month
            stream<<days;               //Convert days to string
            output=stream.str();
            date+=output;
            return date;                //Return date
        }
        m++;                //Increment months
    }while(days>31);      
}
