/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: SavingsAccount Class Specification
 * Created on June 9, 2021, 5:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float bal;      //Hold balance input
    float amount;   //Hold transaction input
    float rate;     //Hold rate input
    int years;      //Hold years input
    char choice;    //Hold repeat choice
    
    //Inputs
    cout<<"Enter Savings Account Details"<<endl;
    cout<<"Input the starting balance: ";
    cin>>bal;
    //Create SavingsAccount object
    SavingsAccount acc(bal);
    do{
        //Make transactions
        cout<<"Input a deposit or withdrawal"<<endl;
        cin>>amount;
        acc.Transaction(amount);
        cout<<"Enter y to enter another transaction or any other key to finish"<<endl;
        cin>>choice;
    }while(choice=='y');
    //Display Withdrawal/Deposit Information
    acc.toString();
    //Input Savings Account Info
    cout<<"Input the Savings Account rate of interest: ";
    cin>>rate;
    cout<<"Input the # of years: ";
    cin>>years;
    //Display Final Balance with interest
    acc.toString();
    cout<<"Balance after "<<years<<" years given "<<fixed<<setprecision(2)<<rate<<"% SIMPLE interest = "
            <<acc.Total(rate,years)<<endl;
    cout<<"Balance after "<<years<<" years given "<<fixed<<setprecision(2)<<rate<<"% COMPOUND (recursive) interest = "
            <<acc.TotalRecursive(rate,years)<<endl;
    return 0;
}

