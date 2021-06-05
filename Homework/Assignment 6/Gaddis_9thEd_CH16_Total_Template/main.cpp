/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Total Template
 * Created on June 1, 2021, 3:20 PM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries
template <class T>
T total(T val, T &tot); //Sum Function

int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    char cont;
    int counter=0;
    
    cout<<"This program sums values."<<endl;
    cout<<"Run Program using ints or floats? Enter i or f: ";
    cin>>choice;
    
    if(choice=='i'){ //Int Sums
        int tot=0;
        int val;
        while(cont!='q'){  
            cout<<"\nEnter a value to add to the total"<<endl;
            cin>>val;
            cout<<tot<<" + "<<val<<" = "<<total(val, tot)<<endl;
            cout<<"Enter q to quit or any key to add to the total: ";
            cin>>cont;
        }
    }
    else if (choice=='f'){ //Float Sums
        float tot=0;
        float val;
        while(cont!='q'){    
            cout<<"\nEnter a value to add to the total"<<endl;
            cin>>val;
            cout<<fixed<<setprecision(2)<<tot<<" + "<<val<<" = "
                    <<total(val, tot)<<endl;
            cout<<"Enter q to quit or any key to add to the total: ";
            cin>>cont;
        }
    }
    
    return 0;
}
//Sum Function
template <class T>
T total(T val, T &tot){
    tot+=val;
    return tot;
}

