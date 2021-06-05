/* 
 * File:   Card.h
 * Author: Lindsay Kislingbury
 * Purpose: Card Class Specification
 * Created on June 2, 2021, 8:08 PM
 */

#ifndef CARD_H
#define CARD_H
#include <iostream> //I/O Library
#include <string>   //String Library
#include <iomanip>  //Formating Library
#include "Type.h"   //Type Enum
using namespace std;
class Card;   //Forward Declaration for overloaded <<
//Function Prototype for overloaded <<
ostream &operator <<(ostream &, const Card &);

class Card{
protected:
    Type            type;    //Type of Card
    short           num;     //Number 
    char            color;   //Color
    std::string     colName; //Color Name
    int             points;  //Points
public:
    //Default Constructor
    Card(){
        type=NUMBER;
        num=0;
        color='r';
        colName="red";
        points=0;
    }
    //Constructor
    Card(Type tp, short nm, char col, int pts){
        type=tp; num=nm; color=col; points=pts;
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
    std::string getColn() const{
        return colName;
    }
    void prtColn(){
        cout<<colName;
    }
    int getPoints() const{
        return points;
    }
    //Mutators
    void setColor(char c){
        color=c;
        colName=(c=='X')?"wild":
                (c=='r')?"red":
                (c=='g')?"green":
                (c=='b')?"blue":"yellow";
    }
    //Friends
    //overloaded <<
    friend ostream &operator << (ostream &strm, const Card &crd){
        //If the card is a number card, display number and color
        if(crd.type==NUMBER){
            strm<<setw(2)<<"[  "<<left<<setw(2)<<crd.num<<right
            <<setw(6)<<crd.colName<<setw(3)<<"   ]";
        }
        //Else display type and color
        else{     
            if(crd.type==SKIP){
                strm<<left<<setw(1)<<"["<<setw(7)<<"SKIP"
                        <<right<<setw(6)<<crd.colName<<setw(1)<<"]";
            }
            else if(crd.type==REVERSE){
                strm<<left<<setw(1)<<"["<<setw(7)<<"REVERSE"
                        <<right<<setw(6)<<crd.colName<<setw(1)<<"]";
            }
            else if(crd.type==DRAW2){
                strm<<left<<setw(1)<<"["<<setw(7)<<"DRAW-2"
                        <<right<<setw(6)<<crd.colName<<setw(1)<<"]";
            }
            else if(crd.type==WILD)
                strm<<left<<setw(1)<<"["<<setw(7)<<"WILD"
                        <<right<<setw(6)<<crd.colName<<setw(1)<<"]";
            else if(crd.type==WILD4)
                strm<<left<<setw(1)<<"["<<setw(7)<<"WILD-DRAW4"
                        <<right<<setw(3)<<crd.colName<<setw(1)<<"]";
        }
        return strm;
    }
};
#endif /* CARD_H */

