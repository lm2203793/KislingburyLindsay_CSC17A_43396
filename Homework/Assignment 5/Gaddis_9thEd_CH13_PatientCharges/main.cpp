/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on May 22, 2021 at 9:04PM
 * Purpose:  Write a class named Patient 
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries
#include "Patient.h"
#include "Procedure.h"

//Execution Begins Here
int main(int argc, char** argv) {
    float total;  //Hold total charges
    
    //Create an instance of a Patient, initialized with sample data
    Patient sample("Michael","Gary","Scott","1725 Slough Ave","Scranton","18506");
    
    //Create three instances of the Procedure class, intialized with sample data
    Procedure one("Physical Exam","05/22/2021","Dr. Irvine",250.00);
    Procedure two("X-Ray","05/22/2021","Dr. Jamison",500.00);
    Procedure three("Blood test","05/22/2021","Dr. Smith",200.00);
    
    //Calculate total charges
    total=one.getChgs()+two.getChgs()+three.getChgs();
    
    //Display the patient's info
    cout<<"Patient:"<<endl;
    cout<<sample.getName()<<endl;
    cout<<sample.getAdd()<<endl;
    cout<<"+----------------------------+"<<endl;
    //Display Procedure Info
    //Procedure 1
    cout<<"Procedure #1:"<<endl;
    cout<<one.getPrc()<<endl;
    cout<<one.getDt()<<endl;
    cout<<one.getDr()<<endl;
    cout<<fixed<<setprecision(2)<<"$"<<one.getChgs()<<endl<<endl;
    //Procedure 2
    cout<<"Procedure #2:"<<endl;
    cout<<two.getPrc()<<endl;
    cout<<two.getDt()<<endl;
    cout<<two.getDr()<<endl;
    cout<<fixed<<setprecision(2)<<"$"<<two.getChgs()<<endl<<endl;
    //Procedure 3
    cout<<"Procedure #3:"<<endl;
    cout<<three.getPrc()<<endl;
    cout<<three.getDt()<<endl;
    cout<<three.getDr()<<endl;
    cout<<fixed<<setprecision(2)<<"$"<<three.getChgs()<<endl<<endl;
    //Display total charges
    cout<<"Total Charges: $"<<total<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}