
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include "Card.h"
#include "Type.h"
using namespace std;

//class Player;   //Forward Declaration for overloaded <<
//Function Prototype for overloaded <<
//ostream &operator <<(ostream&,Player&);

class Player{
protected:
    int             plyrNum;    //Player Number
    string          name;       //Player name
    bool            unoFlag;    //Uno status
    bool            cPlay;      //Can play status
    bool            winner;     //Win status
public:
    //Default Constructor
    Player(){
        unoFlag=false;
        cPlay=false;
        winner=false;
    }
    //Set Player Info
    void set(int num, string n){
        plyrNum=num;
        name=n;
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
    bool getCply(){
        return cPlay;
    }
    //Mutators
    void setUno(bool flag){
        unoFlag=flag;
    }
    void setWin(){
        winner=true;
    }
    
    void showCard(int);
    void RecCrd(Card);  //receive card
    void showHnd();
    Card playChc(int index);
    Card playCard(int index);
    void unoStat(vector<Card>);
    void cPlyStat(vector<Card>,const Card);
    //Friends
    //overloaded <<
  // friend ostream &operator << (ostream&, Player&);

};


#endif /* PLAYER_H */

