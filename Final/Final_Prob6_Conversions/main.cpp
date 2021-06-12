/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Conversions
 * Created on June 11, 2021, 8:39 PM
 */

//System Libraries
#include <cstdlib> //C Standard Library
#include <iomanip> //Formating Library
#include <iostream>//I/O Library
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Display 
    cout<<"Handwritten Solutions Included In Final Project Folder"<<endl;
    cout<<"Part 1: Convert to Binary, Octal, and Hex"<<endl;
    cout<<left<<setw(20)<<"3.75 "<<left<<setw(10)<<"base 10 ="<<endl;
    cout<<left<<setw(20)<<"3.C "<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(20)<<"11.11 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(20)<<"3.6"<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(20)<<"\n0.7 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(20)<<"0.B3333"<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(20)<<"0.1011 0011 0011"<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(20)<<"0.546314631"<<left<<setw(10)<<"base 8"<<endl;
    cout<<left<<setw(20)<<"\n89.9 "<<left<<setw(10)<<" base 10 ="<<endl;
    cout<<left<<setw(20)<<"0.59.E6666"<<left<<setw(10)<<"base 16"<<endl;
    cout<<left<<setw(20)<<"1011001.11100 1100 "<<left<<setw(10)<<"base 2"<<endl;
    cout<<left<<setw(20)<<"131.714631463 "<<left<<setw(10)<<"base 8"<<endl;
    cout<<"\nPart 2: Nasa conversion"<<endl;
    cout<<left<<setw(20)<<"0.375 base 10 ="<<left<<setw(10)<<"780000FE"<<endl;
    cout<<left<<setw(20)<<"0.7 base 10 ="<<left<<setw(10)<<"59999900"<<endl;
    cout<<left<<setw(20)<<"89.9 base 10 ="<<left<<setw(10)<<"59F333F9"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"I did not complete steps 3-5. I do not remember\ncovering scaled"
        <<" binary in class. But I waited\nuntil the last minute to do this"
        <<" problem. There\nwere plenty of opportunities to ask about this\nin"
        <<" class if I had started this problem earlier"<<endl;
    //Exit 
    return 0;
}

