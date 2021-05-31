/* 
 * File:   Grades.h
 * Author: Lindsay Kislingbury
 * Purpose: Grades Class Specification
 * Created on May 28, 2021, 7:06 PM
 */
#ifndef GRADES_H
#define GRADES_H

class Grades{
protected:
    float score;    //Numeric score
public:
    //Default constructor
    Grades(){
        score=0.0;
    }
    //Constructor
    Grades (float s){
        score=s;
    }
    //Mutator Function
    void setScore(float s){
        score=s;
    }
    //Accessor Function
    float getScore() const{
        return score;
    }
    
    char ltrGrade() const;
};
#endif /* GRADES_H */

