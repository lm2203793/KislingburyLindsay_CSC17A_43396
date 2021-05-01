/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 25, 2021 6:12PM
 * Purpose:  Midterm Problem #7
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Library
#include <vector>    //Vector Library
#include "Prime.h"   //Prime Structure
#include "Primes.h"  //Primes Structure
using namespace std;


//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Primes *factor(int);             //Input an integer, return all prime factors
void prntPrm(Primes *, int);     //Output all prime factors
void clean(Primes *);            //Deallocate memory 
//Execution of Code Begins Here
int main(int argc, char** argv) {

    //Declare variables
    float input=0;
    Primes *ary;

    //Get Number to Factor
    cout<<"This program returns all prime factors of a given number "<<endl;
    cout<<"between 2 and 10000"<<endl;
    cout<<"Enter a number to factor: ";
    cin>>input;
    ary=factor(input);

    //Display the Prime Factors
    prntPrm(ary, input);
    
    //Clean up
    clean(ary);
    
    //Exit
    return 0;
}

//Function Implementations
//Input an integer, return all prime factors
Primes *factor(int n){
    Primes *primes = new Primes;    //Allocate memory for primes structure
    
    //Get all prime Factors
    vector<int>pfactors;            //Store all prime factors 
    int factors;                    //Store number of factors
    
    while(n%2==0){                  //n is divisible by 2      
        pfactors.push_back(2);      //2 is a prime factor
        factors++;                  //increment number of factors
        n=n/2;                      //divide n by 2
    }
    for(int i=3; i<sqrt(n); i=i+2){ //n must be odd, loop up to sqrt(n), skip 2
        while(n%i==0){              //find factors up to n
            pfactors.push_back(i);  //i is a prime factor
            factors++;              //increment factors
            n=n/i;                  //divide n by i
      }
    }
    if (n>2){                       //n is a prime number greater than 2
        pfactors.push_back(n);      //n is a prime factor
        factors++;                  //increment factors
    }

    //Count Unique Factors
    unsigned short freq=1;          //Frequency of each unique factor
    unsigned short nPrimes=0;       //Hold number of unique primes
    for(int i=0; i<factors; i++){   //Loop through prime factors
        if(factors>1){    
            if(pfactors[i]==pfactors[i+1]){ //More than one instance of a factor
                freq++;                     //Increment factors
                if(freq==1){                //Only ++ number of unique factors once
                    nPrimes++;
                }
            }
            else{                           //++ number of unique factors
                nPrimes++;
            }
        }
        else{
            nPrimes=1;
        }
    }
    primes->nPrimes=nPrimes;            //Store number of unique prime factors
    
    //Fill Prime Array with Unique Factors and Their Powers
    primes->prime=new Prime[nPrimes];
    int index=0; //Index to store the prime factor in prime    
    int power=1; //Power of the prime factor   
    
    for(int i=0; i<factors; i++){ //Loop through prime factors
        if(factors>1){                      //If the original input is not prime    
            if(pfactors[i]==pfactors[i+1]){ //More than one instance of a prime fact
                power++;                    //Increment power
                if(power==1){               //Only store the factor once
                    primes->prime[index].prime=pfactors[i]; //Store the prime factor
                    index++;
                }
            }
            else{                           //Only one instance of a prime factor
                primes->prime[index].prime=pfactors[i]; //Store prime factor
                index++;
            }
            primes->prime[index].power=power;//Store the power of the factor
            power=1;//Reset power
        }
        else {                                  //If the original input is prime  
            primes->prime[0].prime=pfactors[0]; //Store the one prime factor
            primes->prime[0].power;             //power = 1
        }
    }
    return primes;
} 

//Output all prime factors
void prntPrm(Primes *primes, int input){
    
    cout<<"The prime factors of "<<input<<" are: "<<endl;
    for(int i=0; i<primes->nPrimes; i++){
        cout<<primes->prime[i].prime<<"^"<<primes->prime[i].power;
        if(i<primes->nPrimes-1){
            cout<<" * ";
        }
    }
}

//Deallocate Memory
void clean(Primes *prim){
    delete []prim->prime;
    delete prim;
}