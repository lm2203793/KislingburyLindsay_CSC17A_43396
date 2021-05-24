/* 
 * File:   Patient.h
 * Author: Lindsay Kislingbury
 * Purpose: Specification for Patient Class
 * Created on May 22, 2021, 9:04 PM
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;


class Patient{
private:
    string  first,      //Patient first name
            middle,     //Patient middle name
            last;       //Patient last name
    string  city,       //Patient city
            street,     //Patient street
            zip;        //Patient zip code
public:
    //Constructor 
    Patient(string frst, string mid, string lst, string strt, 
            string cty, string z){
        first=frst; middle=mid; last=lst;
        city=cty; street=strt; zip=z;
    }
    //Set Functions
    void setName(string frst,string mid,string lst){
        first=frst; middle=mid; last=lst;
    }
    void setAdd(string strt,string cty,string z){
        city=cty; street=strt; zip=z;
    }
    //Get Functions
    string getName(){
        string name=first+" "+middle+" "+last;
        return name;
    }
    string getAdd(){
        string add=street+" "+city+" "+zip;
        return add;
    }
    
};


#endif /* PATIENT_H */

