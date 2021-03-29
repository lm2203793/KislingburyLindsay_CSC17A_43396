/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 27, 2021 3:31PM
 * Purpose: Augment a 2D Dynamic Array
 */

//Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
	//Declare variables
    int aryRows,aryCols,                //Hold array size inputs
    **ary;                              //Pointer to the array      
    
    //get rows and columns
    cin>>aryRows;
    cin>>aryCols;

    //Return the array size and the array
    ary=getData(aryRows,aryCols);
    
    //Print the Matrix
    printDat(ary, aryRows, aryCols);
    
    //Print New Line
    cout<<endl;
    
    //Print Augmented Matrix
    printDat(augment(ary,aryRows,aryCols), aryRows+1, aryCols+1);
    
    //Clean Up
    destroy(ary, aryRows);

    
	return 0;
}

//Function Definitions

//Get the Matrix Data
int **getData(int &aryRows, int &aryCols){
    //Create dynamic array to hold contents
    int **array=new int*[aryRows];
    //Fill array
    for(int r=0; r<aryRows; r++){   //Loop for each row 
        array[r]=new int[aryCols];  //Allocate memory for columns
        for(int c=0;c<aryCols;c++){ //Loop for each column
            cin>>array[r][c];
        }
    }
    
    return array;
}                 

//Print the Matrix
void printDat(const int* const *ary, int aryRows, int aryCols){
   int count=0;    //Count elements for formatting
   //Print Array with formatting
   for(int i=0; i<aryRows; i++){            //Loop for each row
       for(int j=0; j<aryCols; j++){        //Loop for each column
           count++;                         //Increment counter for each element
           cout<<ary[i][j];         
           if(count%aryCols!=0) cout<<" ";  //Print Space if not the last element of the row
       }
       if(i!=aryRows-1) cout<<endl;
   }
}   

//Augment the original array
int **augment(const int * const *ary, int aryRows, int aryCols){
    //Create Copy
    int **temp=new int*[aryRows+1]; //Plus one row
    
    //Allocate memory for columns
    for(int r=0; r<aryRows+1; r++){
        temp[r]=new int[aryCols+1]; //Plus one column
    }

    //Fill First Row
    for(int c=0; c<aryCols+1; c++){
        temp[0][c]=0;               //Zeroes for firt row
    }
    
    //Fill Fist column
    for(int r=0; r<aryRows+1; r++){
        temp[r][0]=0;               //Zeroes for first column
    }
    
    //Fill Inside
    for(int r=1; r<aryRows+1; r++){     //Loop for rows 
        for(int c=1;c<aryCols+1;c++){   //Loop for columns
            temp[r][c]=ary[r-1][c-1];   //Fill inside with original inputs
        }
    }
    
    return temp;
}

//Destroy the Matrix, i.e., reallocate memory
void destroy(int **ary, int aryRows){
    for(int r=0;r<aryRows;r++){
        delete []ary[r];
    }
    delete []ary;
} 