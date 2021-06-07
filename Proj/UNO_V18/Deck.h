
#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
#include <iostream>
#include "Card.h"
using namespace std;
class Deck{
protected:
    vector<Card>  deck;     //Pointer to the deck of cards
    Card          discard;   //Discard
    vector<Card>  draw;      //Draw Pile
    int           drawSz;
public:
    //Default Constructor
    Deck(){
        drawSz=0;
        filDeck();
        shuffle();
        setDscrd();
    }
    friend class Player;
    //constructor
    Deck(Type, short, char, std::string, int);
    //fill the deck
    void filDeck();
    //shuffle the deck
    void shuffle();
    //set the discard
    void setDscrd();
    //fill draw pile
    void filDraw();
    //deal a hand
    void deal(vector<Card> &);
    //Take a card from draw pile
    Card drawCard();
    //Change discard
    void recDisc(Card);
    //Accessors
    Card& getDis(){
        return discard;
    }
    vector<Card> getDraw(){
        return draw;
    }
    int getSize(){
        return deck.size();
    }
    
    int getDrSz(){
        return draw.size();
    }
    void shoDraw(){
        cout<<"draw size:"<<draw.size();
        for(int i=0; i<draw.size(); i++){
            cout<<draw[i].getColor()<<endl;
        }
    }
    
    Type getDisT();
    char getdisC(){
        char c;
        c=discard.getColor();
        return c;
    }
    
    int getDiscN(){
        int num;
        num=discard.getNum();
        return num;
    }


    
    
};


#endif /* DECK_H */

