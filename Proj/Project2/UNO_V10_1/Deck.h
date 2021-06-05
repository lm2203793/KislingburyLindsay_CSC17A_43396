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
    vector<Card>    *deck;
    vector<Card>    *filDeck();
    vector<Card>    *deal(); 
    int             size;
protected:
    Card            discard;
    vector<Card>    draw;
public:
    //Constructor
    Deck();
    //Destructor
    ~Deck();

    void shuffle();
    void setDscrd();
    void filDraw();
};



#endif /* DECK_H */

