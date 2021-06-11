/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Problem #1 Random Sequence
 *          Create a class that returns a random number from the following set,
 *          {18,33,56,78,124}.  Loop 100,000 times with this procedure and 
 *          print the frequency of each of the 5 numbers obtained.
 * Created on June 8, 2021, 2:56 PM
 */
//System Libraries
#include <cstdlib> //C Standard Library
#include <iostream>//I/O Stream Library
//User Libraries
#include "Prob1Random.h"
using namespace std;


//Execution Begins Here!
int main(int argc, char** argv) {
    //Driver program to return a random sequence
	char n=5;  
	char rndseq[]={18,33,56,79,124};
	int ntimes=100000;
	Prob1Random a(n,rndseq);
	for(int i=1;i<=ntimes;i++){
		a.randFromSet();
	}
	int *x=a.getFreq();
	char *y=a.getSet();
	for(int i=0;i<n;i++){
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    return 0;
}

