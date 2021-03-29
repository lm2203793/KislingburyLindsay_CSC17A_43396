/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 27, 2021 2:00PM
 * Purpose: Sum a Dynamic Array
 */

//Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int **getData(int &,int &);                 //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);   //Print the 2-D Array
void destroy(int **,int,int);               //Deallocate memory
int sum(const int * const *, int,int);      //Return the Sum

int main(){
	//Declare variables
    int aryRows,aryCols,                //Hold array size inputs
    **ary;                              //Pointer to the array                   
    
    //get rows and columns
    cin>>aryRows;
    cin>>aryCols;

    //Return the array size and the array
    ary=getData(aryRows,aryCols);

    //Print the Array
    prntDat(ary, aryRows, aryCols);
    
    //Print the Sum
    cout<<sum(ary, aryRows, aryCols);
    
    //Clean Up
    destroy(ary, aryRows, aryCols);
    
    
	return 0;
}

//Function Definitions

//Return the 2-D array and its size.
int **getData(int &aryRows, int &aryCols){
    //Create dynamic array to hold contents
    int **array=new int*[aryRows];
    //Fill array
    for(int r=0; r<aryRows; r++){
        array[r]=new int[aryCols];  //Allocate Memory for columns
        for(int c=0;c<aryCols;c++){
            cin>>array[r][c];       //Input Array data
        }
    }
    
    return array;
}                 

//Print the 2-D Array
void prntDat(const int* const *ary, int aryRows, int aryCols){
   int count=0;    //Count elements for formatting
   //Print Array with formatting
   for(int i=0; i<aryRows; i++){
       for(int j=0; j<aryCols; j++){
           count++;
           cout<<ary[i][j];
           if(count%aryCols!=0) cout<<" ";  //Print Space if not the last element of the row
       }
       cout<<endl;
   }
}   

//Deallocate memory
void destroy(int **ary, int aryRows, int aryCols){
    for(int r=0;r<aryRows;r++){
        delete []ary[r];
    }
    delete []ary;
}               

//Return the Sum
int sum(const int * const *ary, int aryRows, int aryCols){
    int sum=0;  //Hold the sum
    //Calculate sum
    for(int i=0; i<aryRows; i++){
        for(int j=0; j<aryCols; j++){
            sum+=ary[i][j];
        }
    }
    return sum;
}      