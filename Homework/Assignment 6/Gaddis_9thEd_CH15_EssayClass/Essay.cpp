/* 
 * File:   Grades.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Essay Class Member Function Definition
 *          set function adds points for all categories
 *          and passes the score to Grades setscore() function
 * Created on May 30, 2021, 7:06 PM
 */
#include "Essay.h"

void Essay::set(float g,float s,float l,float c){
    float score;
    //Add the scores multiplied by their weights
    score=((g*GRAMMAR)+(s*SPELLING)+(l*LENGTH)+(c*CONTENT));
    //Call Grades Class Function setScore
    setScore(score);
}
