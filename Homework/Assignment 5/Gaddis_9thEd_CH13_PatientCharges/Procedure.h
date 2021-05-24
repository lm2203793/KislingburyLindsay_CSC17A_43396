/* 
 * File:   Patient.h
 * Author: Lindsay Kislingbury
 * Purpose: Specification for Patient Class
 * Created on May 22, 2021, 9:04 PM
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <string>
using namespace std;

class Procedure{
private:
    string  procdre,    //Name of the procedure
            date,       //Date of the procedure
            dr;         //Name of practitioner
    float   charges;    //Charge for the procedure
public:
    //Constructor
    Procedure(string pro, string dt, string doc, float chrgs){
        procdre=pro; date=dt; dr=doc; charges=chrgs;
    }
    
    //Set functions
    void setPrc(string prc){
        procdre=prc;
    }
    void setDt(string dt){
        date=dt;
    }
    void setDr(string doc){
        dr=doc;
    }
    void setChgs(float chgs){
        charges=chgs;
    }
    
    //Get functions
    string getPrc(){
        return procdre;
    }
    string getDt(){
        return date;
    }
    string getDr(){
        return dr;
    }
    float getChgs(){
        return charges;
    }
    
};



#endif /* PROCEDURE_H */

