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
void input(int &);
void destroy(DivSls *);

int main(int argc, char** argv) {
    //Execution Begins here
    
    //Declare variables
    int numDivs;    //The array size
    
    //Input
    cout<<"This Program Stores Quarterly Sales Figures."<<endl;
    cout<<"Enter The Number of Divisions:"<<endl;
    cin>>numDivs;
    input(numDivs);
    
    //Exit
    return 0;
}

//Function Definitions
void input(int &numDivs){
    DivSls *temp = new DivSls[numDivs];
    //Fill the array with specified number of values
    for(int i=0; i<numDivs; i++){
        cin.ignore();                   //Clear the buffer
        cout<<"Enter The Name Of The Division: ";
        getline(cin, temp[i].name);
        for(int i=0; i<4; i++){
            cout<<"Enter The Quarter: ";
            cin>>temp[i].qrtr;
            cout<<"Enter the Quarter's Sales: ";
            cin>>temp[i].sales;
        }
        cout<<endl;
    }
    
    //Write the array to file
    fstream saleDat;
    saleDat.open("DivisionSales.txt", ios::out | ios::binary);
    saleDat.write(reinterpret_cast<char *>(temp), sizeof(temp));
    saleDat.close();

    //Deallocate Memory
    delete temp; 
}





