/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on February 25, 2021, 02:24 PM
 * Purpose:  Convert US dollars to Yen and Euro
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
float cnvrt(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const float YN2DLR=106.235;        //Conversion factor: Yen per Dollar
                                       //Exchange Rate Current on 02/25/21
    const float ER2DLR=0.8236;         //Conversion factor: Euro per Dollar
                                       //Exchange Rate Current on 02/25/21
    float usd;                         //Amount to be converted in USD
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    cout<<"This program converts USD to EUR and JPN"<<endl;
    cout<<"Using the exchange rates current on 02/25/2021."<<endl;
    cout<<"\nEnter an amount to convert in USD: $";
    cin>>usd;
    
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2);
    cout<<"$"<<usd<<" USD = $"<<cnvrt(usd,ER2DLR); //Convert to Euros
    cout<<" Euros"<<endl;
    
    cout<<"$"<<usd<<" USD = $"<<cnvrt(usd,YN2DLR); //Convert to Yen
    cout<<" Yen"<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}

//Function Definitions

//Conversion
float cnvrt (float usd, float cnvfctr){
    usd*=cnvfctr;
    return usd;
}