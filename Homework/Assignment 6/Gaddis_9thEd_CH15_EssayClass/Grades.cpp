/* 
 * File:   Grades.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Grades Class Member Function Definition
 *          ltrGrade() assigns a letter grade to an assignment
 * Created on May 30, 2021, 7:06 PM
 */
#include "Grades.h"

char Grades::ltrGrade() const{

    char letterGrade;               //Letter grade
    if(score>89) letterGrade='A';
    else if(score>79) letterGrade='B';
    else if(score>69) letterGrade='C';
    else if(score>59) letterGrade='D';
    else letterGrade='F';

    return letterGrade;
}
