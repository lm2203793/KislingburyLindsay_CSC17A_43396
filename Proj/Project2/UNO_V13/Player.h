
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
    
    void deal(Deck &deck){
        for(int i=0; i<7; i++){
           hand.push_back(deck.deck.back());
           deck.deck.pop_back();
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
    void playCard(int, Deck &);
    void unoStat(bool);
    bool cPlyStat(Card &);
    //Friends
    //overloaded <<
  // friend ostream &operator << (ostream&, Player&);
    
    
    Type getType(int index){
       Type type;
       type=hand[index].getType();
       return type;
   }
    char getCol(int index){
        char c;
        c=hand[index].getColor();
        return c;
    }
    
    int getNum(int index){
        int num;
        num=hand[index].getNum();
        return num;
    }
    
    void shoLcrd();
    
    void playIt(Deck &);

};


#endif /* PLAYER_H */

