/* 
 * File:   main.cpp
 * Author: Lindsay Kisingbury
 * Created on April 24, 2021, 4:35 PM
 * Purpose:  Midterm Problem #2
 *           Pay Check Structure
 */

#ifndef PAYCHECK_H
#define PAYCHECK_H

struct PayChk{
    std::string     company,        //Company Name
                    address,        //Company Address
                    name,           //Employee Name
                    engPay;         //Gross Pay in English
    unsigned short  hrs;            //Hours Worked
    float           rate,           //Pay Rate
                    gross=0;        //Gross Pay
            
};


#endif /* PAYCHECK_H */

