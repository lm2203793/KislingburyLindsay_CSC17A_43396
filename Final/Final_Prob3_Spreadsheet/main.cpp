/* 
 * File:   Prob3TableInherited.h
 * Author: Lindsay Kislingbury
 * Purpose: Spread Sheet Stuff
 * Created on June 9, 2021, 3:24 PM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
//User Libraries
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {

    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    
    char fileNm[]="Problem3.txt";
    Prob3TableInherited<int> tab(fileNm,rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    //Exit
    return 0;
}

