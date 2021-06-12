/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: CIS 17a Final
 * Created on June 11, 2021, 8:34 PM
 */

//System Libraries
#include <cstdlib> //C Standard Library
#include <iostream>//I/O Stream Library
#include <fstream> //File Stream Library
#include <iomanip> //Formatting Library
//User Libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"
using namespace std;

//Function Prototypes
void prob1(); //Problem 1: Random Sequence
void prob2(); //Problem 2: All Kinds of Sorting
void prob3(); //Problem 3: Spreadsheet Stuff
void prob4(); //Problem 4: Savings Account 
void prob5(); //Problem 5: Employee Class
void prob6(); //Problem 6: Conversions

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;    //Menu choice
    
    do{
        //Main Menu
        cout<<"Linday Kislingbury CIS 17a Final"<<endl;
        cout<<"1: Random Sequence\n2: All Kinds of Sorting\n3: Spreadsheet Stuff\n"
            <<"4: Savings Account\n5: Employee Class\n6: Conversions"<<endl;
        cout<<"Q: Quit"<<endl;
        cout<<"Enter the Problem #: ";
        cin>>choice;
        switch(choice){
            case '1':
                prob1();
                break;
            case '2':
                prob2();
                break;
            case '3':
                prob3();
                break;
            case '4':
                prob4();
                break;
            case '5':
                prob5();
                break;
            case '6':
                prob6();
                break;
        }
    }while(choice!='Q');
    return 0;
}

//Function Definitions
//Problem 1: Random Sequence
void prob1(){
    cout<<"The start of Problem 1, random sequence\n"<<endl;
    //Driver program to return a random sequence
    char n=5;  
    char rndseq[]={18,33,56,79,124};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++){
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++){
            cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    cout<<endl;
}

//Problem 2: All Kinds of Sorting
void prob2(){
    cout<<"\nThe start of Problem 2, the sorting problem\n"<<endl;
    Prob2Sort <char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){
        cout<<*ch2;
        ch2++;
    }
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
                cout<<zc[i*16+j];
        }
    }
    delete []zc;
    cout<<endl<<endl;
}

//Problem 3: Spreadsheet Stuff
void prob3(){
    cout<<"The start of Problem 3, spreadsheet stuff\n"<<endl;
    int rows=5;
    int cols=6;
    
    char fileNm[]="Problem3.txt";
    Prob3TableInherited<int> tab(fileNm,rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Problem 4: Savings Account 
void prob4(){
    cout<<"The start of Problem 4, savings account\n"<<endl;
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
        cout<<"Enter y to enter another transaction or any other key to"
                <<" finish"<<endl;
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
    cout<<endl;
    cout<<"Balance after "<<years<<" years given "<<fixed<<setprecision(2)<<rate
            <<"% SIMPLE interest = "<<acc.Total(rate,years)<<endl;
    cout<<"Balance after "<<years<<" years given "<<fixed<<setprecision(2)<<rate
            <<"% COMPOUND (recursive) interest = "
            <<acc.TotalRecursive(rate,years)<<endl;
    cout<<"\n\n";
}

//Problem 5: Employee Class
void prob5(){
    cout<<"The start of Problem 5, employee class\n"<<endl;
    //Declare Variables
    char cName[20]; //Employee name
    char cTitle[20];//Employee title
    float rate;     //Hourly rate
    bool tryAgn;    //Input Validation
    string name;    //Hold name for input validation
    string title;   //Hold title for input validation
    char choice;    //Choice to repeat
    bool repeat;    //true=repeat
    do{
        cin.ignore();
        cin.clear();
        cout<<"Employee Pay Calculator"<<endl;
        //Input Name, Job Title and Hourly Rate
        cout<<"Input Name: ";
        getline(cin, name);
        while(name.length()>20){ //Input Validation
            cout<<"Name too long! Must be 20 characters or less"<<endl;
            getline(cin, name);
        }
        for(int i=0; i<name.length(); i++){ //Convert to c string
            cName[i]=name[i];
        }
        cout<<"Input Job Title: ";
        getline(cin, title);
        while(title.length()>20){ //Input Validation
            cout<<"Title too long! Must be 20 characters or less"<<endl;
            getline(cin, title);
        }
        for(int i=0; i<title.length(); i++){ //Convert to c string
            cTitle[i]=title[i];
        }
        cout<<"Input Hourly Rate: ";
        cin>>rate;

        //Create Employee Object
        Employee emp(cName,cTitle,rate);
        //Input Hours Worked
        int hours;
        cout<<"Input Hours Worked: ";
        cin>>hours;
        while(tryAgn){ //Input Validation with Exception
            try{
                emp.setHoursWorked(hours);
                tryAgn=false;
            }
            catch(Employee::InvalidHours h){
                cout<<"Unacceptable Hours Worked!"<<endl;
                cout<<"Input Hours Worked: ";
                cin>>hours;
            }
        }
        emp.setHoursWorked(hours);
        emp.CalculatePay(rate, hours);
        emp.toString();

        //Ask to run again
        cin.ignore();
        cin.clear();
        cout<<"\nEnter y to Calculate Another Employee or any other key to "
                <<"quit"<<endl;
        cin>>choice;
        if(choice=='y') repeat=true;
        else repeat=false;
        cin.clear();
    }while(repeat);
    cout<<"\n\n";
}

//Problem 6: Conversions
void prob6(){
    cout<<"The start of Problem 6, conversions\n"<<endl;
    
    cout<<"Handwritten Solutions Included In Final Project Folder"<<endl;
    cout<<"Part 1: Convert to Binary, Octal, and Hex"<<endl;
    cout<<left<<setw(20)<<"3.75 "<<left<<setw(10)<<"base 10 ="<<endl;
    cout<<left<<setw(20)<<"3.C "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(20)<<"11.11 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(20)<<"3.6"<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(20)<<"\n0.7 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(20)<<"0.B3333"<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(20)<<"0.1011 0011 0011"<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(20)<<"0.546314631"<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(20)<<"\n89.9 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(20)<<"0.59.E6666"<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(20)<<"1011001.11100 1100 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(20)<<"131.714631463 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<"\nPart 2: Nasa conversion"<<endl;
    cout<<left<<setw(20)<<"0.375 base 10 ="<<left<<setw(10)<<"780000FE"<<endl;
    cout<<left<<setw(20)<<"0.7 base 10 ="<<left<<setw(10)<<"59999900"<<endl;
    cout<<left<<setw(20)<<"89.9 base 10 ="<<left<<setw(10)<<"59F333F9"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"I did not complete steps 3-5. I do not remember\ncovering scaled"
        <<" binary in class. But I waited\nuntil the last minute to do this"
        <<" problem. There\nwere plenty of opportunities to ask about this\nin"
        <<" class if I had started this problem earlier"<<endl;
    cout<<endl;
}


