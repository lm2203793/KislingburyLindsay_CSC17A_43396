
/* 
 * File:   Card.h
 * Author: linds
 *
 * Created on June 2, 2021, 8:08 PM
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
    //Constructor
    Card(Type tp, short nm, char col, string coln, int pts){
        type=tp; num=nm; color=col; coln=colName; points=pts;
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

