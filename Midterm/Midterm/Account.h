/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 24, 2020, 12:35 PM
 * Purpose:  Midterm Problem #1 Account Structure
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account{
    std::string     name,       //Name of the account holder
                    address;    //Address of the account holder
    unsigned short  accNum;     //Account #
    float           begBal;     //Beginning Balance
    int             numDeps,    //Number of Deposits
                    numChks;    //Number of Checks
    float           *chks,       //Total checks written by the account holder
                    *deps;     //Total deposits credited to the account/month
};

#endif /* ACCOUNT_H */

