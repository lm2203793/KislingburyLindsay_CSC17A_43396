/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: linds
 *
 * Created on June 2, 2021, 8:08 PM
 */

#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"
using namespace std;

class Deck{
private:
    vector<Card> *deck;     //Pointer to the deck of cards
    Card         discard;   //Discard
    vector<Card> draw;      //Draw Pile
public:
    //constructor
    Deck();
    //Destructor
    ~Deck(){
      delete deck;  
    }
    //fill the deck
    vector<Card> *filDeck();
    //shuffle the deck
    void shuffle();
    //set the discard
    void setDscrd();
    //fill draw pile
    void filDraw();
    //deal a hand
    vector<Card> *deal();
    
    
};


#endif /* DECK_H */

