/* 
 * File:   Deck.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Deck Class Member Functions
 * Created on June 2, 2021, 8:08 PM
 */
#include <vector>   //Vector Library
#include <ctime>    //Time Library
#include "Deck.h"   //Deck Class
#include "Type.h"   //Type enum

//Fill the deck
void Deck::filCrds(){
    cards.push_back(Card(NUMBER,0,'r',0));
    cards.push_back(Card(NUMBER,0,'g',0));
    cards.push_back(Card(NUMBER,0,'b',0));
    cards.push_back(Card(NUMBER,0,'y',0));
    //One through Nine: 2 of each color per number
    for(short i=1; i<=2; i++){
        for(int j=0; j<9; j++){
            cards.push_back(Card(NUMBER,j,'r',j));
            cards.push_back(Card(NUMBER,j,'g',j));
            cards.push_back(Card(NUMBER,j,'b',j));
            cards.push_back(Card(NUMBER,j,'y',j));
        }
    }
    //Add Action Cards
    //Skip: 2 of each color
    for(int j=0; j<2; j++){
        cards.push_back(Card(SKIP,-1,'r',20));
        cards.push_back(Card(SKIP,-1,'g',20));
        cards.push_back(Card(SKIP,-1,'b',20));
        cards.push_back(Card(SKIP,-1,'y',20));
    }
    //Reverse: 2 of each color
    for(int j=0; j<2; j++){
        cards.push_back(Card(REVERSE,-2,'r',20));
        cards.push_back(Card(REVERSE,-2,'g',20));
        cards.push_back(Card(REVERSE,-2,'b',20));
        cards.push_back(Card(REVERSE,-2,'y',20));
    }
    //Draw Two: 2 of each color
    for(int j=0; j<2; j++){
        cards.push_back(Card(DRAW2,-3,'r',20));
        cards.push_back(Card(DRAW2,-3,'g',20));
        cards.push_back(Card(DRAW2,-3,'b',20));
        cards.push_back(Card(DRAW2,-3,'y',20));
    }
    //Set Color for all Card except WILD types
    for(int i=0; i<cards.size(); i++){
        cards[i].setColor(cards[i].getColor());
    }
    //Wild: 4
    for(int j=0; j<4; j++) cards.push_back(Card(WILD,-4,'X',50));
    //Wild Draw Four: 4
    for(int j=0; j<4; j++) cards.push_back(Card(WILD4,-5,'X',50));   
}

//shuffle the deck
void Deck::shuffle(){
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //shuffle deck by swapping cards
    for(int i=0; i<cards.size()-1; i++) {
        int j=i+rand()%(cards.size()-i);
        swap(cards[i], cards[j]);
   }
}
//Set the discard
void Deck::setDscrd(){
    //Flip last card over to start discard pile
    int counter=1;  //Counter for index of card to swap 
    if(cards.back().getType()!=NUMBER){ //If the last card is a special card
        //Continue swapping last card with the one above it until last 
        //card is not a special card
        while(cards.back().getType()!=NUMBER){ 
            swap(cards[cards.size()],cards[cards.size()-counter]);      
            counter++;
        }
    }
    discard=cards.back();     //Flip the last card over to start discard pile
    cards.pop_back();         //Remove that card from the deck
}


Card Deck::dealCrds(){
    Card temp;
    if(cards.size()==0){ //refill cards
        reFill();
    }
    temp=cards.back();  
    cards.pop_back();
    return temp;
}
//change the discard
void Deck::chngDisc(Card card){
    Card temp=card;
    dPile.push_back(discard);
    discard=temp;
}


void Deck::reFill(){
    while(dPile.size()>0){
        cards.push_back(dPile.back());
        dPile.pop_back();
    }
    shuffle();
}


