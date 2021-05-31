/* 
 * File:   Essay.h
 * Author: Lindsay Kislingbury
 * Purpose: Essay Class Specification
 * Created on May 30, 2021, 7:06 PM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "Grades.h"

class Essay : public Grades{
    private: 
        const float GRAMMAR=0.30;   //Weight for Grammar 
        const float SPELLING=0.20;  //Weight for Spelling 
        const float LENGTH=0.20;    //Weight for Length 
        const float CONTENT=0.30;   //Weight for Content 
        float grmr;   //Points received for grammar
        float spel;   //Points received for spelling
        float len;    //Points received for length
        float cont;   //Points received for content
               
    public:
        //Default Constructor
        Essay(){
            grmr=0;
            spel=0;
            len=0;
            cont=0;
        }
        //Constructor
        Essay(float g,float s,float l ,float c){
            set(g, s, l, c);
        }
        //Mutator
        void set(float,float,float,float); //Defined in Essay.cpp
};
#endif /* ESSAY_H */

