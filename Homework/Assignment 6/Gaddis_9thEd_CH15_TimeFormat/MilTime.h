/* 
 * File:   MilTime.h
 * Author: Lindsay Kislingbury
 * Purpose: MilTime Class Specification
 * Created on May 29, 2021
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time{
    private:
        char *milHrs;     //24hr military time format
        int  milSecs;     //seconds in standard format
    public:
        //Default Constructor
        MilTime(char *hrs, int sec):Time(){
            milHrs=hrs;
            milSecs=sec;
        }
        //Convert
        void cnv();        
};

#endif /* MILTIME_H */

