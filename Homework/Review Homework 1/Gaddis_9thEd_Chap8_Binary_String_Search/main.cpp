/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury 
 * Created on March 8, 2021 8:19PM
 * Purpose:  Search an Array of strings
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void bblSrt(string[],int);      //Sort an array of strings alphabetically
int binSrch(string[], string, int);  //Search an array of strings

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int NUM_NMS       =20;
    string names[NUM_NMS]   ={"Collins, Bill", "Smith, Bart", "Allen, Jim", 
                              "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                              "Taylor, Terri","Johnson, Jill", "Allison, Jeff",
                              "Looney, Joe", "Wolfe, Bill", "James, Jean",
                              "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                              "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                              "Pike, Gordon", "Holland, Beth"};
    string search;          //Name to search for
    int pos;                //Position of the found name
    char exit;              //Flag to exit progam
    
    //Initialize Variables
    search="";
    
    //Map Inputs to Outputs -> Process
    
    //Sort the names alphabetically
    bblSrt(names, NUM_NMS);  
    
    //Display sorted names
    cout<<"This program searches a list of names."<<endl;
    cout<<"Here is the list of names:"<<endl;
    for(int x=0; x<20; x++){
        cout<<"#"<<x+1<<": ";
        cout<<names[x]<<endl;
    }
    
    //Get name to search for
    
    do{
        cout<<"Enter a name to search for:"<<endl;
        cout<<"Please enter the name exactly as shown, including punctuation "
              "and spaces"<<endl;
        getline(cin, search);

        //Search for name
        pos=binSrch(names, search, NUM_NMS);

        //Display position of name
        if(pos!=-1){
          cout<<"That name is found at position: "<<pos<<endl;  
        }
        else{
          cout<<"Invalid entry! Please enter the name exactly as shown, "
                "including punctuation and spaces"<<endl;
          cin.clear();
        }
    }while(pos==-1);

    
    //Display Inputs/Outputs
    
    //Exit the Program - Cleanup
    return 0;
}

//Function Definitions

//Bubble Sort an array of strings
void bblSrt(string names[],int n){
   for(int i=0; i<n-1; i++)    
       for(int j = 0; j < n-i-1; j++)  
           if (names[j].compare(names[j+1]) > 0){ 
                 string temp = names[j+1];
                 names[j+1] = names[j];
                 names[j] = temp;
             } 
} 

//Binary Search on an array of strings
int binSrch(string names[], string search, int size){
    int first=0;                //First element in array
    int last=size;                //Last element in array
    int middle;               //Mid point of search
    int position =-1;           //Flag
    bool found=false;
    int srchs=0;              //
    
    while(!found && first <= last){
        middle=(first+last)/2;  //Calculate mid point
        if(names[middle]==search){
            found=true;
            position=middle;
        }
        else if(names[middle][0]>search[0]){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
    }
    return position;
}
