/* 
 * File:   Player.cpp
 * Author: Lindsay Kislingbury
 * Purpose: Player Class Member Functions
 * Created on June 2, 2021, 8:08 PM
 */
#include <iostream> //I/O Library
#include <string>   //String Library
#include <iomanip>  //Format Library
#include "Player.h" //Player class
#include "Type.h"   //Type enum
#include "Deck.h"   //Deck class
using namespace std;

//Set player info
void Player::set(int num, string nm){
        plyrNum=num;
        hand={};
        unoFlag=false;
        winner=false;
        name=nm;
    }
//Deal player hands
void Player::deal(Deck &deck){
        for(int i=0; i<7; i++){
           hand.push_back(deck.deck.back());
           deck.deck.pop_back();
        }
    }
//Receive a card from the draw pile
void Player::recCrd(Deck &deck){
    Card add;
    add=deck.draw.back();
    //Add the card to player's hand
    hand.push_back(add);
    deck.draw.pop_back(); //remove the card from draw pile
}


//Show Player's hand
void Player::showHnd(){
    for(int i=0; i<hand.size(); i++){//Loop on Player's hand size
        cout<<right;
        cout<<setw(3)<<i<<setw(2)<<": ";
        cout<<left;
        cout<<hand[i];
        if((i+1)%2==0)cout<<endl;
    }
    cout<<endl;
}

//Play a card
void Player::playCard(int index, Deck &deck){
    Card card=hand[index];  //hold the card chosen
    //Take Played Card Out of Player's Hand
    hand.erase(hand.begin()+index);
    deck.discard=card;
}
//Determine Uno Status
void Player::unoStat(bool canPlay){
    if(hand.size()==2){    //If player has two cards
        if(canPlay)         //If player has a playable card
            unoFlag=true;   //Set UNO flag to true
        else                //If player doesn't have a playable card
            unoFlag=false;  //Set UNO flag to false
    }
    else                    //If player doesn't have two cards
        unoFlag=false;      //Set UNO flag to false
}

//Determine can play status
bool Player::cPlyStat(Card &discard){
    //Loop on size of player's hand
    for(int i=0; i<hand.size(); i++){
        //Check Number Cards
        if(hand[i].getType()==NUMBER){
            //If player has a card with the same color or number
            if(hand[i].getColor()==discard.getColor()
                    ||hand[i].getNum()==discard.getNum()){
                return true;
            }
        }
        //Check Special Cards
        if(hand[i].getType()!=NUMBER){
            if(hand[i].getColor()==discard.getColor()
                    ||hand[i].getType()==discard.getType()){
                return true;
            }
        }
        if(hand[i].getType()==WILD||hand[i].getType()==WILD4){
            return true;
        }
    }
}
Type Player::getType(int index){
       Type type;
       type=hand[index].getType();
       return type;
   }
char Player::getCol(int index){
        char c;
        c=hand[index].getColor();
        return c;
    }
int Player::getNum(int index){
        int num;
        num=hand[index].getNum();
        return num;
    }

void Player::playIt(Deck &deck){
    Card card=hand.back();  //hold the card chosen
    //Take Played Card Out of Player's Hand
    hand.pop_back();
    deck.discard=card;
}

void Player::setScr(){
        scr.win=winner;
        for(int i=0; i<4; i++) scr.nm[i]=name[i];
        int largest=0;
        for(int i=0; i<hndSzs.size(); i++){
            if(hndSzs[i]>largest) largest=hndSzs[i];
        }
        scr.lrgHnd=largest;
    }
void Player::prntScr(){
        if(scr.win)cout<<"Winner: ";
        else cout<<"Loser: ";
        cout<<scr.nm<<endl;
        cout<<scr.nm<<"' Largest hand: "<<scr.lrgHnd<<endl;
    }
