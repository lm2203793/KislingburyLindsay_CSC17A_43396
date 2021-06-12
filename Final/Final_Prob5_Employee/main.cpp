/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Employee Class
 * Created on June 10, 2021, 12:34 PM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
//User Libraries
#include "Employee.h"
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char cName[20]; //Employee name
    char cTitle[20];//Employee title
    float rate;     //Hourly rate
    bool tryAgn;    //Input Validation
    string name;    //Hold name for input validation
    string title;   //Hold title for input validation
    char choice;    //Choice to repeat
    bool repeat;    //true=repeat
    do{
        cout<<"Employee Pay Calculator"<<endl;
        //Input Name, Job Title and Hourly Rate
        cout<<"Input Name: ";
        getline(cin, name);
        while(name.length()>20){ //Input Validation
            cout<<"Name too long! Must be 20 characters or less"<<endl;
            getline(cin, name);
        }
        for(int i=0; i<name.length(); i++){ //Convert to c string
            cName[i]=name[i];
        }
        cout<<"Input Job Title: ";
        getline(cin, title);
        while(title.length()>20){ //Input Validation
            cout<<"Title too long! Must be 20 characters or less"<<endl;
            getline(cin, title);
        }
        for(int i=0; i<title.length(); i++){ //Convert to c string
            cTitle[i]=title[i];
        }
        cout<<"Input Hourly Rate: ";
        cin>>rate;

        //Create Employee Object
        Employee emp(cName,cTitle,rate);
        //Input Hours Worked
        int hours;
        cout<<"Input Hours Worked: ";
        cin>>hours;
        while(tryAgn){ //Input Validation with Exception
            try{
                emp.setHoursWorked(hours);
                tryAgn=false;
            }
            catch(Employee::InvalidHours h){
                cout<<"Unacceptable Hours Worked!"<<endl;
                cout<<"Input Hours Worked: ";
                cin>>hours;
            }
        }
        emp.setHoursWorked(hours);
        emp.CalculatePay(rate, hours);
        emp.toString();

        //Ask to run again
        cout<<"\nEnter y to Calculate Another Employee or any other key to quit"<<endl;
        cin>>choice;
        if(choice=='y') repeat=true;
        cin.ignore();
        cin.clear();
    }while(repeat);
    
    //Exit
    return 0;
}

