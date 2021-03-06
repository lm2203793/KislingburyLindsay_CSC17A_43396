/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 4, 2021, 6:42 PM
 * Purpose:  Weather Data Table
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>   //Stream Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const int MNTH=3;
    const int DAY=30;
    char wthTble[MNTH][DAY];
    char x;
    int rainy, cloudy, sunny;
    ifstream wData;
    int maxmnth;
    int curmaxC, curmaxS, curmaxR;
    
    //Initialize Variables
    rainy=0;
    sunny=0;
    cloudy=0;
    maxmnth=3;
    curmaxC=0;
    curmaxR=0;
    curmaxS=0;    
    
    //Fill Array
    cout<<"Weather Data Table."<<endl;
    wData.open("wData.txt");
    
    for (int mnth=0; mnth<3; mnth++){
        for(int day=0; day<30; day++){
            wData>>wthTble[mnth][day];
        }
    }
    
    for (int mnth=0; mnth<3; mnth++){
        cout<<endl;
        for(int day=0; day<30; day++){
            cout<<wthTble[mnth][day];
        }
    }
    
    //
    for (int mnth=0; mnth<3; mnth++){
        int temprainy, tempcloudy, tempsunny;
        temprainy=0;
        tempcloudy=0;
        tempsunny=0;
        for(int day=0; day<30; day++){
            if (wthTble[mnth][day]=='R'){
                temprainy++;
            }
            if(wthTble[mnth][day]=='C'){
                tempcloudy++;
            }
            if (wthTble[mnth][day]=='S'){
                tempsunny++;
            }
        }
        rainy+=temprainy;
        cloudy+=tempcloudy;
        sunny+=tempsunny;
        
        if(temprainy>curmaxR){
            maxmnth=mnth;
            curmaxR=temprainy;
        }
        if(tempcloudy>curmaxC){
            maxmnth=mnth;
            curmaxR=tempcloudy;
        }        
        if(temprainy>curmaxS){
            maxmnth=mnth;
            curmaxR=tempsunny;
        }
    }
    
    cout<<"\ntotal rainy days = "<<rainy<<endl;
    cout<<"total sunny days = "<<sunny<<endl;
    cout<<"total cloudy days = "<<cloudy<<endl;
    cout<<"Rainiest Month = "<<curmax[]


    
    
    
    //Display Inputs/Outputs
    
    //Exit the Program - Cleanup
    return 0;
}

