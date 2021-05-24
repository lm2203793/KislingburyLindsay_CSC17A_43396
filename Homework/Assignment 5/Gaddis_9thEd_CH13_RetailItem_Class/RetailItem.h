/* 
 * File:   RetailItem.h
 * Author: Lindsay Kislingbury
 * Purpose: Specification for RetailItem class
 * Created on May 22, 2021, 10:09 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std;

class RetailItem{
private:
    string      desc;       //Item description
    int         units;      //# of units on hand
    float       price;      //Price of the item
public:
    //Constructor
    RetailItem(){
        desc=" "; units=0; price=0.0;
    }
    
    //Set functions
    void setDesc(string d){
        desc=d;
    }
    void setUnts(int u){
        units=u;
    }
    void setPrc(float p){
        price=p;
    }
    
    //Get functions
    string getDesc() const{
        return desc;
    }
    int getUnts() const{
        return units;
    }
    float getPrc() const{
        return price;
    }
    
};


#endif /* RETAILITEM_H */

