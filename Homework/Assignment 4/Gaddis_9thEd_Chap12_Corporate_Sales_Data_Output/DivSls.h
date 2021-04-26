/* 
 * File:   DivSls.h
 * Author: Lindsay Kislingbury
 * Created on April 23, 2021 11:29AM
    * Purpose: Structure to hold Division Quarterly Sales
 */

#ifndef DIVSLS_H
#define DIVSLS_H

#include<string>

struct DivSls{ 
    std::string name;
    unsigned short qrtr;
    float sales;
};

#endif /* DIVSLS_H */

