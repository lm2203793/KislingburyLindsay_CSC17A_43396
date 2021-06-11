/* 
 * File:   Employee.h
 * Author: Lindsay Kislingbury
 * Purpose: Employee Class Member Function Definitions
 * Created on June 10, 2021, 12:47 PM
 */
#include "Employee.h"


//Constructor
Employee::Employee(char name[], char title[], float rate){//Constructor
    for(int i=0; i<20; i++) MyName[i]=name[i];
    for(int i=0; i<20; i++) JobTitle[i]=title[i];
    HourlyRate=rate;
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}  

//Calculate Gross Pay
float  Employee::getGrossPay(float rate, int hours){
    float gross=0; //Hold the calculated gross pay to return
    int dbl=0;     //Hold double time hours
    //Start
    if(hours>40){ //If hours are greater than 40
        gross+=(40*rate); //Add 40 straight time hours at straight time rate
        hours-=40;     //Subtract 40 hours
        if(hours>10){//If hours are greater than 10
            gross+=(10*(rate*1.5)); //add 10 over time hours at overtime rate (rate * 1.5)
            dbl=hours-10;//Double time hours = hours-10
            gross+=(dbl*(rate*2)); //add the double time hours at double time rate  (rate * 2)
        }
        else{ //Else if hours are not greater than 10
            gross+=(hours*(rate*1.5));
        }
    }
    else{//Else if hours are not greater than 40
        gross=hours*rate; //Calculate straight time at straight time rate
    }
    //Return gross pay
    GrossPay=gross;
    return gross;
}

//Calculate Taxes
double Employee::Tax(float gross){ //Utility Procedure
    double tax=0;   //Hold the taxes to return
    double hTax=0;  //Hold the taxes at highest tax bracket

    if(gross>500){ //If gross pay is greater than $500
       tax+=(500*0.1); //Add taxes at 0.1 rate for $500
       gross-=500;     //Subtract $500
       if(gross>500){//If gross is still greater than $500 
           tax+=(500*0.2); //Add taxes at 0.2 rate for $500
           hTax=gross-500;//gross - 500 is taxed at highest bracket
           tax+=(hTax*0.3); //Add taxes 0.3 rate for remaining pay
       }
       else{ //Else if gross is not greater than 500
           tax+=(gross*0.2); //Add taxes at 0.2 rate for remaining pay
       }
   }
    else{//Else if gross is not greater than 500
       tax=gross*0.1; //Add taxes at 0.1 rate for entire pay
   }
    return tax;
} 

//Calculate Net Pay
float Employee::getNetPay(float gross){//Procedure
    float net;
    double taxes=Tax(getGrossPay(HourlyRate, HoursWorked));
    gross=getGrossPay(HourlyRate, HoursWorked);
    net=gross-taxes;
    NetPay=net;
    return net;
} 

void  Employee::toString(){
    cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<"Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked;
    cout<<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
} 


