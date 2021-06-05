/* 
 * File:   Game.h
 * Author: Lindsay Kislingbury
 * Purpose: Game Class Specification
 * Created on June 1, 2021, 9:36 PM
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <iostream>
using namespace std;

class Deck{
private:
    vector<Card>    deck;
    Card            discard;
    vector<Card>    draw;
    void            filDeck();
    int             size;
 
public:
    //Constructor
    Deck();
    //Destructor
    ~Deck();
    void filDraw();
    void shuffle();
    void setDscrd();
    void print(){
        for(int i=0; i<deck.size(); i++){
            cout<<i<<": "<<deck[i].getColor()<<deck[i].getType()<<" "<<deck[i].getNum()<<" "<<endl;
        }
    }
    vector<Card>    *deal();
};   



#endif /* DECK_H */

