/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Created on April 23, 2021 11:29AM
    * Purpose: Corporate Sales Data Output
 *              Division Sales Structure
 */
#ifndef DIVSLS_H
#define DIVSLS_H

struct Qtr{
    unsigned short  qtr;
    float           amnt;
};

struct DivSls{
    char    name[50];
    Qtr     sales[4];
};





#endif /* DIVSLS_H */

