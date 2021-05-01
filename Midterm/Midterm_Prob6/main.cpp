/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 27 2021 5:31PM
 * Purpose:  Midterm Problem #6
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//Execution of Code Begins Here
int main(int argc, char** argv) {
    
    //Display 
    cout<<"Handwritten Solutions Included In Midterm Project Folder"<<endl;
    cout<<"Part A:"<<endl;
    cout<<left<<setw(12)<<"2.875 "<<left<<setw(10)<<"base 10 ="<<endl;
    cout<<left<<setw(12)<<"2.E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"10.111 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"2.7 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(12)<<"\n0.1796875 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(12)<<"0.2E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"0.0010 1110 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"0.134 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<"\nPart B:"<<endl;
    cout<<left<<setw(12)<<"-2.875 "<<left<<setw(10)<<"base 10 ="<<endl;
    cout<<left<<setw(12)<<"-2.E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"10.1111 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"-2.7 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(12)<<"\n0.1796875 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(12)<<"-0.2E "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(12)<<"0.0010 1111 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(12)<<"-0.134 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<"\nPart C:"<<endl;
    cout<<left<<setw(12)<<"59999901 ="<<left<<setw(10)<<"0.1 * 2^-15"<<endl;
    cout<<left<<setw(12)<<"59999902 ="<<left<<setw(10)<<"0.1 * 2^-14"<<endl;
    cout<<left<<setw(12)<<"A66667FE ="<<left<<setw(10)<<"1.01 * 2^-15"<<endl;
    //Exit stage right
    return 0;
}

//Function Implementations