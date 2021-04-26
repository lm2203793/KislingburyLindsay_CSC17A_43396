/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 21, 2021 3:42PM
    * Purpose: Sentence Filter
 */

//Libraries
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

//Function Prototypes
/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    fstream file;
    string quote,author;
   
    //Input
    file.open("quote.txt");
    getline(file, quote, '\n');
    getline(file, author);
    
    cout<<"Sentence Filter:"<<endl;
    cout<<"This program changes the case of all letters to the correct formatting\n"<<endl;
    cout<<"Text Before:"<<endl;
    cout<<quote<<endl;
    cout<<author<<endl;
    
    //Format Quote
    for(int i=1; i<quote.length(); i++){//Change all letters to lowercase
        quote[i]=tolower(quote[i]);
    }
    quote[0]=toupper(quote[0]);//Capitalize First Letter of Quote
    for(int i=0; i<quote.length(); i++){//Capitalize First Letter of Every Sentence 
        if(quote[i]=='.'){
            quote[i+2]=toupper(quote[i+2]);
        }
        if(quote[i]=='i'&&quote[i-1]==' '&&quote[i+1]==' '){//Capitalize the word I
                quote[i]=toupper(quote[i]);
        }
        if(i%80==0){ //Insert Line Breaks
            if(quote[i+1]==' '){
                quote.insert(i,1,'\n');
            }
            else{
                int x=quote.find(' ', i);
                quote.insert(x+1,1,'\n');
            }
        }
    }
    
    //Format Attribution
       for(int i=0; i<author.length(); i++){//Change all letters to lowercase
        author[i]=tolower(author[i]);
    }
    author[0]=toupper(author[0]);
    for(int i=0; i<author.length(); i++){//Capitalize First Letter of Every Word
        if(author[i-1]==' '){
            author[i]=toupper(author[i]);
        }
    }

        
    cout<<"\nText After:";
    cout<<quote<<endl;
    cout<<author<<endl;
    
    
    return 0;
}

