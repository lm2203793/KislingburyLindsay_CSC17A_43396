/* 
 * File:   Player.h
 * Author: Lindsay Kislingbury
 * Purpose: Game Class Member Functions
 * Created on June 1, 2021, 9:01 PM
 */
#include "Card.h"
#include "Deck.h"
#include "Type.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Constructor
Deck::Deck(){
    filDeck;
    size=deck->size();
    shuffle();
}

//fill deck
vector<Card>*Deck::filDeck(){
    //Add Number Cards 
    //4 Zero Cards: 1 of each color
    deck->push_back(new Card(NUMBER,0,'r',"red",0));
    deck->push_back(new Card(NUMBER,0,'g',"green",0));
    deck->push_back(new Card(NUMBER,0,'b',"blue",0));
    deck->push_back(new Card(NUMBER,0,'y',"yellow",0));
    //One through Nine: 2 of each color per number
    for(short i=1; i<=9; i++){
        for(int j=0; j<2; j++) deck->push_back(new Card(NUMBER,i,'r',"red",i));
        for(int j=0; j<2; j++) deck->push_back(new Card(NUMBER,i,'g',"green",i));
        for(int j=0; j<2; j++) deck->push_back(new Card(NUMBER,i,'b',"blue",i));
        for(int j=0; j<2; j++) deck->push_back(new Card(NUMBER,i,'y',"yellow",i));
    }
    //Add Action Cards
    //Skip: 2 of each color
    for(int j=0; j<2; j++) deck->push_back(new Card(SKIP,-1,'r',"red",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(SKIP,-1,'g',"green",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(SKIP,-1,'b',"blue",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(SKIP,-1,'y',"yellow",20));
    //Reverse: 2 of each color
    for(int j=0; j<2; j++) deck->push_back(new Card(REVERSE,-2,'r',"red",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(REVERSE,-2,'g',"green",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(REVERSE,-2,'b',"blue",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(REVERSE,-2,'y',"yellow",20));
    //Draw Two: 2 of each color
    for(int j=0; j<2; j++) deck->push_back(new Card(DRAW2,-3,'r',"red",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(DRAW2,-3,'g',"green",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(DRAW2,-3,'b',"blue",20));
    for(int j=0; j<2; j++) deck->push_back(new Card(DRAW2,-3,'y',"yellow",20));
    //Wild: 4
    for(int j=0; j<4; j++) deck->push_back(new Card(WILD,-4,'X',"X",50));
    //Wild Draw Four: 4
    for(int j=0; j<4; j++) deck->push_back(new Card(WILD4,-5,'X',"X",50));

}

//Shuffle the deck of card pointers
void Deck::shuffle(){
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Shuffle Cards
    for(int i=0; i<size-1; i++) {
        int j=i+rand()%(size-i);
        swap(deck[i], deck[j]);
   }
}

//Discard
void Deck::setDscrd(){
    //Flip last card over to start discard pile
    int counter=1;  //Counter for index of card to swap 
    if(deck->back().getType()!=NUMBER){ //If the last card is a special card
        //Continue swapping last card with the one above it until last 
        //card is not a special card
        while(deck->at(size).getType()!=NUMBER){ 
            swap(deck->at(size),deck[size-counter]);      
            counter++;
        }
    }
    discard=deck->back();     //Flip the last card over to start discard pile
    deck->pop_back();            //Remove that card from the deck
}
//Fill the draw pile
void Deck::filDraw(){
    for(int i=0; i<size; i++)
        draw->push_back(deck[i]);
    //Remove cards added to the draw pile from the deck
    for(int i=0; i<draw.size(); i++)
        deck->pop_back();
}

//deal
vector<Card>*Deck::deal(){
//Allocate memory for array of player hands
    vector<Card> *hand=new vector<Card>;
    //Deal player the last 7 cards in the shuffled deck
        for(int i=size-1; i>deck.size()-8; i--)
            hand.push_back(deck[i]);
        //Remove those cards from the deck
        for(int i=0; i<7; i++)
            deck.pop_back();
    //Return pointer to array of player hands
    return hand;
}



