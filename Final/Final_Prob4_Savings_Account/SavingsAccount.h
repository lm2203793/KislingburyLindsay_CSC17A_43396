/* 
 * File:   SavingsAccount.h
 * Author: Lindsay Kislingbury
 * Purpose: SavingsAccount class Specification
 * Created on June 9, 2021, 5:48 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount{
    private:
        float Balance;                  //Property
        int   FreqWithDraw;             //Property
        int   FreqDeposit;              //Property
        float Withdraw(float);          //Utility Procedure
        float Deposit(float);           //Utility Procedure
    public:
        SavingsAccount(float bal){ //Constructor
            if(bal<0) Balance=0;
            else Balance=bal;
            FreqWithDraw=0;
            FreqDeposit=0;
        }              
        void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	     //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void  toString();                    //Output Properties
};


#endif /* SAVINGSACCOUNT_H */

