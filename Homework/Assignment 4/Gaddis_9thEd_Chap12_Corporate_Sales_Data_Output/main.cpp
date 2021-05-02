/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 23, 2021 11:29AM
    * Purpose: Corporate Sales Data Output
 */

//Libraries
#include <iostream>
#include <fstream>
#include "DivSls.h"
using namespace std;

//Function Prototypes
void input(unsigned short &);   //Write Divison Data to File
void read(int);                 //Display data stored in File
    
int main(int argc, char** argv) {
    //Declare variables
    unsigned short numDivs;    //Number of Divisions   

    //Write Division Data to File
    input(numDivs);

    //Display Data Stored in the File
    read(numDivs);

    //Exit
    return 0;
}

//Function Definitions
//Write Divison Data to File
void input(unsigned short &numDivs){
    DivSls temp;    //Hold Data for each division
    char again;     //User choice to add another division
    fstream saleDat("DivisionSales.dat", ios::out | ios::binary);
    //Get Sales Data
    do{
        //cin.ignore();                   
        //Get Division Name
        cout<<"Enter The Name Of The Division: ";
        cin>>temp.name;
        cin.clear();                    //Clear the buffer
        for(int j=0; j<4; j++){         //Loop for each quarter 
            temp.sales[j].qtr=j;
            //Get The Quarters Sales 
            do{                        
                cin.clear();            //Clear Buffer
                cin.ignore();
                cout<<"Enter Quarter "<<j+1<<" Sales: $";
                cin>>temp.sales[j].amnt;
                if(cin.fail()||!cin||temp.sales[j].amnt<0){//Input Validation
                    cout<<"Invalid Input! Sales must be a positive value"<<endl;
                }
            }while(cin.fail()||!cin||temp.sales[j].amnt<0);
        }
        
        //Write Division Data to File
        saleDat.write(reinterpret_cast<char *>(&temp), sizeof(temp));
        numDivs++;
        //Ask if user wants to enter another division
        cout<<"\nEnter Another Division? y or n :";
        cin>>again;
    }while(again=='y'||again=='Y');
    
    //Close the File
    saleDat.close();
}
//Display data stored in File
void read(int numDivs){
    DivSls record;
    fstream saleDat("DivisionSales.dat", ios::in | ios::binary);
    cout<<"\nNow Reading...\n"<<endl;
    //Read First Record
    saleDat.read(reinterpret_cast<char *>(&record), sizeof(record));
    
    //Continue Reading Records Until End of File
    for(int i=0; i<numDivs; i++){
        cout<<"Division: "<<record.name<<endl;
        for(int i=0; i<4; i++){
            cout<<"Qtr "<<record.sales[i].qtr<<" ";
            cout<<"sales: "<<record.sales[i].amnt<<endl; 
        }
        saleDat.read(reinterpret_cast<char *>(&record), sizeof(record));
        cout<<endl;
    }
    
    saleDat.close();
}



