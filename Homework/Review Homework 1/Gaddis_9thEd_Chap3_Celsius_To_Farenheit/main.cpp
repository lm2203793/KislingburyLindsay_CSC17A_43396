/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on February 25, 2021, 1:05PM
 * Purpose:  Celsius To Fahrenheit Conversion
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
float convCtoF(float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
  
    //Declare Variables
    float celsius;
    
    //Initialize Variables
    celsius=0;
    
    //Map Inputs to Outputs -> Process
    cout<<"This program converts Celsius to Fahrenheit."<<endl;
    cout<<"Enter the temperature in Celsius: ";
    cin>>celsius;
    
    //Display Inputs/Outputs
    cout<<celsius<<" degrees C = "<<convCtoF(celsius)<<" degrees F";
    
    //Exit the Program - Cleanup
    return 0;
}

//Celsius to Fahrenheit Conversion Function
float convCtoF (float celsius){
    float frnht=0;
    frnht=(1.8*celsius)+32;
    return frnht;
}