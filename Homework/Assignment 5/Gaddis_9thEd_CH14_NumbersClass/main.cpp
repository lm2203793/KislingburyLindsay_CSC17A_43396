/* 
 * File:   Numbers.h
 * Author: Lindsay Kislingbury
 * Purpose: Design a class Numbers that can be used to translate 
 * whole dollar amounts 
 * Created on May 23, 2021, 6:33 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;
//User Libraries
#include "Numbers.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n;      //Hold amount input
    bool error; //Input Validation Flag
    char cont;  //Continue Menu Flag
    
    do{
        //Get amount to convert
        do{
            error=false;
            cout<<"Enter a whole dollar amount 0 to 9999: $";
            cin>>n;
            if(n<0||n>9999||!cin||cin.fail()){
                cin.clear();
                cin.ignore();
                error=true;
                cout<<"Invalid Amount!"<<endl;
            }
        }while(error);
        //Create Numbers object
        Numbers num(n);
        //Translate to English
        num.convert();
        //Display Translated Amount
        num.print();
        //Ask to continue
        cout<<"\nEnter y to convert another amount or any key to exit: ";
        cin>>cont;
    }while(cont=='y');
    return 0;
}

