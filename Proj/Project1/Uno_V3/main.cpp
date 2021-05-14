/* 
 * File:   main.cpp
 * Author: linds
 * Purpose: UNO VERSION 3: Added functionality for special cards (skip,draw,
 *                         reverse) Code is a MESS :(
 * Created on May 8, 2021 6:09PM
 */

//System Libraries
#include <cstdlib>  //C Standard Library
#include <iostream> //I/O Library
#include <iomanip>  //Format Library
#include <vector>   //Vector Library
#include <ctime>    //Time Library
#include <cctype>   //Character Library
using namespace std;

//User Libraries
enum Type{NUMBER,SKIP,REVERSE,DRAW2,WILD,WILD4}; //Card Types
#include "Card.h"    //Card Structure
#include "Hands.h"   //Hand Structure

//Function Prototypes
//Game Setup:
Hands *setup(vector<Card>&, Card &, int, Hands *);
void filDeck(vector<Card> &);
void shuffle(vector<Card> &);
vector<Card> *deal(vector<Card> &);
//Play:
void drawCrd(vector<Card> *, vector<Card> &);
void playCrd(vector<Card> &, Card &, vector<Card> &);
void playCrd(vector<Card>, Card &);
void display(Card, vector<Card> *);
bool valPlay(vector<Card>, Card);
bool valPlay(vector<Card>, Card, int);
void play();
int setPlyr(Card, int, int);
void prcCard(vector<Card> &, vector<Card> &, Card);


int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));

    //Play Game
    char strtChc;           //Start menu choice

   //Start Menu
    bool error;
    do{
        do{cout<<"UNO!"<<endl;
            cout<<"1: Play Game\n2: View Scores\nQ: Quit"<<endl;
            cin>>strtChc;
            strtChc=toupper(strtChc);
            if(strtChc=='1'||strtChc=='2'||strtChc=='Q')error=false;
            else {
                error=true;
                cout<<"Invalid Choice!"<<endl;
            }
            cin.clear();
        }while(!cin||cin.fail()||error);
        switch(strtChc){
            case '1':
                play();
                break;
            case '2':
                //view scores
                break;
            case 'Q':
            default:
                cout<<"Exiting Program";
                break;
        }
    }while(strtChc!='Q');

    return 0;
}
//Function Definitions

/*****************************************************************************/
/*                               SETUP                                       */







//SETUP MAIN
Hands *setup(vector<Card>&draw, Card &discard, int players, Hands *hands){
    cout<<"setup is running!"<<endl;
    //Declare Variables
    vector<Card> deck; //To Hold the Entire Deck of Cards
    
    //Fill the deck
    filDeck(deck);
    
    //Shuffle the deck
    shuffle(deck);

    //Allocate memory for array of player hands
    Hands *hand=new Hands[players];
    
    //Get Player Names
    string name;
    cin.ignore();
    for(int i=0; i<players; i++){
        cout<<"Enter Player "<<i+1<<"'s Name: ";
        getline(cin, name);
        hand[i].player=name;
    }
 
    //Fill player hands
    for(int i=0; i<players; i++){
        //Deal player the last 7 cards in the shuffled deck
        for(int j=deck.size()-1; j>deck.size()-8; j--){
            hand[i].data.push_back(deck[j]);
        }
    
        //Remove the cards just drawn from the deck
        for(int i=0; i<7; i++) deck.pop_back();
    }
    
    //Create Draw and Discard Pile
    //Flip a card from the deck over to start discard pile
    discard=(deck.back());

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
    //Zero cards 
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
    //Action Cards
    //Skip
    for(int j=0; j<2; j++) deck.push_back({SKIP,0,'r'});
    for(int j=0; j<2; j++) deck.push_back({SKIP,0,'g'});
    for(int j=0; j<2; j++) deck.push_back({SKIP,0,'b'});
    for(int j=0; j<2; j++) deck.push_back({SKIP,0,'y'});
    //Reverse
    for(int j=0; j<2; j++) deck.push_back({REVERSE,0,'r'});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,0,'g'});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,0,'b'});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,0,'y'});
    //Draw Two
    for(int j=0; j<2; j++) deck.push_back({DRAW2,0,'g'});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,0,'g'});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,0,'b'});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,0,'y'});
    
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

//DRAW
void drawCrd(vector<Card> &hand, vector<Card> &draw){
    //Add a card from the draw pile to the player's hand
    hand.push_back(draw.back());

    //Remove that card from the draw pile
    draw.pop_back();

}

//PLAY A CARD with choices
void playCrd(vector<Card> &hand, Card &discard, vector<Card> &draw){
    bool valid;     //Is the play valid
    int cardChc;
    
    //Player Chooses a Card
    do{ 
        cin.clear();
        cout<<"Which Card Do You Want To Play?"<<endl;
        cin>>cardChc;
        //Check If The Play Is Valid
        valid=valPlay(hand,discard,cardChc);
        if(valid){
            //Put Played Card on Top of Discard Pile
            discard=hand[cardChc];
            //Take Played Card Out of Player's Hand
            hand.erase(hand.begin()+cardChc);
        }
        else{
            //Display Error Message
            cout<<"You must choose a card of the same color, "<<
                    "number, or type!"<<endl;
        }
    }while(!valid); //Loop Until Valid Card Is Played
}

//play the card just drawn
void playCrd(vector<Card> hand, Card &discard){
    //Put Played Card on Top of Discard Pile
    discard=hand.back();
    //Take Played Card Out of Player's Hand
    hand.pop_back();
}

//DISPLAY HAND
void display(Card discard, vector<Card> &hand){
    //Show Discard 
    cout<<"Discard:"<<endl;
    if(discard.type==NUMBER) cout<<discard.num<<" "<<discard.color<<endl;
    else cout<<discard.type<<" "<<discard.color<<endl;
    
    //Show Your Hand
    cout<<"Your Hand:"<<endl;
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].type){
            case(NUMBER):
                cout<<i<<": "<<hand[i].num<<" "<<hand[i].color<<"   ";
                break;
            case(DRAW2):
                cout<<i<<": "<<"DRAW TWO"<<" "<<hand[i].color<<"   ";
                break;
            case(SKIP):
                cout<<i<<": "<<"SKIP"<<" "<<hand[i].color<<"   ";
                break;
            case(REVERSE):
                cout<<i<<": "<<"REVERSE"<<" "<<hand[i].color<<"   ";
                break;
            case(WILD):
                cout<<i<<": "<<"WILD"<<" "<<hand[i].color<<"   ";
                break;
            case(WILD4):
                cout<<i<<": "<<"WILD DRAW FOUR"<<" "<<hand[i].color<<"   ";
                break;    
        }
    }
    cout<<endl;
}

void play(){
    //Declare Variables
    bool endgame;           //running game=true
    bool error;             //input validation
    Hands *hands;           //Pointer to an array of player hand vectors
    vector<Card> draw;      //Draw Pile
    Card discard;           //Discard Pile
    int players;            //Number of players
    int curPlyr=0;          //current player
    bool canPlay;           //does player have a valid card to play
    char cont;              //input to continue
    int cardChc;            //card choice
    

    //Shuffle deck, deal two hands, create discard and draw pile
    cout<<"How many players? (Up to 4)"<<endl;
    do{
        cin>>players;
        if(players<=10&&players>=2)error=false;
        else{
            cout<<"Invalid!"<<endl;
            error=true;
        }
        cin.clear();
    }while(error||!cin||cin.fail());
    error=false;
    
    //Setup and Deal hands
    hands=setup(draw, discard, players, hands);
    
    do{//Main Game Loop
        do{//Player Turn Loop
            prcCard(hands[curPlyr].data, draw, discard);
            cout<<hands[curPlyr].player<<"'s TURN!"<<endl;
            //Get current Player's hand
            //Display discard pile and player hand
            display(discard, hands[curPlyr].data);
            //Check if the player can play a card
            canPlay=valPlay(hands[curPlyr].data,discard);
            if(canPlay){//Play A Card
                playCrd(hands[curPlyr].data, discard, draw); 
            }
            else{//Draw A Card
                do{
                    cout<<"No Valid Card to Play!"<<endl;
                    cout<<"Type x To Draw A Card"<<endl;
                    cin>>cont;
                    //Draw A Card
                    drawCrd(hands[curPlyr].data, draw);
                    //Display The Card Just Drawn
                    cout<<"You drew: ";
                    cout<<hands[curPlyr].data.back().num;
                    cout<<hands[curPlyr].data.back().color<<endl;
                    //Check If The Card Just Drawn Can Be Played
                    canPlay=valPlay(hands[curPlyr].data, discard);
                    if(canPlay){
                        //Play The Card
                        cout<<"Type x to Play it"<<endl;
                        cin>>cont;
                        playCrd(hands[curPlyr].data, discard); 
                    }
                }while(!canPlay);
                }
        }while(error);//input validation);
         //**make sure it works w/ more than two players
        curPlyr=setPlyr(discard, curPlyr, players);
    }while(!endgame);
    
}

//Set the current player at the start of the turn
int setPlyr(Card discard, int curPlyr, int players){
    int addSign;    //Positive or negative for play direction
    bool rev=false; //Flag that indicates when play direction has switched
    
    //If Reverse is played
    if(discard.type==REVERSE) rev=!rev; //Switch the play direction

    //Set sign to indicate play direction
    if(rev) addSign=-1;      //If reverse is active, sign is negative
    else    addSign=1;       //If reverse is not active, sign is positive
    
    //Skip
    if(discard.type==SKIP) curPlyr+=2*addSign;//If Skip is played, skip a player
    else curPlyr+=addSign;  
    
    //Wrap
    if(curPlyr<0) curPlyr=players+curPlyr; //Current player is negative,
                                           //wrap around to beginning
    
    if(curPlyr>players-1) curPlyr=curPlyr-players;//Current player> # of players
                                                  //wrap around to beginning
    
    //Return the current player
    return curPlyr;
}

//Determines if a card played is valid
bool valPlay(vector<Card> hand, Card discard, int cardChc){
    bool valid; //play is valid=true
    
    //Number Card is played
    if(hand[cardChc].type==NUMBER){
        //Card played matches discard color or number
        if(hand[cardChc].color==discard.color
                ||hand[cardChc].num==discard.num){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard color or number
        else valid=false;//Set Valid to False
    }
    //Special Card is played
    if(hand[cardChc].type!=NUMBER){
        //Card played matches discard type or color
        if(hand[cardChc].type==discard.type
                ||hand[cardChc].color==discard.color){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard type or color
        else valid=false;//Set Valid to False
    }

    //Return valid status of card played
    return valid;
}

//Determines whether a player can play any card in their hand
bool valPlay(vector<Card> hand, Card discard){
    bool valid=false; //Player has a card that can be played=true
    
    for(int i=0; i<hand.size(); i++){
        //Check Number Cards
        if(hand[i].type==NUMBER){
            //If player has a card with the same color or number
            if(hand[i].color==discard.color||hand[i].num==discard.num){
                valid=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
        //Check Special Cards
        if(hand[i].type!=NUMBER){
            if(hand[i].color==discard.color||hand[i].type==discard.type){
                valid=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
    }
    
    //Return valid status of player's hand
    return valid;
}

//Add Cards to players hand when draw two or wild draw four are played
void prcCard(vector<Card> &hand, vector<Card> &draw, Card discard){
    switch(discard.type){ //Switch on card type
        case(DRAW2):      //Draw Two
            for(int i=0; i<2; i++){ 
                hand.push_back(draw.back());//Add Two Cards to Player's hand
                draw.pop_back();            //Remove those cards from draw pile
            }
            break;
        case(WILD4):    //Wild Draw Four
            for(int i=0; i<4; i++){
                hand.push_back(draw.back()); //Add Four Cards to player's hand    
                draw.pop_back();             //Remove those cards from draw pile
            }
            break;
    }
}

//change color for wilds
void color(Card &discard){
    ///////
}

