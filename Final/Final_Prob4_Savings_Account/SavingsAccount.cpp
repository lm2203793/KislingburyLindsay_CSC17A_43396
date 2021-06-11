/* 
 * File:   SavingsAccount.h
 * Author: Lindsay Kislingbury
 * Purpose: SavingsAccount Class Member Definitions
 * Purpose: SavingsAccount 
 * Created on June 9, 2021, 5:48 PM
 */
#include <iostream>
#include "SavingsAccount.h"
using namespace std;
//Constructor

//Utility Procedure
float SavingsAccount::Withdraw(float amount){
    float nBal;
    amount*=-1; //Convert to positive
    nBal=(Balance-amount); //Subtract from Balance
    if(nBal>0){ //If the balance after withdrawing > zero
        Balance=nBal;
        FreqWithDraw++;
        return nBal;
    }
    else{ 
        cout<<"Withdraw Not Allowed"<<endl;
    }
}  

//Utility Procedure
float SavingsAccount::Deposit(float amount){
    Balance=(Balance+amount);
    FreqDeposit++;
    return Balance;
}           

//Procedure
void  SavingsAccount::Transaction(float amount){
    if(amount<0) Withdraw(amount);
    else Deposit(amount);
}          

//Savings Procedure
float SavingsAccount::Total(float rate, int years){ 
    rate/=100; //Convert to decimal
    float bal; //Hold balance to return
    float intrst=Balance*rate*years; //I=Prt
    bal=Balance+intrst; //Add interest to Balance
    return bal;
}	 

float SavingsAccount::TotalRecursive(float rate,int years){
    rate/=100;  //Convert to decimal
    float total;//Hold total to return
    for(int i=0; i<years; i++){ //Loop on years
        Balance+=(Balance*rate);//Add interest for each year to balance
    }
    total=Balance;
    return total;
}

//Output Properties
void  SavingsAccount::toString(){
    cout<<"Balance = "<<Balance<<endl;
    cout<<"Withdraws = "<<FreqWithDraw<<endl;
    cout<<"Deposits = "<<FreqDeposit<<endl;
}                   

