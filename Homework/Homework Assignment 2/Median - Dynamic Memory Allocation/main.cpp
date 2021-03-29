/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on March 25th 4:00PM
 * Purpose: Calucate Median 
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
int *getData(int &);            //Return the array size and the array
void prntDat(int *,int);        //Print the integer array
float *median(int *,int);       //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *,int);      //Print the median Array


//Execution begins here
int main(){
    //Declare variables
    int arySize;                //The array size
    int *ary;                   //Pointer to the array
    
    
    //Input the size of the array
    cin>>arySize;
    
    //Return the array size and the array
    ary=getData(arySize);
    
    //Print Median Array
    prntMed(median(ary,arySize), arySize);
    
    //Delete allocated memory
    delete []ary;
        
	//your code here
	return 0;
}

//Function Defintions

//Return the array size and the array
int *getData(int &arySize){
int *temp=new int[arySize];  //Dynamic Array to hold values
    
    //Fill the array with specified number of values
    for(int i=0; i<arySize; i++){
        cin>>temp[i];
    }
    
    //Print the array size and the array
    for(int i=0; i<arySize-1; i++){
        cout<<temp[i]<<" ";
        }
    cout<<temp[arySize-1]<<endl;
    
    return temp;
}

//Print the integer array
void prntDat(int *,int){}   

//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *ary, int arySize){
    float median=0.0;               //Hold the median value
    
    for(int i=0; i<arySize; i++){  //Sum the values
        median+=ary[i];
    }
    median/=arySize;               //Divide the sum by the number of values
    arySize+=2;                    //Add two to array size to hold median and array size data
    
    //Allocate and Fill the Mode Array
    float *medAry=new float[arySize];
    medAry[0]=arySize;
    medAry[1]=median;
    
    for(int i=0; i<arySize; i++){
        medAry[i+2]=ary[i];
    }
    
    return medAry;
}  

//Print the median Array
void prntMed(float *median, int arySize){
    
    //Display median without formatting
    cout<<median[0];
    //Display median array contents with formatting
    for(int i=1; i<arySize+2; i++){
        cout<<" "<<fixed<<setprecision(2)<<median[i];
    }
}     
