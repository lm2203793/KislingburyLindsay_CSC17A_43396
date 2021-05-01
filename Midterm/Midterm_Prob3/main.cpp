/* 
 * File:   main.cpp
 * Author: Linday Kislingbury
 * Date: April 26, 2021 2:11PM
 * Purpose:  Midterm Problem #3 Not included in menu
 * Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    
    //Mode    
    //Allocate the mode array
    stats->mode=new Array;
    //Find max frequency
    int freq=0, nmodes=0;
    for(int i=0; i<array->size; i++){
        int count=0;                                //Instances of the number
        for(int j=0; j<array->size; j++){
            if(array->data[j]==array->data[i]){     //Element matches
                count++;                            //Increment Count
            }
        }   
        if(count>=freq){
            freq=count;                             //Highest Count
        }
    }
    
    //Store the max frequency
    stats->modFreq=freq;
    
    //Find number of modes
    for(int i=0; i<array->size; i++){
        int match=0;                                //Number of matches found
            for(int k=i+1; k<(i+freq); k++){
                if(array->data[i]==array->data[k]){ //Element matches
                    match++;                        //Increment match
                  if(match==(freq-1)){              //Matches = Max frequency
                      nmodes++;                     //Increment number of modes
                      i=k;                          //Skip over to next value
                      break; 
                  }
                }                               
                else{                               //Element doesn't match
                    i=k;                            //Skip over to next value
                    break;
                  }
            }     
    }
    
    //Store the number of modes
    stats->mode->size=nmodes;
    
    if(nmodes!=0){
       stats->mode->data=new int[stats->mode->size];
        //Fill the mode array
        int indx=0;                             //Index to store mode values
        int count=0;                            //Count number of modes
        for(int i=0; i<array->size; i++){
            int match=0;                        //Number of matches found
                for(int k=i+1; k<(i+freq); k++){
                    if(array->data[i]==array->data[k]){//Match
                        match++;
                      if(match==(freq-1)){      //Number of matches = Max freq
                          stats->mode->data[indx]=array->data[i]; //Store 
                          indx++;               //Increment index
                          i=k;                  //Skip over to next value
                          break; 
                      }
                    }
                    else{                       //Match not found, skip over
                        i=k;
                        break;
                      }
                }     
        }
    }
    //Median
    //The number in the middle, or the average of the two middle numbers
    float median=0.0;                            //Hold the median value
    if(array->size%2 != 0){                      //If the array size is even         
        median=array->data[array->size/2];       //Get the middle value          
    }
    else{                                        //If the array size is odd
        median=array->data[(array->size-1)/2];   //Average of middle numbers
    }
    
    //Store the median
    stats->median=median;
    
    //Mean (average)
    float mean=0.0;
    for(int i=0; i<array->size; i++){
        mean+=array->data[i];                 //Sum all values
    }   
    mean/=array->size;                           //Divide by number of values
    
    //Store the average
    stats->avg=mean;
    
    return stats;
}