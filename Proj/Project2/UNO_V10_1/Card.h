/* 
 * File:   Player.h
 * Author: Lindsay Kislingbury
 * Purpose: Card Class Specification
 * Created on June 1, 2021, 9:01 PM
 */

#ifndef CARD_H
#define CARD_H
#include <string>
#include "Type.h"
using namespace std;

class Card{
protected:
    Type            type;    //Type of Card
    short           num;     //Number 
    char            color;   //Color
    string          colName; //Color Name
    int             points;  //Points
public:
    //Default constructor
    Card(){
        
    }
    //Mutators
    void setType(Type t){
        type=t;
    }
    void setNum(short n){
        num=n;
    }
    void setColor(char c, string cn){
        color=c;
        colName=cn;
    }
    void setPoints(int p){
        points=p;
    }
    //Accessors
    Type getType() const{
        return type;
    }
    short getNum() const{
        return num;
    }
    char getColor() const{
        return color;
    }
    string getColn() const{
        return colName;
    }
    int getPoints() const{
        return points;
    }
    
};


#endif /* CARD_H */

