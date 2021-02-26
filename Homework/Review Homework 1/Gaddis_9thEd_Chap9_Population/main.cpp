/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on February 25, 2021 7:48PM
 * Purpose: Predict the future size of a population of Zombies
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting Library
#include <cmath>
using namespace std;

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
const float PERCNV = 100.0f;

//Function Prototypes
float incrse(float, float, int);    //Calculate Zombie Increase

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int     days;       //Number of days of Zombie increase
    float   srtNum,     //Starting population 
            prcnt;      //Average Daily population increase as a percentage
    
    //Initialize Variables
    srtNum  =0;
    days    =0;
    prcnt   =0.0f;
    
    //Map Inputs to Outputs -> Process
    do{//Input Starting Population
        cout<<"This program predicts the future size";
        cout<<" of a population of Zombies."<<endl;
        cout<<"Input the starting number of Zombies";
        cout<<" (must be larger than 1): ";
        cin>>srtNum;
        if(srtNum<2){
            cout<<"Invalid Input!"<<endl;
        }
    }while(srtNum<2);
    
    do{//Input Average Daily Increase as a Percentage
        cout<<"\nInput the average daily population increase as a percentage"<<endl;
        cout<<"(must be a positive number): %";
        cin>>prcnt;
        if(prcnt<0){
            cout<<"Invalid Input!"<<endl;
        }
    }while(prcnt<0);
    
    do{//Input Days of Population Increase
        cout<<"\nInput the number of days the Zombies multiply ";
        cout<<"(must be larger than 1): ";
        cin>>days;
        if(days<2){
            cout<<"Invalid Input!"<<endl;
        }
    }while(days<2);

    //Display Inputs/Outputs
    cout<<"The Zombie population in "<<days<<" days will be: ";
    cout<<incrse(srtNum,prcnt,days);
    
    //Exit the Program - Cleanup
    return 0;
}

//Function Definitions

//Calculate Population Increase
float incrse(float srtNum, float prcnt, int days){
    float temp=1;
    prcnt/=PERCNV;
    for(int x=0; x<days; x++){
        temp=srtNum*prcnt;
        srtNum+=temp;
    }
    
    //Round up to nearest whole number
    srtNum=ceil(srtNum);
    return srtNum;
}