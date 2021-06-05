/* 
 * File:   Player.h
 * Author: linds
 *
 * Created on June 2, 2021, 6:26 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"

class Player{
private:
    int          plyrNum;
    vector<Card> *hand;
public:
    //constructor
    Player(int num, vector<Card> *h){
        plyrNum=num;
        hand=h;
    }
    //accessors
    Card getCard(int index){
        return hand->at(index);
    }
    string getName() const{
        return name;
    }
    int getNum() const{
        return plyrNum;
    }
    //destructor
    ~Player(){
        delete hand;
    }
    
    
};


#endif /* PLAYER_H */

