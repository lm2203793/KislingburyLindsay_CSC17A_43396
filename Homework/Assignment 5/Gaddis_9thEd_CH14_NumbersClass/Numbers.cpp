/* 
 * File:   Numbers.h
 * Author: Lindsay Kislingbury
 * Purpose: Numbers Class Member Functions Definitions
 * Created on May 23, 2021, 6:33 PM
 */

#include <string>
#include <cstdlib>
#include "Numbers.h"
using namespace std;

//Split # into parts and convert parts to english
string Numbers::convert(){
    int ones, tens, hunds, thous;   //Hold place values
    string english;                 //Hold english amount
    //Break number into place value parts
    thous=number/1000;
    hunds=number%1000/100;
    tens=number%100/10;
    ones=number%10;
    //Build English amount
    english=cnvThou(thous)+cnvHund(hunds)+cnvTen(tens,ones)+"Dollars";
    //Return english amount
    return english;
}
//Convert Thousands
string Numbers::cnvThou(int n){
    string thou;
    if(n!=0){//Thousands
        thou+=(n==9?"Nine ":
                n==8?"Eight ":
                n==7?"Seven ":
                n==6?"Six ":
                n==5?"Five ":
                n==4?"Four ":
                n==3?"Three ":
                n==2?"Two ":
                n==1?"One ":"");
        thou+="Thousand ";
    }
    else thou="";
    return thou;
}
//Convert Hundreds
string Numbers::cnvHund(int n){
    string hund;
    if(n!=0){//Hundreds
    hund+=(n==9?"Nine ":
            n==8?"Eight ":
            n==7?"Seven ":
            n==6?"Six ":
            n==5?"Five ":
            n==4?"Four ":
            n==3?"Three ":
            n==2?"Two ":
            n==1?"One ":"");
    hund+="Hundred ";
    }
    else hund="";
    return hund;
}
//Convert Tens and Ones
string Numbers::cnvTen(int t, int o){
    string ten;
        if(t!=0){//Tens
        if(t==9)ten+="Ninety ";
        if(t==8)ten+="Eighty ";
        if(t==7)ten+="Seventy ";
        if(t==6)ten+="Sixty ";
        if(t==5)ten+="Fifty ";
        if(t==4)ten+="Forty ";
        if(t==3)ten+="Thirty ";
        if(t==2)ten+="Twenty ";
        if(t==1){
            if(o==0)ten+="Ten ";
            if(o==1)ten+="Eleven ";
            if(o==2)ten+="Twelve ";
            if(o==3)ten=+"Thirteen ";
            if(o==4)ten+="Fourteen ";
            if(o==5)ten+="Fifteen ";
            if(o==6)ten+="Sixteen ";
            if(o==7)ten+="Seventeen ";
            if(o==8)ten+="Eighteen ";
            if(o==9)ten+="Nineteen ";
        }
    }
    else if(o!=1){//Ones
        ten+=(o==9?"Nine ":
        o==8?"Eight ":
        o==7?"Seven ":
        o==6?"Six ":
        o==5?"Five ":
        o==4?"Four ":
        o==3?"Three ":
        o==2?"Two ":
        o==1?"One ":"Zero");
    }   
    return ten;
}
