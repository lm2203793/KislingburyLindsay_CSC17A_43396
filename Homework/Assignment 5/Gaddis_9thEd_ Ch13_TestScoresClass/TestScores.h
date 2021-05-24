/* 
 * File:   TestScores.h
 * Author: Lindsay Kislingbury
 * Purpose: TestScores class specification
 * Created on May 23, 2021, 3:16 PM
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores{
private:
    int     size;
    float   *scores;
    float   avg;
public:
    //Constructor
    TestScores(int n){
        size=n;
        scores=new float[size];
    }
    //Destructor
    ~TestScores(){
        delete []scores;
    }
    //Set an individual Score
    void setScore(int i, float s){
        scores[i]=s;
    }
    //Get an individual score
    float getScore(int i){
        return scores[i];
    }
    //Calculate average score
    void calcAvg(){
        for(int i=0; i<size; i++) avg+=scores[i];
        avg/=size;  
    }
    //Get average Score
    float getAvg(){
        return avg;
    }
    int getSize(){
        return size;
    }
};


#endif /* TESTSCORES_H */

