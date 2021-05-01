/* 
 * File:   main.cpp
 * Author: Lindsay Kisingbury
 * Created on April 24, 2021, 4:35 PM
 * Purpose:  Midterm Problem #2
 */

//System Libraries
#include <iostream>     //I/O Library
#include <iomanip>      //Format Library
#include "PayCheck.h"   //Pay Check Structure
using namespace std;

//Function Prototypes
PayChk *input(unsigned short &);        //Get Employee Data
void print(PayChk *, unsigned short &); //Convert Gross Pay to English
string engConv(float pay);              //Display Pay Checks

//Execution Begins Here
int main(int argc, char** argv) {  
    //Declare variables
    unsigned short emplys;  //Hold the number of employees
    PayChk *chk;            //Pointer to Pay Check Structure
    
    //Input
    cout<<"Welcome to Paycheck Generator!"<<endl;
    cout<<"To Generate Employee Paychecks, enter the Number of Employees: ";
    cin>>emplys;
    
    //Get Data
    chk=input(emplys);
    
    //Print Check
    print(chk, emplys);
    
    //Clean up
    delete chk;
    
    //Exit
    return 0;
}

//Function Implementations
//Get Employee Data
PayChk *input(unsigned short &emplys){
    PayChk *chk = new PayChk[emplys];       //Allocate Memory
    float hours, rate;
    
    //Get Company Info
    cin.clear();                            //Clear Buffer
    cin.ignore();
    cout<<"Enter the Company Name: ";       
    getline(cin, (*chk).company);
    for(int i=1; i<emplys; i++){
        chk[i].company=chk[0].company;
    }
    cout<<"Enter the Company Address: ";
    getline(cin, chk->address);
    for(int i=1; i<emplys; i++){
        chk[i].address=chk[0].address;
    }
    //Get Employee Info
    for(int i=0; i<emplys; i++){
        cout<<"Enter Employee # "<<i+1<<"'s name: ";
        getline(cin, chk[i].name);
        cout<<"Enter "<<chk[i].name<<"'s hours worked: ";
        do{//Input Validation. hours must be number >0
            cin>>hours;
            if(!cin||cin.fail()||hours<0){
                cin.clear();
                cin.ignore();
                cout<<"Invalid! Enter a positive numeric value: ";
            }
        }while(!cin||cin.fail()||hours<0);
        chk[i].hrs=hours;
        cout<<"Enter "<<chk[i].name<<"'s pay rate: ";
        do{//Input Validation. hours must be number >0
            cin>>rate;
            if(!cin||cin.fail()||rate<0){
                cin.clear();
                cin.ignore();
                cout<<"Invalid! Enter a positive numeric value: ";
            }
        }while(!cin||cin.fail()||hours<0);
        chk[i].rate=rate;
        cin.clear();                        //Clear Buffer
        cin.ignore();
        
        //Calculate employee's gross pay
        chk[i].gross=chk[i].hrs*chk[i].rate;
        
        //Get employee's pay in English
        chk[i].engPay=engConv(chk[i].gross);
    }

    return chk;
}

//Convert Gross Pay to English
string engConv(float pay){
    string amount;                 //Hold The English Pay Amount
    int    dollars=0;              //Hold Dollar Amounts
    float  c=0;                    //Hold Cents Amounts
    int    thou=0, hund=0, ten=0,  //Hold Dollar Place Values
           one=0,                   
           cHun=0, cTen=0;          //Hold Cent Place Values
    
        //Break Amount into Dollars and Cents
        dollars=static_cast<int>(pay);
        c=((dollars-pay)*-1)*100;
        
        //Break Dollar into parts
        thou=pay/1000;
        hund=dollars%1000/100;
        ten=dollars%100/10;
        one=dollars%10;
        
        //Break Cents into parts
        if(c>0)c+=0.5;  //Round up
        else c-=0.5;    //Round down
        int cents=static_cast<int>(c);
        if(cents!=0){
            if(cents>9){ 
                cHun=cents%100/10;
            }
            cTen=cents%10;
        }
        
        //English Dollar Amount
        if(dollars==0)amount+="Zero ";
        if(thou!=0){//Thousands
            amount+=(thou==9?"Nine ":
                    thou==8?"Eight ":
                    thou==7?"Seven ":
                    thou==6?"Six ":
                    thou==5?"Five ":
                    thou==4?"Four ":
                    thou==3?"Three ":
                    thou==2?"Two ":
                    thou==1?"One ":"");
            amount+="Thousand ";
        }
        if(hund!=0){//Hundreds
            amount+=(hund==9?"Nine ":
                    hund==8?"Eight ":
                    hund==7?"Seven ":
                    hund==6?"Six ":
                    hund==5?"Five ":
                    hund==4?"Four ":
                    hund==3?"Three ":
                    hund==2?"Two ":
                    hund==1?"One ":"");
            amount+="Hundred ";
        }
        if(ten!=0){//Tens
            if(ten==9)amount+="Ninety ";
            if(ten==8)amount+="Eighty ";
            if(ten==7)amount+="Seventy ";
            if(ten==6)amount+="Sixty ";
            if(ten==5)amount+="Fifty ";
            if(ten==4)amount+="Forty ";
            if(ten==3)amount+="Thirty ";
            if(ten==2)amount+="Twenty ";
            if(ten==1){
                if(one==0)amount+="Ten ";
                if(one==1)amount+="Eleven ";
                if(one==2)amount+="Twelve ";
                if(one==3)amount=+"Thirteen ";
                if(one==4)amount+="Fourteen ";
                if(one==5)amount+="Fifteen ";
                if(one==6)amount+="Sixteen ";
                if(one==7)amount+="Seventeen ";
                if(one==8)amount+="Eighteen ";
                if(one==9)amount+="Nineteen ";
            }
        }
        if(one!=1){//Ones
            amount+=(one==9?"Nine ":
            one==8?"Eight ":
            one==7?"Seven ":
            one==6?"Six ":
            one==5?"Five ":
            one==4?"Four ":
            one==3?"Three ":
            one==2?"Two ":
            one==1?"One ":"");
        }
        amount+="Dollars and ";
        
        //English Cents Amount
        if(cents!=0){
            if(cHun!=0){//Hundreds Place
                if(cHun==9)amount+="Ninety ";
                if(cHun==8)amount+="Eighty ";
                if(cHun==7)amount+="Seventy ";
                if(cHun==6)amount+="Sixty ";
                if(cHun==5)amount+="Fifty ";
                if(cHun==4)amount+="Forty ";
                if(cHun==3)amount+="Thirty ";
                if(cHun==2)amount+="Twenty ";
                if(cHun==1){
                    if(cTen==0)amount+="Ten ";
                    if(cTen==1)amount+="Eleven ";
                    if(cTen==2)amount+="Twelve ";
                    if(cTen==3)amount=+"Thirteen ";
                    if(cTen==4)amount+="Fourteen ";
                    if(cTen==5)amount+="Fifteen ";
                    if(cTen==6)amount+="Sixteen ";
                    if(cTen==7)amount+="Seventeen ";
                    if(cTen==8)amount+="Eighteen ";
                    if(cTen==9)amount+="Nineteen ";
                }
            }
            //Tens Place
            amount+=(cTen==9?"Nine ":
                        cTen==8?"Eight ":
                        cTen==7?"Seven ":
                        cTen==6?"Six ":
                        cTen==5?"Five ":
                        cTen==4?"Four ":
                        cTen==3?"Three ":
                        cTen==2?"Two ":
                        cTen==1?"One ":"");
            amount+="Cents";
        }
        else amount+="No Cents";
    return amount;
}

//Display Pay Checks
void print(PayChk *chk, unsigned short &emplys){
    unsigned short width=70, height=6;
    
    for(int emp=0; emp<emplys; emp++){
        cout<<"\n\n"<<chk[emp].name<<"'S PAYCHECK:"<<endl;
         for(int i=0; i<width; i++){
            cout<<"*";
        }
        cout<<"**"<<endl;
        cout<<chk[emp].company<<endl;         
        cout<<chk[emp].address<<endl;
        cout<<endl;
        cout<<left<<setw(40)<<chk[emp].name<<right<<setw(30)<<"April 25th 2021\n"<<endl;
        cout<<right<<setw(55)<<"$"<<left<<chk[emp].gross<<endl;
        cout<<fixed<<setprecision(2)<<chk[emp].engPay<<endl;
        cout<<left<<setw(40)<<"FOR: PAYCHECK"<<right<<setw(30)<<"................"<<endl;
        for(int j=0; j<width; j++){
            cout<<" ";
        }
        cout<<endl;
        for(int i=0; i<width; i++){
            cout<<"*";
        }
        cout<<"**"<<endl;
    }
}