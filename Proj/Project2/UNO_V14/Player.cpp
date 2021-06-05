/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Player.h"
#include "Type.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Determine Uno Status
void Player::unoStat(vector<Card> hand){
    if(hand.size()==2){    //If player has two cards
        if(cPlay)         //If player has a playable card
            unoFlag=true;   //Set UNO flag to true
        else                //If player doesn't have a playable card
            unoFlag=false;  //Set UNO flag to false
    }
    else                    //If player doesn't have two cards
        unoFlag=false;      //Set UNO flag to false
}

//Determine can play status
void Player::cPlyStat(vector<Card> hand, const Card discard){
    //Loop on size of player's hand
    for(int i=0; i<hand.size(); i++){
        //Check Number Cards
        if(hand[i].getType()==NUMBER){
            //If player has a card with the same color or number
            if(hand[i].getColor()==discard.getColor()
                    ||hand[i].getNum()==discard.getNum()){
cout<<"if "<<hand[i].getColor()<<" matches "<<discard.getColor()<<" or "<<hand[i].getNum()<<" matches "<<discard.getNum()<<endl;
                cPlay=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
        //Check Special Cards
        if(hand[i].getType()!=NUMBER){
            if(hand[i].getColor()==discard.getColor()
                    ||hand[i].getType()==discard.getType()){
cout<<"if "<<hand[i].getColor()<<" matches "<<discard.getColor()<<" or "<<hand[i].getType()<<" matches "<<discard.getType()<<endl;
                cPlay=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
        if(hand[i].getType()==WILD||hand[i].getType()==WILD4){
            cPlay=true;
            break;
        }
    }
}

