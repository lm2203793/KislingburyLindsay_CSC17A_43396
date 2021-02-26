/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on February 25 2021, 04:57 PM
 * Purpose:  Display the number of days in a given month
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//Function Prototypes
bool leapYr(int);   //Check if the given year is a leap year

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int   month,    //Month input by user
          year,     //Year input by user
          days;     //Days in the chosen month
    int   dysLkup[12]   = {31,28,31,30,31,30,
                           31,31,30,31,30,31};//# Of Days In Each Month
    string mnthNms[12]  = {"January","February","March","April","May",
                           "June","July","August","September","October",
                           "November","December"}; //Month Names
    //Initialize Variables
    month   =  0;
    year    =  0;
    days    =  0;
    
    //Map Inputs to Outputs -> Process
    cout<<"This program displays the number of days in a given month."<<endl;   
    do{//Input Month
        cout<<"Enter a month in numerical form (EX: January = 1) : ";
        cin>>month;
        if(month<1||month>12){
            cout<<"Invalid Input!"<<endl;
        }
    }while(month<1||month>12);
    
    do{//Input Year
        cout<<"Enter a year in four digit form (EX: 2021): ";
        cin>>year;
    }while(year<1000&&year>9999);

    //Determine Number of Days in Chosen Month
    days=dysLkup[month-1];
    if(month==2){//Check if chosen year is a leap year
        if (leapYr(year)){
            days+=1; //Add one day
        }
    }
   
    //Display Inputs/Outputs
    cout<<mnthNms[month-1]<<" "<<year<<" has "<<days<<" days.";
    //Exit the Program - Cleanup
    return 0;
}

//Function Definitions
//Determine if Leap Year
bool leapYr (int year){
    if (year%4==0){
        if (year%100==0){
            if(year%400==0){
              return true;  
            }
            else return false;
        }
        else return true;
    }
    else return false;
}