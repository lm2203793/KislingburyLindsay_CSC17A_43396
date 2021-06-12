/* 
 * File:   Prob1Random.h
 * Author: Lindsay Kislingbury
 * Purpose: Prob1Random Class Member Function Definitions
 * Created on June 8, 2021, 2:56 PM
 */    
#include "Prob1Random.h"
#include <cstdlib>

//Constructor
Prob1Random::Prob1Random(const char n, const char *rndseq){
    numRand=0;     
    nset=n;  
    //Allocate memory for freq and set
    freq=new int[n];
    set=new char[n];
    //Fill set with random sequence
    for(int i=0; i<n; i++){
        set[i]=rndseq[i];
    }
}   

//Destructor
Prob1Random::~Prob1Random(void){
    delete []set;
    delete []freq;
}                       

//Returns a random number from the set
char Prob1Random::randFromSet(void){
    //Increment number of times called
    numRand++;
    //Declare and initialize random index
    int rIndex=rand()%nset;
    //Increment frequency at random index
    freq[rIndex]++;
    //Return random number from set
    return set[rIndex]; 
}                   

//Returns the frequency histogram
int* Prob1Random::getFreq(void) const{
    return freq;
}                 

//Returns the set used
char* Prob1Random::getSet(void) const{
    return set;
}                 

//Gets the number of times randFromSet has been called
int Prob1Random::getNumRand(void) const{
    return numRand;
}              