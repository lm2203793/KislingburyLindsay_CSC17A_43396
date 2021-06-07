
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Type.h"
using namespace std;


class Player{
protected:
    int             plyrNum;    //Player Number
    vector<Card>    hand;      //Hand of Cards
    std::string     name;       //Player name
    bool            unoFlag;    //Uno status
    bool            winner;     //Win status

public:
    //Default Constructor
    Player(){}
    //Set Player Info
    void set(int num,std::string n){
        plyrNum=num;
        name=n;
        hand={};
        unoFlag=false;
        winner=false;
        
    }
    ~Player(){
        
    }
    
    void deal(Deck &deck){
        for(int i=0; i<7; i++){
            hand.push_back(deck.deck[i]);
        }
    }
    //Accessors
    vector<Card>getHnd(){
        return hand;
    }
    Card getCrd(int index){
        return hand.at(index);
    }
    string getName() const{
        return name;
    }
    int getNum() const{
        return plyrNum;
    }
    bool getUno(){
        return unoFlag;
    }
    int getHndSz(){
        return hand.size();
    }
    //Mutators
    void setUno(bool flag){
        unoFlag=flag;
    }
    void setWin(){
        winner=true;
    }
    
    void showCard(int);
    void recCrd(Deck &);  //receive card
    void showHnd();
    Card playChc(int index);
    Card playCard(int index);
    void unoStat(bool);
    bool cPlyStat(const Card &);
    //Friends
    //overloaded <<
  // friend ostream &operator << (ostream&, Player&);

};


#endif /* PLAYER_H */

