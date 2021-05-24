/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on May 22,2021 at 10:08PM
 * Purpose:  Write a class named RetailItem
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "RetailItem.h"
using namespace std;
//User Libraries


//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    RetailItem *inv;    //pointer to array of inventory items
    int invSize;        //size of inventory
    string desc;        //hold description input
    int units;          //hold # of units input
    float price;        //hold price input
    bool error=false;   //flag for input validation
    int total=0;          //total units on hand
    
    //Print welcome message
    cout<<"Welcome to inventory creator!"<<endl;
    
    //Get # of items in inventory
    do{
        error=false;
        cout<<"Enter the number of SKUs in inventory: ";
        cin>>invSize;
        if(!cin||cin.fail()){
            cin.clear();
            cin.ignore();
            error=true;
            cout<<"Error! enter a numeric value"<<endl;
        }
    }while(error);
    
    //Allocate memory for array of inventory items
    inv=new RetailItem[invSize];
    
    //Get inventory info
    for(int i=0; i<invSize; i++){
        cout<<"+-----------------------------+"<<endl;
        cout<<"SKU # "<<i+1<<":"<<endl;
        cout<<"Enter the item name: ";
        cin>>desc;
        cin.clear();
        inv[i].setDesc(desc); //Set description
        do{//Input Validation
            error=false;
            cout<<"Enter the # of units on hand: ";
            cin>>units;
            if(!cin||cin.fail()){
                error=true;
                cin.clear();
                cin.ignore();
                cout<<"Error! enter a numeric value"<<endl;
            }
        }while(error);
        cin.clear(); //Clear buffer
        inv[i].setUnts(units);//Set # of units
        
        do{
            error=false;
            cout<<"Enter the price: $";
            cin>>price;
            if(!cin||cin.fail()){
                error=true;
                cin.clear();
                cin.ignore();
                cout<<"Error! enter a numeric value"<<endl;
            }
        }while(error);
        cin.clear(); //Clear buffer
        inv[i].setPrc(price); //Set price of item
    }
    
    //Print Inventory
    cout<<"\nCURRENT INVENTORY:"<<endl;
    for(int i=0; i<invSize; i++){
        cout<<"Item #"<<i+1<<": ";
        cout<<inv[i].getDesc()<<endl;
        cout<<right<<setw(15)<<inv[i].getUnts()<<" units"<<endl;
        cout<<right<<setw(15)<<"$"<<inv[i].getPrc()<<endl;
    }
    
    //Calculate total units on hand
    for(int i=0; i<invSize; i++){
        total+=inv[i].getUnts();
    }
    
    //Print total # of units on hand
    cout<<"\nTotal # of units on hand: "<<total<<endl;
    
    //Exit
    return 0;
}

