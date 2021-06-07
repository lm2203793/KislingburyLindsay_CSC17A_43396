/* 
 * File:   Card.h
 * Author: Lindsay Kislingbury
 * Purpose: Cplayer Class Specification
 * Created on June 5, 2021, 4:12 PM
 */

#ifndef CPLAYER_H
#define CPLAYER_H
#include "Player.h"
#include "Card.h"

class Cplayer : public Player{
private:
    int     hardNum;   //Difficulty Level
                       //1: Dumb Bot, 2: Lucky Bot, 3: Smart Bot
public:
    //Default Constructor
    Cplayer() : Player(){}
    
    //Set Difficulty
    void setHrd(int n){
        hardNum=n;
    }
    //Overloaded version of getPcrd
    virtual Card getPcrd(Card &);

    //Choose a wild color
    char chsWild();
    
    //Assigns a value to each symbol(# or type)
    void scoreSym(int[]);
    
    //Assigns a value to each color
    void scoreClr(int[]);
    
    //Assigns a value to each playable card in the player's hand
    //For number and type
    int scrCrdsN(vector<int>, int[], int);
    
    //Assigns a value to each playable card in the player's hand
    //For color
    int scrCrdsC(vector<int>, int[], int);
    
    //Assigns a value to each playable card in the player's hand
    //Number, type, and color
    int sCrdsA(int [], int [], vector<int>, int );
    
};



#endif /* CPLAYER_H */

