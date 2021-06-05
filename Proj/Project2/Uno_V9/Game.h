/* 
 * File:   Game.h
 * Author: Lindsay Kislingbury
 * Purpose: Game Class Specification
 * Created on June 1, 2021, 9:36 PM
 */

#ifndef GAME_H
#define GAME_H
#include "Card.h"
#include "Player.h"
#include<vector>
enum Type{NUMBER,SKIP,REVERSE,
            DRAW2,WILD,WILD4};       //Card Types
class Game{
private:
    vector<Card>    *deck;      //Pointer to the deck of Cards
    vector<Card>    *draw;      //Pointer to the draw Pile
    Card             discard;   //Discard Pile
    int              players;   //Number of Players
    vector<Card>     *handPtr;  //Pointer to Current Player's hand
    int              curPlyr;   //Current player
    int              cardChc;   //Card choice
public:
    //Constructor
    Game(){
        deck=filDeck();
    }
    //Fill Deck
    vector<Card> *filDeck();    //Fill The Deck
    
    //Shuffle
    void shuffle(vector<Card> &deck, Card &discard);
};


#endif /* GAME_H */

