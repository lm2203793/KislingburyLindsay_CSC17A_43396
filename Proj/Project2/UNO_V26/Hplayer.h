/* 
 * File:   hPlayer.h
 * Author: Lindsay Kislingbury
 * Purpose: Hplayer Class Specification
 *          derived from Player class
 * Created on June 5, 2021, 5:26 PM
 */

#ifndef HPLAYER_H
#define HPLAYER_H
#include <iostream>
#include "Player.h"

class Hplayer : public Player{
public:
    //Default Constructor
    Hplayer() : Player(){} 
    
    //Returns the card to play
    int pCrd(Card, int);
    
    //Overrides base class getPcrd function
    //Plays a card with exception for bad input
    virtual Card getPcrd(Card &);
    
    //Input a wild color
    char chsWild();
    
    //Exception class
    class BadChc{
    private:
        int crdChc;         //Hold card choice
    public:
        BadChc(int chc){    //Constructor
            crdChc=chc;
        }
        int getChc() const{ //Returns card choice
            return crdChc;
        }
    };

    

};


#endif /* HPLAYER_H */

