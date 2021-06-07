/* 
 * File:   Player.h
 * Author: Lindsay Kislingbury
 * Purpose: Card Class Specification
 * Created on June 1, 2021, 9:01 PM
 */

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card{
protected:
    Type            type;    //Type of Card
    short           num;     //Number 
    char            color;   //Color
    string          colName; //Color Name
    int             points;  //Points
public:
    //Constructor
    Card(){
        type="";num=0;color='';colName="";points=0;
    }
    
};


#endif /* CARD_H */

