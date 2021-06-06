/* 
 * File:   cPlayer.h
 * Author: Lindsay Kislingbury
 * Purpose: cPlayer Class Specification
 * Created on June 5, 2021, 5:31 PM
 */

#ifndef CPLAYER_H
#define CPLAYER_H
#include "Player.h"
#include "Card.h"

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
    
    ~Cplayer(){
        cout<<"bot destroyed"<<endl;
    }
    
    //counts number of each symbol
    void scoreSym(int*);
    
    //counts number of each color
    void scoreClr(int*);
    
    //assigns a value to each valid card by number
    void scrCrdsN(vector<int>, int *, int *, int);
    //assigns a value to each valid card by color
    void scrCrdsC(vector<int>, int *, int *, int);
   
    
    
    int findMaxN(vector<int> valCrds);
    
    virtual Card getPcrd(Card);
    
    int fndMchSym(Type, vector<int>);
    
    int fndMchSym(int, vector<int>);
    int fndWild(vector<int>);
    
    int fndMaxC(vector<int>);
    
    int fndMtchC(vector<int>, char);
    
    char wildPic();
    
};



#endif /* CPLAYER_H */

