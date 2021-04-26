/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 21, 2021 9:51PM
    * Purpose: Array/File Functions
 */

//Libraries
#include <iostream>
#include <fstream>
using namespace std;


//Function Prototypes
int *filAray(int);
void aToFile(string, int*, int&);
void modify(string, int*, int&);
void fToArry(string, int*, int&);
void printA(int*, int&);
void printF(string, int &);

int main(int argc, char** argv) {
    //Execution Begins here
    
    //Declare variables
    int arySize=20;             //Array Size
    int *arr=nullptr;           //Pointer to the array
    string fileNm="num.dat";    //Name of the binary file
            
    //Fill Array with random numbers
    arr=filAray(arySize);
    
    //Print Array
    cout<<"Array Contents: "<<endl;
    printA(arr, arySize);
    cout<<endl;
    
    //Write array to file
    cout<<"Writing Array to File..."<<endl;
    aToFile(fileNm, arr, arySize);
    
    //Modify Array
    cout<<"Modifying File Contents..."<<endl;
    modify(fileNm, arr, arySize);
    
    //Read contents of file into array
    cout<<"Reading Modified Array from file..."<<endl;
    fToArry(fileNm, arr, arySize);
    
    //Print array
    cout<<"Modified Array Contents:"<<endl;
    printA(arr, arySize);

    //Exit
    return 0;
}

//Function Definitions

//Fill Array
int *filAray(int n){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array
    for(int i=0; i<n; i++){
        *(array+i)=rand()%90+10;
    }
    return array;
}

//Write contents of array to file
void aToFile(string fileNm, int *arr, int &arySize){
    fstream datFile; //File Stream Object
    //Open file in output mode
    datFile.open(fileNm, ios::out | ios::binary); 
    //Write array to file
    datFile.write(reinterpret_cast<char *>(arr), arySize);
    //Close File
    datFile.close(); 
}

//Modify File
void modify(string fileNm, int *arr, int &arySize){
    //Modify array contents
    for(int i=0; i<arySize; i++){
        *(arr+i)=rand()%10+2;
    }
    //Write modified array to file
    fstream datFile; //File stream object
    //Open file in output mode
    datFile.open(fileNm, ios::out | ios::binary);
    //Write modified array to file
    datFile.write(reinterpret_cast<char *>(arr), arySize);
    //Close the file
    datFile.close();
}

//Read contents of file into an array
void fToArry(string fileNm, int *arr, int &arySize){
    fstream datFile; //File stream object
    //Open file in input mode
    datFile.open(fileNm, ios:: in | ios::binary);
    //Read contents of file into array
    datFile.read(reinterpret_cast<char *>(arr), arySize);
    //Close the file
    datFile.close();
}

//Print Array
void printA(int *arr, int &arySize){
    for(int i=0; i<arySize; i++){
        cout<<arr[i]<<" ";
    }
}
