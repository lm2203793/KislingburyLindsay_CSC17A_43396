/* 
 * File:   cPlayer.h
 * Author: Lindsay Kislingbury
 * Purpose: cPlayer Class Specification
 * Created on June 5, 2021, 5:31 PM
 */

#ifndef CPLAYER_H
#define CPLAYER_H
#include "Player.h"

class Cplayer : public Player{
private:
    int     hardNum;   //difficulty
public:
    //Default Constructor
    Cplayer() : Player(){}
    
    //set difficulty
    void setHrd(int n){
        hardNum=n;
    }
    
    void something(vector<int> valCrds);
    
    virtual Card getPcrd(Card);
};



#endif /* CPLAYER_H */

