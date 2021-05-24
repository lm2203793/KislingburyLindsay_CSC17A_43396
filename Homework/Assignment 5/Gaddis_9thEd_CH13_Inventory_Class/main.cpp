/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Design an Inventory class that can hold information and calculate 
 *          data for items in a retail stores inventory
 * Created on May 22, 2021, 10:51 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Inventory.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n;
    int qty;
    float cost;
    char choice;
    int num;
    bool choosing;

    //Get # of items
    cout<<"Welcome to Inventory Creator!!"<<endl;
    cout<<"How many items? ";
    cin>>n;
    Inventory items[n];
    //Fill Inventory
    for(int i=0; i<n; i++){
        cout<<"Item #"<<i+1<<": "<<endl;
        items[i].setNum(i+1);
        cout<<"Enter the Item's Cost: $";
        cin>>cost;
        items[i].setCost(cost);
        cout<<"Enter the Qty: ";
        cin>>qty;
        items[i].setQty(qty);
        items[i].setTot();
    }
    
    //Display Inventory
    for(int i=0; i<n; i++){
        cout<<"Item #:"<<items[i].getNum()<<endl;
        cout<<"Qty: ";
        cout<<left<<setw(7)<<items[i].getQty();
        cout<<" Cost: $";
        cout<<left<<setw(10)<<fixed<<setprecision(2)<<items[i].getCost();
        cout<<"Total Cost: $";
        cout<<left<<setw(10)<<fixed<<items[i].getTot()<<endl;
        cout<<"+-----------------------------------------+"<<endl;
    }
    
    //Add/Edit item
    do{
        cout<<"Would you like to edit an item? y/n"<<endl;
        cin>>choice;
        if(choice=='y'){
            cout<<"Enter the item #: ";
            cin>>num;
            cout<<"Enter the qty: ";
            cin>>qty;
            items[num-1].setQty(qty);
            cout<<"Enter the cost: $";
            cin>>cost;
            items[num-1].setCost(cost);
            cout<<"New Inventory:"<<endl;
            //Display Inventory
            for(int i=0; i<n; i++){
                cout<<"Item #:"<<items[i].getNum()<<endl;
                cout<<"Qty: ";
                cout<<left<<setw(7)<<items[i].getQty();
                cout<<" Cost: $";
                cout<<left<<setw(10)<<fixed<<setprecision(2)<<items[i].getCost();
                cout<<"Total Cost: $";
                cout<<left<<setw(10)<<fixed<<items[i].getTot()<<endl;
                cout<<"+-----------------------------------------------+"<<endl;
            }
        }
        else if(choice=='n'){
            cout<<"Ending Program";
            choosing=false;
        }
        else{
            cout<<"Invalid!"<<endl;
            choosing=true;
        }
    }while(choosing);

    //Exit
    return 0;
}


