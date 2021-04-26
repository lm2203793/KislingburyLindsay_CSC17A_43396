/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Account.h
 * Author: linds
 *
 * Created on April 24, 2021, 3:28 PM
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account{
    std::string     name,       //Name of the account holder
                    address;    //Address of the account holder
    unsigned short  accNum,     //Account #
                    numChks,    //Number of checks written
                    numDeps;    //Number of deposits
    float           begBal;     //Beginning Balance
    float           chks,       //Total checks written by the account holder
                    deps=0;       //Total deposits credited to the account/month
};

#endif /* ACCOUNT_H */

