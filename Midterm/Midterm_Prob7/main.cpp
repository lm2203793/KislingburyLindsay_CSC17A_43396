/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 25, 2021 6:12PM
 * Purpose:  Midterm Problem #7
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
struct Prime{
    unsigned short prime;
    unsigned char power;
};

struct Primes{
    unsigned char nPrimes;
    Prime *prime;
};

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Primes *factor(int);        //Input an integer, return all prime factors
void prntPrm(Primes *);     //Output all prime factors
void fact(int);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float input;
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout<<"This program returns all prime factors of a given number "<<endl;
    cout<<"between 2 and 10000"<<endl;
    cout<<"Enter a number to factor: ";
    cin>>input;
    //Display the Inputs/Outputs
    fact(input);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
//Input an integer, return all prime factors
void fact (int input){
    int n,i;
    cin>>n;
    int factors=1,exponen=0;//exponent stores power of current prime
    while(n%2==0)//a separate check for 2       {
        exponen++;
        n=n/2;
    }
    factors= factors*(exponen+1);
    exponen=0;
    int original_n=n;
    for(i=3;n>1 && i<=sqrt(original_n);i+=2)//Checking for every prime number
    {
        exponen=0;
        while(n%i==0)
        {
            exponen++;
            n=n/i;
        }
        factors= factors*(exponen+1);
    }
    cout<< factors<< endl;
    }
    
    

}

//Output all prime factors
void prntPrm(Primes *){}     