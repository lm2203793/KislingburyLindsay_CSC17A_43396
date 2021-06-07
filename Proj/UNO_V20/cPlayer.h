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
    
    int findMaxN(vector<int> valCrds);
    
    virtual Card getPcrd(Card);
    
    int fndMchSym(Type, vector<int>);
    
    int fndMchSym(int, vector<int>);
    int fndWild(vector<int>);
    
    int fndMaxC(vector<int>);
    
    int fndMtchC(vector<int>, char);
    
};



#endif /* CPLAYER_H */

