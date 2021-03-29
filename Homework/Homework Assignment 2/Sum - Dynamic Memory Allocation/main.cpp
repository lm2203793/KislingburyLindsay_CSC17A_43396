/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 27, 2021 1:00PM
 * Purpose: Reverse a dynamic array
 */

//Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int *getData(int &);            //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array


int main(){
    
	//Declare variables
    int arySize;                //The array size
    int *ary;                   //Pointer to the array
    
    //Input the size of the array
    cin>>arySize;
    
    //Return the array size and the array
    ary=getData(arySize);
	
	//Print the Originial array
	prntAry(ary, arySize);
	
	//Print newline
	cout<<endl;
	
	//Print Sums array
	prntAry(sumAry(ary, arySize), arySize);
	
	//Delete allocated memory
    delete []ary;
	
	return 0;
}

//Function Definitions

//Return the array size and the array from the inputs
int *getData(int &arySize){
    int *temp = new int[arySize];
    
    //Fill the array with specified number of values
    for(int i=0; i<arySize; i++){
        cin>>temp[i];
    }
    
    return temp;
}           

//Return the array with successive sums
int *sumAry(const int *ary, int arySize){
    //Copy the array
    int *orig = new int[arySize];
    //Fill with passed array
    orig[0]=0;
    for(int i=0;i<arySize;i++){
        orig[i+1]=ary[i];
    }
    
    //Copy the array
    int *sums = new int[arySize];
    sums[0]=0;                  //Set intital values 
    sums[1]=orig[0]+orig[1];
    
    //Get Successive sums
    for(int i=0; i<arySize; i++){
        sums[i]=orig[i+1]+sums[i-1];
        
    }
    
    return sums;
}   

//Print the array
void prntAry(const int *ary, int arySize){
    for(int i=0; i<arySize-1; i++){
        cout<<ary[i]<<" ";
    }
    cout<<ary[arySize-1];
}     