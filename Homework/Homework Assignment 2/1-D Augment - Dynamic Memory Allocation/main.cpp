/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 27, 2021 3:00PM
 * Purpose: Augment a Dynamic Array
 */

//Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int *getData(int &);            //Read the array
int *augment(const int *,int);  //Augment and copy the original array
void prntAry(const int *,int);  //Print the array

int main(){
    
    //Declare Variables
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
	
	//Print Augmented Array
    prntAry(augment(ary, arySize), arySize+1);
    
    //Delete allocated memory
    delete []ary;
    
	return 0;
}

//Function Definitions

//Read the array
//Return the array size and the array from the inputs
int *getData(int &arySize){
    int *temp = new int[arySize];
    //Fill the array with specified number of values
    for(int i=0; i<arySize; i++){
        cin>>temp[i];
    }
    
    return temp;
}            

//Augment and copy the original array
int *augment(const int *ary, int arySize){
    //Copy the array
    int *temp = new int[arySize+1];
    //Fill with passed array
    temp[0]=0;
    for(int i=1;i<=arySize;i++){
        temp[i]=ary[i-1];
    }
    
    return temp;
}  

//Print the array
void prntAry(const int *ary, int arySize){
    for(int i=0; i<arySize-1; i++){
        cout<<ary[i]<<" ";
    }
    cout<<ary[arySize-1];
}       