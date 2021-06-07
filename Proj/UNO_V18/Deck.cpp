
#include <vector>
#include <iostream>
#include <ctime>
#include "Deck.h"
#include "Type.h"


//fill the deck
void Deck::filDeck(){
    deck.push_back(Card(NUMBER,0,'r',0));
    deck.push_back(Card(NUMBER,0,'g',0));
    deck.push_back(Card(NUMBER,0,'b',0));
    deck.push_back(Card(NUMBER,0,'y',0));
    //One through Nine: 2 of each color per number
    for(short i=1; i<=2; i++){
        for(int j=0; j<9; j++){
            deck.push_back(Card(NUMBER,j,'r',j));
            deck.push_back(Card(NUMBER,j,'g',j));
            deck.push_back(Card(NUMBER,j,'b',j));
            deck.push_back(Card(NUMBER,j,'y',j));
        }
    }
    //Add Action Cards
    //Skip: 2 of each color
    for(int j=0; j<2; j++){
        deck.push_back(Card(SKIP,-1,'r',20));
        deck.push_back(Card(SKIP,-1,'g',20));
        deck.push_back(Card(SKIP,-1,'b',20));
        deck.push_back(Card(SKIP,-1,'y',20));
    }
    //Reverse: 2 of each color
    for(int j=0; j<2; j++){
        deck.push_back(Card(REVERSE,-2,'r',20));
        deck.push_back(Card(REVERSE,-2,'g',20));
        deck.push_back(Card(REVERSE,-2,'b',20));
        deck.push_back(Card(REVERSE,-2,'y',20));
    }
    //Draw Two: 2 of each color
    for(int j=0; j<2; j++){
        deck.push_back(Card(DRAW2,-3,'r',20));
        deck.push_back(Card(DRAW2,-3,'g',20));
        deck.push_back(Card(DRAW2,-3,'b',20));
        deck.push_back(Card(DRAW2,-3,'y',20));
    }
    //Set Color for all Card except WILD types
    for(int i=0; i<deck.size(); i++){
        deck[i].setColor(deck[i].getColor());
    }
    //Wild: 4
    for(int j=0; j<4; j++) deck.push_back(Card(WILD,-4,'X',50));
    //Wild Draw Four: 4
    for(int j=0; j<4; j++) deck.push_back(Card(WILD4,-5,'X',50));
    
}
//shuffle the deck
void Deck::shuffle(){
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0; i<deck.size()-1; i++) {
        int j=i+rand()%(deck.size()-i);
        swap(deck[i], deck[j]);
   }
}
//Discard
void Deck::setDscrd(){
    //Flip last card over to start discard pile
    int counter=1;  //Counter for index of card to swap 
    if(deck.back().getType()!=NUMBER){ //If the last card is a special card
        //Continue swapping last card with the one above it until last 
        //card is not a special card
        while(deck.back().getType()!=NUMBER){ 
            swap(deck[deck.size()],deck[deck.size()-counter]);      
            counter++;
        }
    }
    discard=deck.back();     //Flip the last card over to start discard pile
    deck.pop_back();         //Remove that card from the deck
}
//fill draw pile
void Deck::filDraw(){
    for(int i=0; i<deck.size(); i++)
        draw.push_back(deck[i]);
    //Remove cards added to the draw pile from the deck
    for(int i=0; i<draw.size(); i++)
        deck.pop_back();
}
//deal a hand
void Deck::deal(vector<Card> &hand){
    for(int i=0; i<7; i++){
        hand.push_back(deck[i]);
    }
    //remove those cards from the deck
    for(int i=0; i<7; i++){
        deck.pop_back();
    }
}

Type Deck::getDisT(){
    Type type;
    discard.getType();
    return type;
}


