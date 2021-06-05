
#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"
using namespace std;

class Deck{
protected:
    vector<Card>  deck;     //Deck of cards
    Card          discard;   //Discard
    vector<Card>  draw;      //Draw Pile
    vector<Card>  *hands;    //array of hands
public:
    //constructor
    Deck(int);
    //Destructor
    ~Deck(){
        delete []hands;
    }
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
    void drawCard(int);
    //Change discard
    void chngDscrd(Card);
    //Accessors
    Card getDis(){
        return discard;
    }
    vector<Card> getDraw(){
        return draw;
    }
    int getSize(){
        return deck.size();
    }
    
    Card getCrd(int curPlyr, int index){
        return hands[curPlyr][index];
    }
    
    vector<Card> getHnd(int plyr){
        return hands[plyr];
    }

    int getHndSz(int plyr){
        return hands[plyr].size();
    }
    
    void showCard(int, int);
    
    void showHnd(int);
    
    Card playCard(int, int);
    
    void chngDscrd(char c){
        discard.setColor(c);
    }



    
    
};


#endif /* DECK_H */

