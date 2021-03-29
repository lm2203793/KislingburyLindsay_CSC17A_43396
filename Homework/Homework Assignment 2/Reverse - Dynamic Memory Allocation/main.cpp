/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 26th 10:17PM
 * Purpose: Reverse a dynamic array
 */

//Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int *getData(int &);                //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);      //Sort in reverse order
void prntDat(const int *,int);      //Print the array

//Execution begins here
int main(){
    //Declare variables
    int arySize;                //The array size
    int *ary;                   //Pointer to the array
    
    //Input the size of the array
    cin>>arySize;
    
    //Return the array size and the array
    ary=getData(arySize);
    
    //Print Array in Ascending order
    prntDat(sort(ary,arySize), arySize);
    
    //Print NewLine
    cout<<endl;
    
    //Print Array in Reverse order
    prntDat(reverse(sort(ary,arySize),arySize), arySize);
    
    //Delete allocated memory
    delete []ary;

	return 0;
}

//Function Definitions

//Return the array size and the array
int *getData(int &arySize){
    int *temp = new int[arySize];
    
    //Fill the array with specified number of values
    for(int i=0; i<arySize; i++){
        cin>>temp[i];
    }
    
    return temp;
}   

//Sort smallest to largest
int *sort(const int *ary, int arySize){
    //Copy the array
    int *temp = new int[arySize];
    //Fill with passed array
    for(int i=0;i<arySize;i++){
        temp[i]=ary[i];
    }
   
   //Sort the array in ascending order
    for(int i=0;i<arySize-1;i++){      
        for(int j=i+1;j<arySize;j++){  
            if(temp[i]>temp[j]){       
                temp[i]=temp[i]^temp[j];  
                temp[j]=temp[i]^temp[j];  
                temp[i]=temp[i]^temp[j];  
            }
        }
    }
    
    //Return Sorted Array
    return temp;
}    

//Sort in reverse order
int *reverse(const int *ary, int arySize){
    //Copy the array
    int *temp = new int[arySize];
    //Fill with passed array
    for(int i=0;i<arySize;i++){
        temp[i]=ary[i];
    }
    
    //Reverse Contents
    int beg=0;           //Points to begginning element
    int end=arySize-1;   //Points to last element
    int x=0;             //Hold the value being swapped

    while(beg<end){
        x = temp[beg];
        temp[beg] = temp[end];
        temp[end] = x;
        beg++;  
        end--;  
    }
    
    //Return Reversed Array
    return temp;
}

//Print the array
void prntDat(const int *ary, int arySize){
    for(int i=0; i<arySize-1; i++){
        cout<<ary[i]<<" ";
    }
    cout<<ary[arySize-1];
}      