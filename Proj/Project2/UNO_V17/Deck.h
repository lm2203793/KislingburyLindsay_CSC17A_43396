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
    vector<Card>  deck;     //Pointer to the deck of cards
    Card          discard;   //Discard
    vector<Card>  draw;      //Draw Pile
    int           drawSz;    //Size of the draw pile
public:
    //Default Constructor
    Deck(){
        drawSz=0;
        filDeck();
        shuffle();
        setDscrd();
    }
    //Declare friend class
    friend class Player;
    //fill the deck
    void filDeck();
    //shuffle the deck
    void shuffle();
    //set the discard
    void setDscrd();
    //fill draw pile
    void filDraw();
    //deal a hand
    void deal(vector<Card> &);
    //Take a card from draw pile
    Card drawCard();
    //Change discard
    void recDisc(Card);
    //Accessors
    Card& getDis(){
        return discard;
    }
    //Get draw pile size
    int getDrSz(){
        return draw.size();
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

