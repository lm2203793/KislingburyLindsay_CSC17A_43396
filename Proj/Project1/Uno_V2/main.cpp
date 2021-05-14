/* 
 * File:   main.cpp
 * Author: linds
 * Purpose: UNO VERSION 2: Added array of hands and two players
 *                         Still only number cards, no special cards
 *                         Play, Draw, Discard all working correctly
 * Created on May 6, 2021 10:15AM
 */

#include <cstdlib>  //C Standard Library
#include <iostream> //I/O Library
#include <iomanip>  //Format Library
#include <vector>   //Vector Library
#include <ctime>    //Time Library

using namespace std;

enum Type{NUMBER,SKIP,REVERSE,DRAW,WILD,WILD4}; //Card Types

#include "Card.h"
#include "Hands.h"   //Card Structure

//Function Prototypes
//Game Setup:
Hands *setup(vector<Card>&, Card &, int, Hands *);
void filDeck(vector<Card> &);
void shuffle(vector<Card> &);
vector<Card> *deal(vector<Card> &);
//Play:
void turn(vector<Card> &, Card &, vector<Card> &, int);
void drawCrd(vector<Card> &, vector<Card> &);
void playCrd(vector<Card> &, Card &, vector<Card> &);
void display(Card, vector<Card> p1Hand);
void play(Hands *, vector<Card> &, Card &, int &);


int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Variable Declaration
    Hands *hands;           //Pointer to an array of player hand vectors
    vector<Card> draw;      //Draw Pile
    Card discard;           //Discard Pile
    int players;            //Number of players


    //Play Game
    play(hands, draw, discard, players);


    return 0;
}
//Function Definitions

/*****************************************************************************/
/*                               SETUP                                       */
//SETUP MAIN
Hands *setup(vector<Card>&draw, Card &discard, int players, Hands *hands){
    //Declare Variables
    vector<Card> deck; //To Hold the Entire Deck of Cards
    
    //Fill the deck
    filDeck(deck);
    
    //Shuffle the deck
    shuffle(deck);

    //Deal two hands
    //Allocate memory for array of player hands
    Hands *hand=new Hands[players];
 
    //Fill player hands
    for(int i=0; i<players; i++){
        hand[i].player=i;
        
    //Deal player the last 7 cards in the shuffled deck
    for(int j=deck.size()-1; j>deck.size()-8; j--){
        hand[i].data.push_back(deck[j]);
    }
    
    //Remove the cards just drawn from the deck
    for(int i=0; i<7; i++) deck.pop_back();
    }
    
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
    return hand;
}

//FILL DECK
void filDeck(vector<Card> &deck){
    //Four zero cards 
    deck.push_back({NUMBER,0,'r'});
    deck.push_back({NUMBER,0,'g'});
    deck.push_back({NUMBER,0,'b'});
    deck.push_back({NUMBER,0,'y'});
    //One through Nine
    for(unsigned short i=1; i<=9; i++){
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'r'});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'g'});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'b'});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'y'});
    }
}

//SHUFFLE
void shuffle(vector<Card> &deck){
    int size=deck.size();
    for(int i=0; i<size-1; i++) {
      int j=i+rand()%(size-i);
      swap(deck[i], deck[j]);
   }
}

//DEAL HANDS
vector<Card> *deal(vector<Card> &deck){
    vector<Card> *hand=new vector<Card>;
    
    //Deal player the last 7 cards in the shuffled deck
    for(int i=deck.size()-1; i>deck.size()-8; i--) hand->push_back(deck[i]);
    
    //Remove the cards just drawn from the deck
    for(int i=0; i<7; i++) deck.pop_back();

    return hand;
}

/*****************************************************************************/
/*                                  TURN                                      */
//TURN MAIN
void turn(vector<Card> &hand, Card &discard, vector<Card> &draw, int players){
    char choice;            //Choice to play a card or draw
    char yesNo;             //Choice to play a card after drawing
    bool error=false;       //Input validation
    
        //Display discard pile and player hand
        display(discard, hand);
        
        //Ask if player wants to play a card or draw
        do{
            cout<<"1: Play a Card\t2: Draw"<<endl;
            cin>>choice;
            //if player enters invalid choice, error message
            if(choice=='1'||choice=='2'){ 
                error=false;
            }
            else{
               cout<<"Invalid Choice. Your Choices:"<<endl;
               error=true;
            }
        }while(error);
        
        //Play a card or draw
        switch(choice){
            case '1': //Play a Card
                    playCrd(hand, discard, draw);
                break;
            case '2': //Draw A Card
                drawCrd(hand, draw);
                cout<<"You drew: ";
                cout<<hand.back().num;
                cout<<hand.back().color<<endl;
                //If they can play the card they just drew
                
                if(hand.back().color==discard.color
                        ||hand.back().num==discard.num){
                    //Ask if they want to play a card
                    cout<<"Play It? y/n"<<endl;
                    cin>>yesNo;
                    if(yesNo=='y') playCrd(hand, discard, draw);      
                }
                break;
        }
}

//DRAW
void drawCrd(vector<Card> &hand, vector<Card> &draw){
    //Add a card from the draw pile to the player's hand
    hand.push_back(draw.back());

    //Remove that card from the draw pile
    draw.pop_back();

}

//PLAY A CARD
void playCrd(vector<Card> &hand, Card &discard, vector<Card> &draw){
    int  cardChc;   //Choice which card to play 
    bool valid=true;//Is the play valid
    
    do{ 
        //Player Chooses a Card
        cout<<"Which Card Do You Want To Play?"<<endl;
        cin>>cardChc;
        //Check If The Play Is Valid
        if(hand[cardChc].color==discard.color||hand[cardChc].num==discard.num){
            //If Valid
            valid=true;//Set Valid to True

            //Put Played Card on Top of Discard Pile
            discard=hand[cardChc];

            //Take Played Card Out of Player's Hand
            hand.erase(hand.begin()+cardChc);
        }
        else{
            //If Not Valid
            valid=false;
            //Display Error Message
            cout<<"You must choose a card with the same color or "<<
                    "number!"<<endl;
        }
    }while(!valid); //Loop Until Valid Card Is Played
}

//DISPLAY HAND
void display(Card discard, vector<Card> p1Hand){
    //Show Discard 
    cout<<"Discard:"<<endl;
    cout<<discard.num<<" "<<discard.color<<endl;
    
    //Show Your Hand
    cout<<"Your Hand:"<<endl;
    for(int i=0; i<p1Hand.size(); i++){
        cout<<i<<": "<<p1Hand[i].num<<p1Hand[i].color<<"\t";
    }
    cout<<endl;
}

/*****************************************************************************/
/*                                 PLAY                                       */
void play(Hands *hands, vector<Card> &draw, Card &discard, int &players){
        
    bool endgame;
    
    //Setup Game
    //Shuffle deck, deal two hands, create discard and draw pile
    cout<<"How many players?"<<endl;
    cin>>players;
    
    //setup and deal hands
    hands=setup(draw, discard, players, hands);
    
    //Play Turns
    do{
        for(int i=0; i<players; i++){
            cout<<"Player "<<i+1<<"'s Turn!"<<endl;
            turn(hands[i].data,discard,draw,players);  
            if(hands[i].data.size()==0) endgame=true;
        }
        
    }while(!endgame);
    
    
}


