/* 
 * File:   Player.cpp
 * Author: Lindsay Kislingbury
 * Purpose: GmScore Struct Specification
 * Created on June 2, 2021, 8:08 PM
 */

#ifndef GMSCORE_H
#define GMSCORE_H

struct GmScore{
    string      nm;         //Player name
    int         lrgHnd=0;   //Largest hand
    bool        win;        //Win status 
};

#endif /* GMSCORE_H */

