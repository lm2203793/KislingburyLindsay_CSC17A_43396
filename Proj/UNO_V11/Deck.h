/* 
 * File:   Player.h
 * Author: Lindsay Kislingbury
 * Purpose: Deck Class Specification
 * Created on June 1, 2021, 9:01 PM
 */

#ifndef DECK_H
#define DECK_H
#include "Type.h"
#include "Card.h"
#include <vector>
using namespace std;


class Deck{
private:
private:
    vector<Card>    deck;
    Card            discard;
public:
    //Constructor
    Deck(){
        filDeck();
    }
    //Fill deck
    vector<Card> filDeck();

    
    //Mutators
    void shuffle();
    
};



#endif /* DECK_H */

