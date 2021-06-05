
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Type.h"
#include "GmScore.h"
using namespace std;


class Player{
protected:
    int             plyrNum;    //Player Number
    vector<Card>    hand;       //Hand of Cards
    string          name;    //Player name
    bool            unoFlag;    //Uno status
    bool            winner;     //Win status
    vector<int>     hndSzs;
    GmScore         scr;

public:
    //Default Constructor
    Player(){}
    //Set Player Info
    void set(int num, string nm){
        plyrNum=num;
        hand={};
        unoFlag=false;
        winner=false;
        name=nm;
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
    
    void setScr(){
        scr.win=winner;
        for(int i=0; i<4; i++) scr.nm[i]=name[i];
        int largest=0;
        for(int i=0; i<hndSzs.size(); i++){
            if(hndSzs[i]>largest) largest=hndSzs[i];
        }
        scr.lrgHnd=largest;
    }
    
    void setHnSz(){
        hndSzs.push_back(hand.size());
    }
    
    GmScore getScr(){
        return scr;
    }

    void prntScr(){
        if(scr.win)cout<<"Winner: ";
        else cout<<"Loser: ";
        cout<<scr.nm<<endl;
        cout<<scr.nm<<"' largest hand: "<<scr.lrgHnd<<endl;
    }

};


#endif /* PLAYER_H */

