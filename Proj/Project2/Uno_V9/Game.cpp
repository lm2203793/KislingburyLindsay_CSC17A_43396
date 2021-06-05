/* 
 * File:   Player.h
 * Author: Lindsay Kislingbury
 * Purpose: Game Class Member Functions
 * Created on June 1, 2021, 9:01 PM
 */
#include "Card.h"
#include "Game.h"
#include <vector>
using namespace std;

//FILL DECK
vector<Card>Game:: *filDeck(){
    vector<Card> *deck=new vector<Card>;
    
   
    //Add Number Cards 
    //4 Zero Cards: 1 of each color
    deck->push_back({NUMBER,0,'r',"red",0});
    deck->push_back({NUMBER,0,'g',"green",0});
    deck->push_back({NUMBER,0,'b',"blue",0});
    deck->push_back({NUMBER,0,'y',"yellow",0});
    //One through Nine: 2 of each color per number
    for(short i=1; i<=9; i++){
        for(int j=0; j<2; j++) deck->push_back({NUMBER,i,'r',"red",i});
        for(int j=0; j<2; j++) deck->push_back({NUMBER,i,'g',"green",i});
        for(int j=0; j<2; j++) deck->push_back({NUMBER,i,'b',"blue",i});
        for(int j=0; j<2; j++) deck->push_back({NUMBER,i,'y',"yellow",i});
    }
    //Add Action Cards
    //Skip: 2 of each color
    for(int j=0; j<2; j++) deck->push_back({SKIP,-1,'r',"red",20});
    for(int j=0; j<2; j++) deck->push_back({SKIP,-1,'g',"green",20});
    for(int j=0; j<2; j++) deck->push_back({SKIP,-1,'b',"blue",20});
    for(int j=0; j<2; j++) deck->push_back({SKIP,-1,'y',"yellow",20});
    //Reverse: 2 of each color
    for(int j=0; j<2; j++) deck->push_back({REVERSE,-2,'r',"red",20});
    for(int j=0; j<2; j++) deck->push_back({REVERSE,-2,'g',"green",20});
    for(int j=0; j<2; j++) deck->push_back({REVERSE,-2,'b',"blue",20});
    for(int j=0; j<2; j++) deck->push_back({REVERSE,-2,'y',"yellow",20});
    //Draw Two: 2 of each color
    for(int j=0; j<2; j++) deck->push_back({DRAW2,-3,'r',"red",20});
    for(int j=0; j<2; j++) deck->push_back({DRAW2,-3,'g',"green",20});
    for(int j=0; j<2; j++) deck->push_back({DRAW2,-3,'b',"blue",20});
    for(int j=0; j<2; j++) deck->push_back({DRAW2,-3,'y',"yellow",20});
    //Wild: 4
    for(int j=0; j<4; j++) deck->push_back({WILD,-4,'X',"X",50});
    //Wild Draw Four: 4
    for(int j=0; j<4; j++) deck->push_back({WILD4,-5,'X',"X",50});
    
    //Return filled deck
    return deck;
}

//SHUFFLE AND CREATE DISCARD PILE
void Game::shuffle(vector<Card> &deck, Card &discard){
    //Shuffle Cards
    int size=deck->size();
    for(int i=0; i<size; i++) {
      int j=i+rand()%(size-i);
      swap(deck[i], deck[j]);
   }
    //Flip last card over to start discard pile
    size--;
    int counter=1;  //Counter for index of card to swap 
    if(deck->back().type!=NUMBER){ //If the last card is a special card
        //Continue swapping last card with the one above it until last 
        //card is not a special card
        while(deck[size].type!=NUMBER){ 
            swap(deck[size],deck[size-counter]);      
            counter++;
        }
    }
    discard=deck->back();  //Flip the last card over to start discard pile
    deck->pop_back();      //Remove that card from the deck
}