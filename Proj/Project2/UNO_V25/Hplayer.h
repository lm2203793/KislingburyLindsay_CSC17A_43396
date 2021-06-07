
/* 
 * File:   hPlayer.h
 * Author: Lindsay Kislingbury
 * Purpose: hPlayer Class Specification
 * Created on June 5, 2021, 5:26 PM
 */

#ifndef HPLAYER_H
#define HPLAYER_H
#include "Player.h"

class Hplayer : public Player{
private:
public:
    //Default Constructor
    Hplayer() : Player(){}
    
    //Destructor
    ~Hplayer(){
        cout<<"human destroyed"<<endl;
    }
    
    virtual Card getPcrd(Card);
    

};


#endif /* HPLAYER_H */

