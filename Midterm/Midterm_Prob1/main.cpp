/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 24, 2020, 12:35 PM
 * Purpose:  Midterm Problem #1
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formating Library
#include "Account.h" //Account Information Structure
using namespace std;

//Function Prototypes
Account *input();                   //Get Account Information
bool calc(Account *, float &);      //Calculate Balance and Overdrawn Status
void output(Account *, float);      //Display Account Information

//Execution of Code Begins Here
int main(int argc, char** argv) {
    
    //Declare variables
    Account *acc;  //Pointer to the Account Information Structure
    float balance; //Hold Account Balance
    
    //Initialize all known variables
    balance=0;
    
    //Get Account Information   
    cout<<"This program will determine if you have exceeded your "
          "account balance."<<endl;
    acc=input();
    
    //Calculate Balance and Overdrawn Status
    calc(acc, balance);
    
    //Display Account Information
    output(acc, balance);
    
    //Clean up
    delete acc;
    
    //Exit stage right
    return 0;
}

//Function Implementations

//Get Account Information
Account *input(){
    Account *accInfo = new Account;
    float x=0;          //Hold Customer Input
    int counter=0;      //Hold number of deposits/checks
    char choice;        //Hold menu choice
    
    //Get Customer Information
    cout<<"Enter Customer Name: ";
    getline(cin, (*accInfo).name);
    cout<<"Enter Customer Address: ";
    getline(cin, accInfo->address);
    do{                             
        cout<<"Enter the Account Number (5 digits or less): ";
        cin>>x;
        accInfo->accNum=x;
        if(x>9999)                  //Error message if acc# is longer than 5 digits
           cout<<"Error! Account number is less than 5 digits."<<endl;
    }while(x>9999);                 //Loop until customer enters valid acc#
    
    cout<<"Enter Beginning Balance: ";
    cin>>(*accInfo).begBal;
    if(!cin||cin.fail()){         //Input Validation. Must be float >0
          do{
              cin.clear();        //Clear buffer
              cin.ignore();
              cout<<"Invalid Amount! Enter an non-negative numeric amount: ";
              cin>>accInfo->begBal;               
          }while(!cin||cin.fail());//Continue until valid input
      }
    
    //Get Deposit Information
    cout<<"Enter All Deposits Made To The Account:"<<endl;
    do{
      counter++;                    //Count number of deposits
      cout<<"Check Amount: ";       
    do{//Input Validation. hours must be number >0
        cin>>x;
        if(!cin||cin.fail()||x<0){
            cin.clear();
            cin.ignore();
            cout<<"Invalid! Enter a positive numeric value: ";
        }
    }while(!cin||cin.fail()||x<0); 
        accInfo->deps+=x;               //Add to total deposits

        do{//Ask for additional deposits
            cout<<"Enter Another Deposit? Enter y or n: ";
            cin>>choice;
            if(choice=='n')             //If no more deposits, end loop
                break;
            }while(choice!='y');        //Input validation, must enter n or y
    }while(choice=='y');                //Continue deposit input until done
    
    accInfo->numDeps=counter;           //Store number of deposits
    counter=0;                          //Reset counter
    x=0;                                //Reset input variable
    
    
    cout<<"Enter All Checks Written From The Account:"<<endl;
    do{
      counter++;                        //Count number of checks
      cout<<"Check Amount: ";     
        do{//Input Validation. hours must be number >0
            cin>>x;
            if(!cin||cin.fail()||x<0){
                cin.clear();
                cin.ignore();
                cout<<"Invalid! Enter a positive numeric value: ";
            }
        }while(!cin||cin.fail()||x<0);          
      accInfo->chks+=x;             //Add to total deposits
      x=0;                          //Reset input variable
      do{   
        cout<<"Enter Another Check? Enter y or n: ";
        cin>>choice;
        if(choice=='n')             //If no more deposits, end loop
            break;
        }while(choice!='y');        //Input validation, must enter n or y
    }while(choice=='y');            //Continue check input until customer is done
    
    accInfo->numChks=counter;       //Store number of checks written

    return accInfo;                 //Return Account Information Structure
};

bool calc(Account *acc, float &bal){
    bool over=false;                //Flag. Overdrawn=true
    
    //Total Balance
    bal=(acc->begBal+acc->deps)-acc->chks;
    
    //Determine Overdrawn Status
    if (bal<0){
        over=true;
    }
    return over;
}

void output(Account *acc, float bal){
    cout<<"\t\tACCOUNT INFORMATION:"<<endl;
    cout<<right<<setw(26)<<"Name: "<<left<<(*acc).name<<endl;
    cout<<right<<setw(26)<<"Address: "<<left<<acc->address<<endl;
    cout<<right<<setw(26)<<"Account #: "<<left<<(*acc).accNum<<endl;
    cout<<right<<setw(26)<<"Beginning Balance: "<<left<<acc->begBal<<endl;
    cout<<right<<setw(26)<<"\t----------------------------"<<endl;
    cout<<right<<setw(26)<<"# of Deposits: "<<left<<(*acc).numDeps<<endl;
    cout<<right<<fixed<<setprecision(2)<<setw(26)<<"Total Deposits: "
            <<left<<acc->deps<<endl;
    cout<<right<<setw(26)<<"# of Checks Written: "<<left<<(*acc).numChks
            <<endl;
    cout<<right<<fixed<<setprecision(2)<<setw(26)<<"Total Checks: "<<left
            <<acc->chks<<endl;
    cout<<right<<setw(26)<<"\t----------------------------"<<endl;
    if(calc(acc, bal)){
        cout<<right<<setw(26)<<"ACCOUNT OVERDRAWN BY $"<<bal<<":"<<endl;
        cout<<right<<setw(26)<<"$20 Fee Has Been Applied and Debited From"
                <<" Your Account"<<endl;
        cout<<right<<setw(26)<<"New Balance: $"<<(bal-20)<<endl;
    }
    else{
        cout<<right<<setw(26)<<"ACCOUNT IN GOOD STANDING"<<endl;
        cout<<right<<setw(26)<<"BALANCE: $"<<bal<<endl;
    }
}