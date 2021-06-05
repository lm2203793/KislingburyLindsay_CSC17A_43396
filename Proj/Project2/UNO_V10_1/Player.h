/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: linds
 *
 * Created on June 2, 2021, 4:01 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "Type.h"

class Player{
private:
    vector<Card>    *hand;
public:
    //Constructor
    Player(vector<Card> *cards){
        hand=cards;
    }
};


#endif /* PLAYER_H */

