/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 26, 2021 2:12PM
 * Purpose:  Midterm Problem #4
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstring>   //C String Library
#include <cmath>
using namespace std;

//Function Prototypes
char *getDat(int);              //Get Input
int *encrypt(char *, int);      //Encrypt Number
void conv(char *, int *, int);  //Conversion to int array
int *decrypt(char *, int);      //Decrypt Number
void options(char *, int);      //Menu
void display(int *, int);       //Display Encrypted or Decrypted Number
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Declare all variables for this function
    int arySize=4;
    char *input;
    
    //Display menu
    options(input, arySize);
    
    //Deallocate memory
    delete input;

    return 0;
}

//Function Implementations
//Get Input
char *getDat(int arySize){
    char *ary=new char[arySize];
    cout<<"Input a 4-digit number: ";
    cin>>ary;
    for(int i=0; i<arySize; i++){
        if(ary[i]=='8'||ary[i]=='9'){
            cout<<"Invalid Input!"<<endl;
            cout<<"Utilize digits 0,1,2,3,4,5,6,7 only!"<<endl;
            cout<<"Re-enter 4-digit number to encrypt: ";
            cin>>ary;
        }
    }
    return ary;
}
//Encrypt Number
int *encrypt(char *ary, int arySize){
    int *encrypt=new int[arySize];
    
    //Fill encrypt 
    for(int i=0; i<arySize; i++){
        encrypt[i]=static_cast<int>(ary[i]-'0');
    }
    
    //Encryption Step One: Convert
    for(int i=0; i<arySize; i++){
        encrypt[i]=floor(encrypt[i]+5);      //Add 5 to each digit
        encrypt[i]=floor(encrypt[i]%8);      //Mod 8 each digit
    }

    //Encryption Step Two: Swap
    int temp=0;                             //temp variable for swap
    temp=encrypt[0];
    encrypt[0]=encrypt[2];                  //swap first digit with third
    encrypt[2]=temp;
    
    temp=encrypt[1];
    encrypt[1]=encrypt[3];                  //swap second digit with fourth
    encrypt[3]=temp;

    return encrypt;
}

//Decrypt Number
int *decrypt(char *ary, int arySize){
    int *decrypt=new int[arySize];
    int swap[arySize]={0,0,0,0};
    //Fill decrypt 
    for(int i=0; i<arySize; i++){
        decrypt[i]=static_cast<int>(ary[i]-'0');
    }
    //Decryption Step One: Swap
    int temp=0;                             //temp variable for swap
    temp=decrypt[0];
    decrypt[0]=decrypt[2];                  //swap first digit with third
    decrypt[2]=temp;
    
    temp=decrypt[1];
    decrypt[1]=decrypt[3];                  //swap second digit with fourth
    decrypt[3]=temp;

    //Decryption Step Two:
    for(int i=0; i<arySize; i++){ //Decryption Key
        if(decrypt[i]==0)swap[i]=3;
        if(decrypt[i]==1)swap[i]=4;
        if(decrypt[i]==2)swap[i]=5;
        if(decrypt[i]==3)swap[i]=6;
        if(decrypt[i]==4)swap[i]=7;
        if(decrypt[i]==5)swap[i]=0;
        if(decrypt[i]==6)swap[i]=1;
        if(decrypt[i]==7)swap[i]=2;
    }
    for(int i=0; i<arySize; i++){
        decrypt[i]=swap[i];
    }
    
    return decrypt;
}
//Display Encrypted or Decrypted Number
void display(int *output, int arySize){
    cout<<"Result: ";
        for(int i=0; i<arySize; i++){
            cout<<output[i];
        }
}
//Menu
void options(char *input, int arySize){
    int *output=new int[arySize];
    char choice=0;      //Menu Choice
    int flag=0;    //Flag to Quit Menu
    cout<<"Encryption Machine!"<<endl;
    cout<<"This program will encrypt or decrypt a 4-digit number"<<endl;
    cout<<"This program utilizes digits 0,1,2,3,4,5,6,7 only"<<endl;
    while(flag==0){
        cout<<"\n\nEnter 1 to Encrypt.\nEnter 2 to Decrypt\nEnter q to Quit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        switch(choice){
            case '1': 
                input=getDat(arySize);          //Get Number
                output=encrypt(input, arySize); //Encrypt 
                display(output, arySize);         //Display
                break;
            case '2': 
                input=getDat(arySize);          //Get Number
                output=decrypt(input, arySize); //Decrypt 
                display(output, arySize);         //Display
                break;
            case 'q':                           //Quit Program
            case 'Q':
                cout<<"End Program";
                flag=1;
                break;
            default:                            //Input Validation
                cout<<"Invalid Entry!"<<endl;
                cout<<"Enter 1 to Encrypt.\nEnter 2 to Decrypt\nEnter q to Quit"<<endl;
                cin>>choice;
                break;
        }
    };
    
    //Deallocate Memory
    delete output;
}

//clear
void clear(char *ary, int arySize){
    for (int i=0; i<arySize; i++){
        ary[i]=0;
    }
}



