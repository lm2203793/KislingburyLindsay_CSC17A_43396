/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 3, 2021, 9:06PM
 * Purpose:  Fahrenheit to Celsius Conversion and Temperature Table
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
float convFtoC(float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
  
    //Declare Variables
    float frnht;
    
    //Initialize Variables
    frnht=0;
    
    //Map Inputs to Outputs -> Process
    cout<<"This program converts Fahrenheit to Celsius."<<endl;
    cout<<"Enter the temperature in Fahrenheit: ";
    cin>>frnht;
    
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(0);
    cout<<frnht<<" degrees F = "<<convFtoC(frnht)<<" degrees C"<<endl;
    cout<<"\n\tTemperature Table:"<<endl;
    for(int x=0; x<20; x++){
        cout<<setw(3)<<x<<" degrees F = "<<setw(3)<<convFtoC(x);
        cout<<" degrees C"<<endl;
    }
    
    //Exit the Program - Cleanup
    return 0;
}

//Celsius to Fahrenheit Conversion Function
float convFtoC (float frnht){
    float cls=0;
    cls=(frnht-32)/1.8000;
    return cls;
}