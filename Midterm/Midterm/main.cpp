/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 28, 2021 4:46PM
 * Purpose:  Midterm
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstring>   //C String Library
#include <vector>    //Vector Library
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
#include "Account.h" //Account Information Structure
#include "PayCheck.h"//Pay Check Structure
#include "Array.h"   //Array Structure
#include "Stats.h"   //Stats Structure
#include "Prime.h"   //Prime Structure
#include "Primes.h"  //Primes Structure


using namespace std;

//Function Prototypes
void menu();
//Problem #1
void p1main();                                   //Problem #1 Program
Account *input();                                       //Get Account Info
void calc(Account *, float &, float &, float &, bool &);//Balance, Overdrawn
void output(Account *, float, float, float, bool);      //Display Account Info
void destroy(Account *);                                //Deallocate Memory
//Problem #2
void p2main();                                  //Problem #2 Program
PayChk *input(unsigned short &);                //Get Employee Data
void print(PayChk *, unsigned short &);         //Convert Gross Pay to English
string engConv(float pay);                      //Display Pay Checks
//Problem #3
void p3main();                  //Problem #3 Program
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure
//Problem #4
void p4main();                  //Problem #4 Program
char *getDat(int);              //Get Input
int *encrypt(char *, int);      //Encrypt Number
void conv(char *, int *, int);  //Conversion to int array
int *decrypt(char *, int);      //Decrypt Number
void options(char *, int);      //Menu
void display(int *, int);       //Display Encrypted or Decrypted Number
//Problem #5
void p5main();  //Problem #5 Problem
void type();    //Menu
void chtr();    //Char  
void unChar();  //Unsigned Char
void shInt();   //Short Int
void unShInt(); //Unsigned Short Int
void integer(); //Int
void unInt();   //Unsigned Int
void lngInt();  //Long Int
void flt();     //Float
void dbl();     //Double
//Problem #6
void p6main();
//Problem #7
void p7main();
Primes *factor(int);             //Input an integer, return all prime factors
void prntPrm(Primes *, int);     //Output all prime factors
void clean(Primes *);            //Deallocate memory 

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    char choice;
    
    //Menu Greeting
    cout<<"Lindsay Kislingbuy\nCIS 17a 43396\nMidterm"<<endl;
    
    do{
        menu();         //Display Menu Greeting
        cin>>choice;    
        switch(choice){
            case '1'://Problem 1
                p1main();
                break;
            case '2'://Problem 2
                p2main();
                break;
            case '3'://Problem 3
                p3main();
                break;
            case '4'://Problem 4
                p4main();
                break;
            case '5'://Problem 5
                p5main();
                break;
            case '6'://Problem 6
                p6main();
                break;
            case '7'://Problem 7
                p7main();
                break;
        }
    }while(choice!='q');
    
    
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void menu(){
    cout<<endl;
    cout<<"\nChoose a Problem:"<<endl;
    cout<<"1: Checking Account Balance"<<endl;
    cout<<"2: Check Generator"<<endl;
    cout<<"3: Mean Median and Mode"<<endl;
    cout<<"4: Encryption Machine"<<endl;
    cout<<"5: Data Type Limits"<<endl;
    cout<<"6: Conversions"<<endl;
    cout<<"7: Prime Factorization"<<endl;
    cout<<"q: Quit Program"<<endl;
}

//**************************************************************************//
// *                            PROBLEM #1                                  //
//**************************************************************************//
//main
void p1main(){
    
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
    
    //Clear Buffer
    cin.clear();
    cin.ignore();
}
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

//**************************************************************************//
// *                            PROBLEM #2                                  //
//**************************************************************************//
//main
void p2main(){
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
}
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
//**************************************************************************//
// *                            PROBLEM #3                                  //
//**************************************************************************//
void p3main(){
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
}
//Copy the array
int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}
//Print the structure
void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}
//Sort an array
void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}
//Recover memory from the Stats Structure
void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}
//Recover memory from the Array Structure
void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}
//Print the array 
void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
//Fill an array and put into a structure
Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}
//Find & store mean, median, & modes in structure
Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    
    //Mode    
    //Allocate the mode array
    stats->mode=new Array;
    //Find max frequency
    int freq=0, nmodes=0;
    for(int i=0; i<array->size; i++){
        int count=0;                                //Instances of the number
        for(int j=0; j<array->size; j++){
            if(array->data[j]==array->data[i]){     //Element matches
                count++;                            //Increment Count
            }
        }   
        if(count>=freq){
            freq=count;                             //Highest Count
        }
    }
    
    //Store the max frequency
    stats->modFreq=freq;
    
    //Find number of modes
    for(int i=0; i<array->size; i++){
        int match=0;                                //Number of matches found
            for(int k=i+1; k<(i+freq); k++){
                if(array->data[i]==array->data[k]){ //Element matches
                    match++;                        //Increment match
                  if(match==(freq-1)){              //Matches = Max frequency
                      nmodes++;                     //Increment number of modes
                      i=k;                          //Skip over to next value
                      break; 
                  }
                }                               
                else{                               //Element doesn't match
                    i=k;                            //Skip over to next value
                    break;
                  }
            }     
    }
    
    //Store the number of modes
    stats->mode->size=nmodes;
    
    if(nmodes!=0){
       stats->mode->data=new int[stats->mode->size];
        //Fill the mode array
        int indx=0;                             //Index to store mode values
        int count=0;                            //Count number of modes
        for(int i=0; i<array->size; i++){
            int match=0;                        //Number of matches found
                for(int k=i+1; k<(i+freq); k++){
                    if(array->data[i]==array->data[k]){//Match
                        match++;
                      if(match==(freq-1)){      //Number of matches = Max freq
                          stats->mode->data[indx]=array->data[i]; //Store 
                          indx++;               //Increment index
                          i=k;                  //Skip over to next value
                          break; 
                      }
                    }
                    else{                       //Match not found, skip over
                        i=k;
                        break;
                      }
                }     
        }
    }
    //Median
    //The number in the middle, or the average of the two middle numbers
    float median=0.0;                            //Hold the median value
    if(array->size%2 != 0){                      //If the array size is even         
        median=array->data[array->size/2];       //Get the middle value          
    }
    else{                                        //If the array size is odd
        median=array->data[(array->size-1)/2];   //Average of middle numbers
    }
    
    //Store the median
    stats->median=median;
    
    //Mean (average)
    float mean=0.0;
    for(int i=0; i<array->size; i++){
        mean+=array->data[i];                 //Sum all values
    }   
    mean/=array->size;                           //Divide by number of values
    
    //Store the average
    stats->avg=mean;
    
    return stats;
}
//**************************************************************************//
// *                            PROBLEM #4                                  //
//**************************************************************************//
void p4main(){
    //Declare all variables for this function
    int arySize=4;
    char *input;
    
    //Display menu
    options(input, arySize);
    
    //Deallocate memory
    delete input;
}
//Get Input
char *getDat(int arySize){
    char *ary=new char[arySize];
    cout<<"Input a 4-digit number: ";
    cin>>ary;
    for(int i=0; i<arySize; i++){
        if(ary[i]=='8'||ary[i]=='9'){
            cout<<"Invalid Input!"<<endl;
            cout<<"Utilize digits 0,1,2,3,4,5,6,7 only!"<<endl;
            cout<<"Re-enter 4-digit number to encrypt: ";
            cin>>ary;
        }
    }
    return ary;
}
//Encrypt Number
int *encrypt(char *ary, int arySize){
    int *encrypt=new int[arySize];
    
    //Fill encrypt 
    for(int i=0; i<arySize; i++){
        encrypt[i]=static_cast<int>(ary[i]-'0');
    }
    
    //Encryption Step One: Convert
    for(int i=0; i<arySize; i++){
        encrypt[i]=floor(encrypt[i]+5);      //Add 5 to each digit
        encrypt[i]=floor(encrypt[i]%8);      //Mod 8 each digit
    }

    //Encryption Step Two: Swap
    int temp=0;                             //temp variable for swap
    temp=encrypt[0];
    encrypt[0]=encrypt[2];                  //swap first digit with third
    encrypt[2]=temp;
    
    temp=encrypt[1];
    encrypt[1]=encrypt[3];                  //swap second digit with fourth
    encrypt[3]=temp;

    return encrypt;
}

//Decrypt Number
int *decrypt(char *ary, int arySize){
    int *decrypt=new int[arySize];
    int swap[arySize]={0,0,0,0};
    //Fill decrypt 
    for(int i=0; i<arySize; i++){
        decrypt[i]=static_cast<int>(ary[i]-'0');
    }
    //Decryption Step One: Swap
    int temp=0;                             //temp variable for swap
    temp=decrypt[0];
    decrypt[0]=decrypt[2];                  //swap first digit with third
    decrypt[2]=temp;
    
    temp=decrypt[1];
    decrypt[1]=decrypt[3];                  //swap second digit with fourth
    decrypt[3]=temp;

    //Decryption Step Two:
    for(int i=0; i<arySize; i++){ //Decryption Key
        if(decrypt[i]==0)swap[i]=3;
        if(decrypt[i]==1)swap[i]=4;
        if(decrypt[i]==2)swap[i]=5;
        if(decrypt[i]==3)swap[i]=6;
        if(decrypt[i]==4)swap[i]=7;
        if(decrypt[i]==5)swap[i]=0;
        if(decrypt[i]==6)swap[i]=1;
        if(decrypt[i]==7)swap[i]=2;
    }
    for(int i=0; i<arySize; i++){
        decrypt[i]=swap[i];
    }
    
    return decrypt;
}
//Display Encrypted or Decrypted Number
void display(int *output, int arySize){
    cout<<"Result: ";
        for(int i=0; i<arySize; i++){
            cout<<output[i];
        }
}
//Menu
void options(char *input, int arySize){
    int *output=new int[arySize];
    char choice=0;      //Menu Choice
    int flag=0;    //Flag to Quit Menu
    cout<<"Encryption Machine!"<<endl;
    cout<<"This program will encrypt or decrypt a 4-digit number"<<endl;
    cout<<"This program utilizes digits 0,1,2,3,4,5,6,7 only"<<endl;
    while(flag==0){
        cout<<"\n\nEnter 1 to Encrypt.\nEnter 2 to Decrypt\nEnter q to Quit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        switch(choice){
            case '1': 
                input=getDat(arySize);          //Get Number
                output=encrypt(input, arySize); //Encrypt 
                display(output, arySize);         //Display
                break;
            case '2': 
                input=getDat(arySize);          //Get Number
                output=decrypt(input, arySize); //Decrypt 
                display(output, arySize);         //Display
                break;
            case 'q':                           //Quit Program
            case 'Q':
                cout<<"End Program";
                flag=1;
                break;
            default:                            //Input Validation
                cout<<"Invalid Entry!"<<endl;
                cout<<"Enter 1 to Encrypt.\nEnter 2 to Decrypt\nEnter q to Quit"<<endl;
                cin>>choice;
                break;
        }
    };
    
    //Deallocate Memory
    delete output;
}
//**************************************************************************//
// *                            PROBLEM #5                                  //
//**************************************************************************//
void p5main(){
    //Run Program
    type();
}
//Menu
void type(){
    char choice;
    cout<<"Find the largest n where n!=factorial that can be calculated"<<endl;
    cout<<"For each data type."<<endl;
    do{
        cout<<"\nChoose a data type to test:"<<endl;
        cout<<left<<setw(23)<<"1. Char"<<setw(23)<<"2. Unsigned Char"<<setw(23)<<"3. Short Int"<<endl;
        cout<<setw(23)<<"4. Unsigned Short Int"<<setw(23)<<"5. Int"<<setw(23)<<"6. Unsigned Int"<<setw(23)<<"7. Long Int"<<endl;
        cout<<setw(23)<<"8. Float"<<setw(23)<<"9. Double"<<endl;
        cout<<"Enter q to quit"<<endl;
        cin>>choice;
        switch(choice){
            case '1': //Char
                chtr();
                break;
            case '2': //Unsigned Char
                unChar();
                break;
            case '3': //Short int
                shInt();
                break;
            case '4': //Unsigned short int
                unShInt();
                break;
            case '5': //Int
                integer();
                break;
            case '6': //Unsigned Int
                unInt();
                break;
            case '7': //Long Int
                lngInt();
                break;
            case '8': //Float
                flt();
                break;
            case '9': //Double
                dbl();
                break;
        }      
    }while(choice!='q');
}
//Char
void chtr(){
    char n=1;
    vector<char>vals;
    int x=100;
    cout<<"\nCHAR"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<int(n)<<endl;
        if(n<=0||n<vals[i-1]||n>127){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Unsigned Char
void unChar(){
    unsigned char n=1;
    vector<unsigned char>vals;
    int x=100;
    cout<<"\nUNSIGNED CHAR"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<int(n)<<endl;
        if(n<=0||n<vals[i-1]||n>255){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Short int
void shInt(){
    short int n=1;
    vector<short int>vals;
    int x=100;
    cout<<"\nSHORT INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<0||n<vals[i-1]||n>32767){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Unsigned short int
void unShInt(){
    unsigned short int n=1;
    vector<unsigned short int>vals;
    int x=100;
    cout<<"\nUNSIGNED SHORT INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>65535){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Int
void integer(){
    int n=1;
    vector<int>vals;
    int x=100;
    cout<<"\nINT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]>n>2147483647){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Unsigned Int
void unInt(){
    unsigned int n=1;
    vector<unsigned int>vals;
    int x=100;
    cout<<"\nUNSIGNED INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>4294967295){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Long Int
void lngInt(){
    long int n=1;
    vector<long int>vals;
    int x=100;
    cout<<"\nLONG INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>9223372036854775807){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Float
void flt(){
    float n=1;
    vector<float>vals;
    int x=200;
    cout<<"\nFLOAT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>3.40282e+38){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Double
void dbl(){
    double n=1;
    vector<double>vals;
    int x=200;
    cout<<"\nFLOAT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>1.79769e+308){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//**************************************************************************//
// *                            PROBLEM #6                                  //
//**************************************************************************//
//Display
void p6main(){
    cout<<"Handwritten Solutions Included In Midterm Project Folder"<<endl;
    cout<<"Part A:"<<endl;
    cout<<left<<setw(12)<<"2.875 "<<left<<setw(10)<<"base 10 ="<<endl;
    cout<<left<<setw(12)<<"2.E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"10.111 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"2.7 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(12)<<"\n0.1796875 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(12)<<"0.2E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"0.0010 1110 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"0.134 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<"\nPart B:"<<endl;
    cout<<left<<setw(12)<<"-2.875 "<<left<<setw(10)<<"base 10 ="<<endl;
    cout<<left<<setw(12)<<"-2.E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"10.1111 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"-2.7 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(12)<<"\n0.1796875 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(12)<<"-0.2E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"0.0010 1111 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"-0.134 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<"\nPart C:"<<endl;
    cout<<left<<setw(12)<<"59999901 ="<<left<<setw(10)<<"0.1 * 2^-15"<<endl;
    cout<<left<<setw(12)<<"59999902 ="<<left<<setw(10)<<"0.1 * 2^-14"<<endl;
    cout<<left<<setw(12)<<"A66667FE ="<<left<<setw(10)<<"1.01 * 2^-15"<<endl;
}

//**************************************************************************//
// *                            PROBLEM #7                                  //
//**************************************************************************//
void p7main(){
   //Declare variables
    float input=0;
    Primes *ary;

    //Get Number to Factor
    cout<<"This program returns all prime factors of a given number "<<endl;
    cout<<"between 2 and 10000"<<endl;
    cout<<"Enter a number to factor: ";
    cin>>input;
    ary=factor(input);

    //Display the Prime Factors
    prntPrm(ary, input);
    
    //Clean up
    clean(ary); 
}
//Input an integer, return all prime factors
Primes *factor(int n){
    Primes *primes = new Primes;    //Allocate memory for primes structure
    
    //Get all prime Factors
    vector<int>pfactors;            //Store all prime factors 
    int factors;                    //Store number of factors
    
    while(n%2==0){                  //n is divisible by 2      
        pfactors.push_back(2);      //2 is a prime factor
        factors++;                  //increment number of factors
        n=n/2;                      //divide n by 2
    }
    for(int i=3; i<sqrt(n); i=i+2){ //n must be odd, loop up to sqrt(n), skip 2
        while(n%i==0){              //find factors up to n
            pfactors.push_back(i);  //i is a prime factor
            factors++;              //increment factors
            n=n/i;                  //divide n by i
      }
    }
    if (n>2){                       //n is a prime number greater than 2
        pfactors.push_back(n);      //n is a prime factor
        factors++;                  //increment factors
    }

    //Count Unique Factors
    unsigned short freq=1;          //Frequency of each unique factor
    unsigned short nPrimes=0;       //Hold number of unique primes
    for(int i=0; i<factors; i++){   //Loop through prime factors
        if(factors>1){    
            if(pfactors[i]==pfactors[i+1]){ //More than one instance of a factor
                freq++;                     //Increment factors
                if(freq==1){                //Only ++ number of unique factors once
                    nPrimes++;
                }
            }
            else{                           //++ number of unique factors
                nPrimes++;
            }
        }
        else{
            nPrimes=1;
        }
    }
    primes->nPrimes=nPrimes;            //Store number of unique prime factors
    
    //Fill Prime Array with Unique Factors and Their Powers
    primes->prime=new Prime[nPrimes];
    int index=0; //Index to store the prime factor in prime    
    int power=1; //Power of the prime factor   
    
    for(int i=0; i<factors; i++){ //Loop through prime factors
        if(factors>1){                      //If the original input is not prime    
            if(pfactors[i]==pfactors[i+1]){ //More than one instance of a prime fact
                power++;                    //Increment power
                if(power==1){               //Only store the factor once
                    primes->prime[index].prime=pfactors[i]; //Store the prime factor
                    index++;
                }
            }
            else{                           //Only one instance of a prime factor
                primes->prime[index].prime=pfactors[i]; //Store prime factor
                index++;
            }
            primes->prime[index].power=power;//Store the power of the factor
            power=1;//Reset power
        }
        else {                                  //If the original input is prime  
            primes->prime[0].prime=pfactors[0]; //Store the one prime factor
            primes->prime[0].power;             //power = 1
        }
    }
    return primes;
} 
//Output all prime factors
void prntPrm(Primes *primes, int input){
    
    cout<<"The prime factors of "<<input<<" are: "<<endl;
    for(int i=0; i<primes->nPrimes; i++){
        cout<<primes->prime[i].prime<<"^"<<primes->prime[i].power;
        if(i<primes->nPrimes-1){
            cout<<" * ";
        }
    }
}
//Deallocate Memory
void clean(Primes *prim){
    delete []prim->prime;
    delete prim;
}