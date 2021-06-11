/* 
 * File:   Deck.h
 * Author: Lindsay Kislingbury
 * Purpose: Deck Class Specification
 * Created on June 3, 2021, 8:08 PM
 */
#ifndef DECK_H
#define DECK_H
#include <vector>   //Vector Library
#include <string>   //String Library
#include <iostream> //I/O Library
#include "Card.h"   //Card Class
using namespace std;

class Deck{
protected:
    vector<Card>  cards;     //Pointer to the deck of cards
    Card          discard;   //Discard
    vector<Card>  dPile;     //Discard Pile
public:
    //Default Constructor
    Deck(){
        filCrds();
        shuffle();
    }
    //Fill the deck
    void filCrds();
    //Shuffle the deck
    void shuffle();
    //Set the discard
    void setDscrd();
    //Deal a card
    Card dealCrds();
    //Take a card from draw pile
    Card drawCard();
    //Change discard
    void chngDisc(Card);
    //Fill discard pile
    void reFill();
    //Get discard
    Card& getDis(){
        return discard;
    }
    //Get Discard type
    Type getDisT(){
        Type type;
        discard.getType();
        return type;
    }
    //Get Discard color
    char getdisC(){
        char c;
        c=discard.getColor();
        return c;
    }
    //Get Discard number
    int getDiscN(){
        int num;
        num=discard.getNum();
        return num;
    }
};
#endif /* DECK_H */

