/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 27, 2021 1:51PM
 * Purpose:  Midterm Problem #5
 */

//System Libraries
#include <iostream>  //I/O Library
#include <vector>    //Vector Library
#include <iomanip>   //Format Library
using namespace std;

//Function Prototypes
void menu();    //Menu
void chtr();    //Char  
void unChar();  //Unsigned Char
void shInt();   //Short Int
void unShInt(); //Unsigned Short Int
void integer(); //Int
void unInt();   //Unsigned Int
void lngInt();  //Long Int
void flt();     //Float
void dbl();     //Double

//Execution of Code Begins Here
int main(int argc, char** argv) {
    
    //Run Program
    menu();

    //Exit stage right
    return 0;
}

//Function Implementations
//Menu
void menu(){
    char choice;
    cout<<"Find the largest n where n!=factorial that can be calculated"<<endl;
    cout<<"For each data type."<<endl;
    do{
        cout<<"\nChoose a data type to test:"<<endl;
        cout<<left<<setw(23)<<"1. Char"<<setw(23)<<"2. Unsigned Char"<<setw(23)<<"3. Short Int"<<endl;
        cout<<setw(23)<<"4. Unsigned Short Int"<<setw(23)<<"5. Int"<<setw(23)<<"6. Unsigned Int"<<setw(23)<<"7. Long Int"<<endl;
        cout<<setw(23)<<"8. Float"<<setw(23)<<"9. Double"<<endl;
        cout<<"Enter q to quit"<<endl;
        cin>>choice;
        switch(choice){
            case '1': //Char
                chtr();
                break;
            case '2': //Unsigned Char
                unChar();
                break;
            case '3': //Short int
                shInt();
                break;
            case '4': //Unsigned short int
                unShInt();
                break;
            case '5': //Int
                integer();
                break;
            case '6': //Unsigned Int
                unInt();
                break;
            case '7': //Long Int
                lngInt();
                break;
            case '8': //Float
                flt();
                break;
        }      
    }while(choice!='q');
}


//Char
void chtr(){
    char n=1;
    vector<char>vals;
    int x=100;
    cout<<"\nCHAR"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<int(n)<<endl;
        if(n<=0||n<vals[i-1]||n>127){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}

//Unsigned Char
void unChar(){
    unsigned char n=1;
    vector<unsigned char>vals;
    int x=100;
    cout<<"\nUNSIGNED CHAR"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<int(n)<<endl;
        if(n<=0||n<vals[i-1]||n>255){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}

//Short int
void shInt(){
    short int n=1;
    vector<short int>vals;
    int x=100;
    cout<<"\nSHORT INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<0||n<vals[i-1]||n>32767){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Unsigned short int
void unShInt(){
    unsigned short int n=1;
    vector<unsigned short int>vals;
    int x=100;
    cout<<"\nUNSIGNED SHORT INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>65535){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}

//Int
void integer(){
    int n=1;
    vector<int>vals;
    int x=100;
    cout<<"\nINT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]>n>2147483647){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Unsigned Int
void unInt(){
    unsigned int n=1;
    vector<unsigned int>vals;
    int x=100;
    cout<<"\nUNSIGNED INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>4294967295){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}
//Long Int
void lngInt(){
    long int n=1;
    vector<long int>vals;
    int x=100;
    cout<<"\nLONG INT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>9223372036854775807){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}

//Float
void flt(){
    float n=1;
    vector<float>vals;
    int x=200;
    cout<<"\nFLOAT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>3.40282e+38){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}

void dbl(){
    double n=1;
    vector<double>vals;
    int x=200;
    cout<<"\nFLOAT"<<endl;
    for(int i=1; i<x; i++){
        n=(n*i);
        vals.push_back(n);
        cout<<"n= "<<i<<"  :"<<n<<endl;
        if(n<=0||n<vals[i-1]||n>1.79769e+308){ //Odd behavior or exceed limit
            cout<<"Overflow at "<<i<<endl;
            cout<<"Largest n where n! can be calculated: "<<i-1<<endl;
            break;
            }
    }
}

