/* 
 * File:   TestScores.h
 * Author: Lindsay Kislingbury
 * Purpose: TestScores class problem
 * Created on May 23, 2021, 3:16 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "TestScores.h"
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n;      //number of test scores
    int score;  //hold score input
    
    //Get Test Scores
    cout<<"How many test scores?: ";
    cin>>n;
    
    //Create TestScores object
    TestScores scores(n);
    
    //Input Scores
    for(int i=0; i<scores.getSize(); i++){
        cout<<"Enter Test Score #"<<i+1<<": ";
        cin>>score;
        scores.setScore(i,score);
    }
    
    //Calculate Average
    scores.calcAvg();
    
    //Display All Scores and Average
    cout<<"Your Scores:"<<endl;
    for(int i=0; i<scores.getSize(); i++){
        cout<<scores.getScore(i);
        if(i!=scores.getSize()-1) cout<<", ";
    }
    cout<<endl;
    cout<<"Your Average: ";
    cout<<fixed<<setprecision(1)<<scores.getAvg()<<endl;
    return 0;
}

