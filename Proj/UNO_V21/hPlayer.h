
/* 
 * File:   hPlayer.h
 * Author: Lindsay Kislingbury
 * Purpose: hPlayer Class Specification
 * Created on June 5, 2021, 5:26 PM
 */

#ifndef HPLAYER_H
#define HPLAYER_H

class hPlayer : public Player{
private:
public:
    //Default Constructor
    hPlayer() : Player(){}
    
    
    virtual Card getPcrd(Card);
    

};


#endif /* HPLAYER_H */

