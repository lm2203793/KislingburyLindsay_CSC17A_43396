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

//Receive a card from the draw pile
void Player::recCrd(Card add){
    Card temp;
    temp=add;
    //Add the card to player's hand
    hand.push_back(temp);
}
//Validate card just drawn when forced to play it
bool Player::valLstCrd(Card dis){
    bool temp;
    temp=valPlay(dis, hand.back());
    return temp;
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
//Get type of card in hand
Type Player::getType(int index){
       Type type;
       type=hand[index].getType();
       return type;
   }
//Get color of card in hand
char Player::getCol(int index){
        char c;
        c=hand[index].getColor();
        return c;
    }
//Get number of card in hand
int Player::getNum(int index){
        int num;
        num=hand[index].getNum();
        return num;
    }
//Play the card just drawn when forced to play
Card Player::playTop(){
    Card temp;
    temp=hand.back();
    hand.pop_back();
    return temp;
}
//Set player scores
void Player::setScr(){
        scr.win=winner;
        scr.nm=name;
        int largest=0;
        for(int i=0; i<hndSzs.size(); i++){
            if(hndSzs[i]>largest) largest=hndSzs[i];
        }
        scr.lrgHnd=largest;
    }
//Print player scores
void Player::prntScr(){
        if(scr.win)cout<<"Winner: ";
        else cout<<"Loser: ";
        cout<<scr.nm<<endl;
        cout<<scr.nm<<"' Largest hand: "<<scr.lrgHnd<<endl;
    }
    
//Validate card played
bool Player::valPlay(Card disCrd, Card pCard){ 
    //Temp variables store card info
    Type pType=pCard.getType();  //Hold player's card type
    Type dType=disCrd.getType();         //Hold discard card type
    char pCol=pCard.getColor();  //Hold player's card color
    char dCol=disCrd.getColor();         //Hold discard card color
    int  pNum=pCard.getNum();    //Hold player's card number
    int  dNum=disCrd.getNum();           //Hold discard card number 
    
    //Wild is always valid
    if(pType==WILD){//Wild is always valid
        return true;        //return true
    }
    if(pType==WILD4){//Wild4 is always valid
        return true;
    }
    //Number Card is played
    if(pType==NUMBER){
        // If card played matches discard color or number
        if(pCol==dCol||pNum==dNum){
            return true;    //return true
        }
        //Card played does not match discard color or number
        else return false;  //return false
    }
    //Special Card is played
    if(pType==SKIP||pType==REVERSE||pType==DRAW2){
        //If card played matches discard type or color
        if(pType==dType||pCol==dCol){
            return true;    //return true
        }
        //Card played does not match discard type or color
        return false;       //return false
    }
    return false;
}
