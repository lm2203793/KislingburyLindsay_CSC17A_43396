
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "Deck.h"
#include "Type.h"
using namespace std;

class Player{
private:
    int             plyrNum;    //Player Number
    vector<Card>    *hand;      //Hand of Cards
    string          name;
public:
    //Constructor
    Player(){

    }
    //Set Player Info
    void set(int num, vector<Card> *h, string n){
        plyrNum=num;
        hand=h;
        name=n;
    }
    //Accessors
    Card getCard(){
        return hand->at(0);
    }
    string getName() const{
        return name;
    }
    int getNum() const{
        return plyrNum;
    }
};


#endif /* PLAYER_H */

