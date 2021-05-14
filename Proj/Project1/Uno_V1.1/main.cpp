/* 
 * File:   main.cpp
 * Author: linds
 * Purpose: UNO VERSION 1
 * Created on May 4, 2021, 11:28 AM
 */

#include <cstdlib>  //C Standard Library
#include <iostream> //I/O Library
#include <iomanip>  //Format Library
#include <vector>   //Vector Library
#include <ctime>    //Time Library
#include "Card.h"   //Card Structure

using namespace std;


//Function Prototypes
void filDeck(vector<Card> &);
void shuffle(vector<Card> &);
vector<Card> deal(vector<Card> &);
void setup(vector<Card> &, vector<Card> &, vector<Card> &,Card &);
void display(Card, vector<Card> p1Hand);
void choose(vector<Card> &, Card &);

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Variable Declaration
    vector<Card> p1Hand;    //Player One's hand
    vector<Card> p2Hand;    //Player Two's hand
    vector<Card> draw;      //Draw Pile
    Card discard;   //Discard Pile
    
    bool endgame;
    
    //Setup Game
    //Shuffle deck, deal two hands, create discard and draw pile
    setup(p1Hand, p2Hand, draw, discard);
    
    do{
        //Display discard pile and player hand
        display(discard, p1Hand);
        
        //Player chooses a card to play
        choose(p1Hand, discard);
        
        //end
        if(p1Hand.size()==0)
            endgame=true;
        
    }while(!endgame);


    return 0;
}
//Function Definitions

/*****************************************************************************/
/*                               SETUP                                       */
//setup
void setup(vector<Card>&p1Hand, vector<Card>&p2Hand, vector<Card>&draw,
        Card &discard){
    //Declare Variables
    vector<Card> deck; //To Hold the Entire Deck of Cards
    
    //Fill the deck
    filDeck(deck);
    
    //Shuffle the deck
    shuffle(deck);

    //Deal two hands
    p1Hand=deal(deck);
    p2Hand=deal(deck);

    //Create Draw and Discard Pile
    //Flip the first card from the deck over to start discard pile
    discard=(deck[0]);

    //Remove that card from the deck
    deck.pop_back();
    
    //Fill the draw pile with the remaining cards
    for(int i=0; i<deck.size(); i++){
        draw.push_back(deck[i]);
    }

    //Remove those cards from the deck
    for(int i=0; i<draw.size(); i++){
        deck.pop_back();
    }
}


//Fill Deck
void filDeck(vector<Card> &deck){
    //Initialize deck
    
    //Four zero cards 
    deck.push_back({0,'r'});
    deck.push_back({0,'g'});
    deck.push_back({0,'b'});
    deck.push_back({0,'y'});
    //One through Nine
    for(unsigned short i=1; i<=9; i++){
        for(int j=0; j<2; j++) deck.push_back({i,'r'});
        for(int j=0; j<2; j++) deck.push_back({i,'g'});
        for(int j=0; j<2; j++) deck.push_back({i,'b'});
        for(int j=0; j<2; j++) deck.push_back({i,'y'});
    }
}

//shuffle
void shuffle(vector<Card> &deck){
    int size=deck.size();
    for(int i=0; i<size-1; i++) {
      int j=i+rand()%(size-i);
      swap(deck[i], deck[j]);
   }
}

//deal two hands
vector<Card> deal(vector<Card> &deck){
    vector<Card> hand;
    
    //Deal player the last 7 cards in the shuffled deck
    for(int i=deck.size()-1; i>deck.size()-8; i--) hand.push_back(deck[i]);
    
    //Remove the cards just drawn from the deck
    for(int i=0; i<7; i++) deck.pop_back();

    return hand;
}

/*****************************************************************************/
/*                               DISPLAY                                      */
void display(Card discard, vector<Card> p1Hand){
    //Show Discard 
    cout<<"Discard:"<<endl;
    cout<<discard.num<<" "<<discard.color<<endl;
    
    //Show Your Hand
    cout<<"Your Hand:"<<endl;
    for(int i=0; i<p1Hand.size(); i++){
        cout<<i<<": "<<p1Hand[i].num<<p1Hand[i].color<<"\t";
    }
}

/*****************************************************************************/
/*                               CHOOSE                                      */
void choose(vector<Card> &p1Hand, Card &discard){
    int choice;
    bool valid;
    
    //ask player what card they want to play
    cout<<"\nWhat card do you want to play?"<<endl;
    cin>>choice;
    
    //check if the play is valid
    if(p1Hand[choice].color==discard.color||p1Hand[choice].num==discard.num)
        valid=true; 
    else valid=false;
    
    cout<<"play is ";
    if(valid==true)cout<<"valid"<<endl;
    else cout<<"not valid"<<endl;
    
    //put players card on top of discard pile
    discard=p1Hand[choice];
    
    //take that card out of players hand
    p1Hand.erase(p1Hand.begin()+choice);
            
}





