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
Account *input();                                       //Get Account Info
void calc(Account *, float &, float &, float &, bool &);//Balance, Overdrawn
void output(Account *, float, float, float, bool);      //Display Account Info
void destroy(Account *);                                //Deallocate Memory

//Execution of Code Begins Here
int main(int argc, char** argv) {
    
    //Declare variables
    Account *acc;         //Pointer to the Account Information Structure
    float balance=0,      //Account Balance
          totDeps=0,      //Total Deposits
          totChks=0;      //Total Checks
    bool  over=false;     //Overdrawn Status

    
    //Get Account Information   
    cout<<"This program will determine if you have exceeded your "
          "account balance."<<endl;
    acc=input();
    
    //Calculate Balance and Overdrawn Status
    calc(acc, balance, totDeps, totChks, over);
    
    //Display Account Information
    output(acc, balance, totDeps, totChks, over);
    
    //Clean up
    destroy(acc);
    
    //Exit stage right
    return 0;
}

//Function Implementations

//Get Account Information
Account *input(){
    //Allocate memory for accInfo Structure
    Account *accInfo = new Account;
    int input=0;    //Hold user input
    //Get Customer Information
    cin.clear();
    cin.ignore();
    cout<<"Enter Customer Name: ";
    getline(cin, (*accInfo).name);
    cout<<"Enter Customer Address: ";
    getline(cin, accInfo->address);
    do{                          
        cout<<"Enter the Account Number (5 digits): ";
        cin>>input;
        if(input>99999||input<10000){//Input Validation
            cout<<"Error! Account number must be 5 digits."<<endl;
            cin.clear();
            cin.ignore();
        }
    }while(input>99999||input<10000);//Loop until valid
   
    accInfo->accNum=input;          //Store account number 
    cout<<"Enter Beginning Balance: ";
    cin>>(*accInfo).begBal;
    if(!cin||cin.fail()){           //Input Validation. Must be float >0
          do{
              cin.clear();          //Clear buffer
              cin.ignore();
              cout<<"Invalid Amount! Enter an non-negative numeric amount: ";
              cin>>accInfo->begBal;               
          }while(!cin||cin.fail()); //Continue until valid input
      }

    //Get Deposit Information
    cout<<"How Many Deposits were made to the account?: ";
    cin>>accInfo->numDeps;
    accInfo->deps=new float[accInfo->numDeps];  //Allocate Memory for deposits
    cout<<"Enter All Deposits Made To The Account:"<<endl;       
    for(int i=0; i<(*accInfo).numDeps; i++){    //Input validation
        do{//Input Validation. hours must be number >0
            cout<<"Deposit Amount: ";
            cin>>accInfo->deps[i];              //Store each deposit
            if(!cin||cin.fail()||accInfo->deps[i]<0){
                cin.clear();
                cin.ignore();                   //Clear buffer
                cout<<"Invalid! Enter a positive numeric value: ";
            }
            }while(!cin||cin.fail()||accInfo->deps[i]<0); 
  }

    //Get Check Information
    cout<<"How Many Checks were written from the account?: ";
    cin>>(*accInfo).numChks;
    accInfo->chks=new float[(*accInfo).numChks]; //Allocate Memory for checks
    cout<<"Enter All Checks Written From The Account:"<<endl;       
      for(int i=0; i<(*accInfo).numChks; i++){  //Input Validation
          do{//Input Validation. hours must be number >0
            cout<<"Check Amount: ";
            cin>>accInfo->chks[i];              //Store each deposit
            if(!cin||cin.fail()||accInfo->chks[i]<0){
                cin.clear();
                cin.ignore();                   //Clear buffer
                cout<<"Invalid! Enter a positive numeric value: ";
            }
            }while(!cin||cin.fail()||accInfo->chks[i]<0); 
      }
    //Return Account Information Structure
    return accInfo;                 
}

void calc(Account *acc, float &bal, float &totDeps, float &totChks, bool &over){
   
    //Total Deposits
    for (int i=0; i<acc->numDeps; i++){
        totDeps+=acc->deps[i];
    }

    //Total Checks
    for (int i=0; i<acc->numChks; i++){
        totChks+=acc->chks[i];
    }

    //Total Balance
    bal+=acc->begBal;
    bal+=totDeps;
    bal-=totChks;

    //Determine Overdrawn Status
    if (bal<0){
        over=true;
    }
}

void output(Account *acc, float bal, float totDeps, float totChks, bool over){
    cout<<"!!!"<<over<<endl;
    
    cout<<"\t\tACCOUNT INFORMATION:"<<endl;
    cout<<right<<setw(26)<<"Name: "<<left<<(*acc).name<<endl;
    cout<<right<<setw(26)<<"Address: "<<left<<acc->address<<endl;
    cout<<right<<setw(26)<<"Account #: "<<left<<(*acc).accNum<<endl;
    cout<<right<<setw(26)<<"Beginning Balance: "<<left<<acc->begBal<<endl;
    cout<<right<<setw(26)<<"\t----------------------------"<<endl;
    cout<<right<<setw(26)<<"# of Deposits: "<<left<<(*acc).numDeps<<endl;
    cout<<right<<fixed<<setprecision(2)<<setw(26)<<"Total Deposits: "
            <<left<<totDeps<<endl;
    cout<<right<<setw(26)<<"# of Checks Written: "<<left<<(*acc).numChks
            <<endl;
    cout<<right<<fixed<<setprecision(2)<<setw(26)<<"Total Checks: "<<left
            <<totChks<<endl;
    cout<<right<<setw(26)<<"\t----------------------------"<<endl;
    if(over==true){
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

//Deallocate Memory
void destroy(Account *acc){
    delete []acc->deps;
    delete []acc->chks;
    delete acc;
}