/* 
 * File:   MilTime.h
 * Author: Lindsay Kislingbury
 * Purpose: MilTime Class Specification
 *          with exception handling
 * Created on May 30, 2021
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time{
    private:
        int milHrs;     //24hr military time format
        int  milSecs;        //seconds in standard format
    public:
        //Default Constructor
        MilTime():Time(){

        }
        //Exception Class for Invalid Hour amount
        class BadHour{
        private:
            int bad;
        public:
            BadHour(int val){
                bad=val;
            }
            int getVal() const{
                return bad;
            }
        };
        //Exception Class for Invalid Seconds
        class BadSecs{
        private:
            int bad;
        public:
            BadSecs(int val){
                bad=val;
            }
            int getVal() const{
                return bad;
            }
        };
        //Mutators
        void setMilHr(string);
        void setMilSec(int);
        
        //Accessors
        int getMilHr() const{
            return milHrs;
        }
        int getMilSecs() const{
            return milSecs;
        }
        
        //Convert
        void cnv(); //Defined in MilTime.cpp
};

#endif /* MILTIME_H */

