/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 4, 2021, 6:42 PM
 * Purpose:  Weather Data Table
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>   //Stream Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void wEntry(char[][30]);                       //Fill Array w/ weather Data
void maxMnth(int,int,int,int,int&,int&,int&);  //Find highest month

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int DAYS=30;             //Number of days per month (assume 30/mo)
    const int MNTHS=3;             //Number of months for weather data
    char wthTble[MNTHS][DAYS];     //Array of weather data
    int rainy, cloudy, sunny;      //Total Count for each condition
    int trainy, tcloudy, tsunny;   //Accumulators for each month
    int maxR, maxC, maxS;          //highest month for each condition 
    int cmaxC, cmaxS, cmaxR; //Hold the current max for swap in place    
    string mNames []={"June","July","August"}; //Names of the months
    
    //Initialize Variables
    rainy=0;
    sunny=0;
    cloudy=0;
    maxR=0;
    maxS=0;
    maxC=0;  

    //Fill Array 
    wEntry(wthTble);
    //Display Table Heading
    cout<<"\t\tWeather Data Table\n"<<endl;
    //Count totals for each condition
    for (int mnth=0; mnth<3; mnth++){
        //Set Accumulators to zero
        trainy=0; 
        tcloudy=0;
        tsunny=0;
        //Count conditions for each month
        for(int day=0; day<30; day++){
            if (wthTble[mnth][day]=='R'){
                trainy++;
            }
            if(wthTble[mnth][day]=='C'){
                tcloudy++;
            }
            if (wthTble[mnth][day]=='S'){
                tsunny++;
            }
        }
        //Add monthly totals to overall total
        rainy+=trainy;
        cloudy+=tcloudy;
        sunny+=tsunny;     
        
        //Display total days for the month
        cout<<mNames[mnth]<<" Conditions:"<<endl;
        cout<<"Rainy Days:"<<"\tCloudy Days:"<<"\tSunny Days:"<<endl;
        cout<<setw(3)<<"\t"<<trainy<<"\t\t"<<tcloudy<<"\t\t"<<tsunny<<endl;
        
        //Determine Highest Month for each condition
        if(trainy>cmaxR){ 
            maxR=mnth;
            cmaxR=trainy;
        }
        if(tcloudy>cmaxC){
            maxC=mnth;
            cmaxC=tcloudy;
        }        
        if(tsunny>cmaxS){
            maxS=mnth;
            cmaxS=tsunny;
        }
    }

    //Display Overall Totals 
    cout<<setw(17)<<left<<"\nTotal Rainy Days"<<setw(3)<<" = "<<rainy<<endl;
    cout<<setw(17)<<"Total Sunny Days"<<setw(3)<<" = "<<sunny<<endl;
    cout<<setw(17)<<"Total Cloudy Days"<<setw(3)<<" = "<<cloudy<<endl;
    cout<<setw(17)<<"Rainiest Month"<<setw(3)<<" = "<<mNames[maxR]<<endl;
    cout<<setw(17)<<"Cloudiest Month"<<setw(3)<<" = "<<mNames[maxC]<<endl;
    cout<<setw(17)<<"Sunniest Month"<<setw(3)<<" = "<<mNames[maxS]<<endl;

    //Exit the Program - Cleanup
    return 0;
}

//Function Definitions
//Read Weather Data into the array
void wEntry(char wthTble[][30]){
    //Open Filestream 
    ifstream wData;       
    
    //Open wData text file and fill wthTable array with weather data
    wData.open("wData.txt");            
    for (int mnth=0; mnth<3; mnth++){
        for(int day=0; day<30; day++){
            wData>>wthTble[mnth][day];
        }
    }
    //Close Filestream
    wData.close();
}
