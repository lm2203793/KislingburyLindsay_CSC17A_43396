/* 
 * File:   Player.h
 * Author: Lindsay Kislingbury
 * Purpose: Player Class Specification
 * Created on June 3, 2021, 8:08 PM
 */
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>       //Vector Library
#include <string>       //String Library
#include "Deck.h"       //Deck Class
#include "Type.h"       //Type Enum
#include "GmScore.h"    //GmScore struct
using namespace std;

class Player{
protected:
    int             plyrNum;    //Player Number
    vector<Card>    hand;       //Hand of Cards
    string          name;       //Player name
    bool            unoFlag;    //Uno status
    bool            winner;     //Win status
    vector<int>     hndSzs;     //Array of hand sizes
    GmScore         scr;        //Hold game score

public:
    //Default Constructor
    Player(){}
    //Mutators
    //Set Player Info
    void set(int, string);
    //Deal 
    void deal(Deck &);
    //Play a card
    void playCard(int, Deck &);
    //Receive a card from the draw pile
    void recCrd(Card); 
    //Receive a card and validate it
    bool recCrdv(Card, Card);
    //Set uno status
    void setUno(bool flag){
        unoFlag=flag;
    }
    //Set win status
    void setWin(){
        winner=true;
    }
    //Play the card just drawn
    Card playTop();
    //Set Player's Scores
    void setScr();
    //Store hand size
    void setHnSz(){
        hndSzs.push_back(hand.size());
    }
    //Accessors
    //Get Player's hand
    vector<Card>getHnd(){
        return hand;
    }
    //Get a card from Player's hand
    Card getCrd(int index){
        return hand.at(index);
    }
    //Get Player's name
    string getName(){
        return name;
    }
    //Get Player's uno status
    bool getUno(){
        return unoFlag;
    }
    //Get Player's hand size
    int getHndSz(){
        return hand.size();
    }
    //Get type of card in player's hand
    Type getType(int);
    //Get color of card in player's hand
    char getCol(int);
    //Get number of card in player's hand
    int getNum(int);
    //Print player's hand
    void showHnd();
    //Get player's uno status
    void unoStat(bool);
    //Get player's can play status
    bool cPlyStat(Card &);
    //Get game score
    GmScore getScr(){
        return scr;
    }
    //Print game score
    void prntScr();
    
    //get turn
    virtual Card getPcrd(Card &)=0;
    
    //
    bool valPlay(Card,Card);
    
    bool valLstCrd(Card);
    
    void shoLstCrd(){
        cout<<hand.back();
    }
    
    
    
    
};


#endif /* PLAYER_H */

