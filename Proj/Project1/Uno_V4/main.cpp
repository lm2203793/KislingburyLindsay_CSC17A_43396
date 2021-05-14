/* 
 * File:   main.cpp
 * Author: linds
 * Purpose: UNO VERSION 4: Cleaned up, organized code,
 *                         Added functionality for all card types  
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
void drawCrd(vector<Card> &, vector<Card> &);
void playCrd(vector<Card> &, Card &, vector<Card> &);
void playCrd(vector<Card> &, Card &);
void display(Card, vector<Card>);
bool valPlay(vector<Card>, Card);
bool valPlay(Card, Card);
void play();
int setPlyr(Card, int, int);
void prcCard(vector<Card> &, vector<Card> &, Card &);


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
//FILL DECK
void filDeck(vector<Card> &deck){
    //Zero cards 
    deck.push_back({NUMBER,0,'r'});
    deck.push_back({NUMBER,0,'g'});
    deck.push_back({NUMBER,0,'b'});
    deck.push_back({NUMBER,0,'y'});
    //One through Nine
    for(short i=1; i<=9; i++){
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'r'});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'g'});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'b'});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'y'});
    }
    //Action Cards
    //Skip
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'r'});
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'g'});
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'b'});
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'y'});
    //Reverse
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'r'});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'g'});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'b'});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'y'});
    //Draw Two
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'g'});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'g'});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'b'});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'y'});
    //Wild
    for(int j=0; j<4; j++) deck.push_back({WILD,-4,'X'});
    //Wild Draw Four
    for(int j=0; j<4; j++) deck.push_back({WILD4,-5,'X'});
    
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
Hands *deal(vector<Card> &deck, int players){
    //Allocate memory for array of player hands
    Hands *hands=new Hands[players];

    //Deal player the last 7 cards in the shuffled deck
    for(int p=0; p<players; p++){
        for(int i=deck.size()-1; i>deck.size()-8; i--){
            hands[p].data.push_back(deck[i]);
        }
        //Remove those cards from the deck
        for(int i=0; i<7; i++){
            deck.pop_back();
        }
    }
    return hands;
}


//DRAW
void drawCrd(vector<Card> &cards, vector<Card> &draw){
    //Add a card from the draw pile to the player's hand
    cards.push_back(draw.back());

    //Remove that card from the draw pile
    draw.pop_back();
}

//PLAY A CARD with choices
void playCrd(vector<Card> &cards, Card &discard, vector<Card> &draw){
    bool valid;     //Is the play valid
    int cardChc;
    Card card;
    Card debug_card;
    //Player Chooses a Card
    do{ 
        cin.clear();
        cout<<"Which Card Do You Want To Play?"<<endl;
        cin>>cardChc;
        /////////////////////////DEBUG////////////////////////////////////
        if(cardChc==-1){
            int x;
            cout<<"DEBUG MODE"<<endl;
            cout<<"card type: ";
            cin>>x;
            debug_card.type=static_cast<Type>(x);
            if(debug_card.type==NUMBER){
                cout<<"card number: ";
                cin>>debug_card.num;
            }
            cout<<"card color: ";
            cin>>debug_card.color;
            card=debug_card;
        }
        else card=cards[cardChc];

        //Check If The Play Is Valid
        valid=valPlay(card, discard);
        if(valid){
            //Put Played Card on Top of Discard Pile
            discard=card;
            //Take Played Card Out of Player's Hand
            /////////////////////////DEBUG//////////////////////
            if(cardChc!=-1){
            cards.erase(cards.begin()+cardChc);
            }
        }
        else{
            //Display Error Message
            cout<<"You must choose a card of the same color, "<<
                    "number, or type!"<<endl;
        }
    }while(!valid); //Loop Until Valid Card Is Played
}

//play the card just drawn
void playCrd(vector<Card> &hand, Card &discard){
    //Put Played Card on Top of Discard Pile
    discard=hand.back();
    //Take Played Card Out of Player's Hand
    hand.pop_back();
}

//DISPLAY HAND
void display(Card discard, vector<Card> hand){
    //Show Discard 
    cout<<"Discard:"<<endl;
    if(discard.type==NUMBER) cout<<discard.num<<" "<<discard.color<<endl;
    else{
        switch(discard.type){
            case(SKIP): cout<<"SKIP "<<discard.color<<endl; break;
            case(REVERSE): cout<<"REVERSE "<<discard.color<<endl; break;
            case(DRAW2): cout<<"DRAW-2 "<<discard.color<<endl; break;
            case(WILD): cout<<"WILD "<<endl; break;
            case(WILD4): cout<<"WILD-DRAW-4 "<<endl; break;
        }
    }
    
    //Show Your Hand
    cout<<"Your Hand:"<<endl;
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].type){
            case(NUMBER):
                cout<<i<<": "<<hand[i].num<<" "<<hand[i].color<<"   ";
                break;
            case(DRAW2):
                cout<<i<<": "<<"DRAW-2 "<<hand[i].color<<"   ";
                break;
            case(SKIP):
                cout<<i<<": "<<"SKIP "<<hand[i].color<<"   ";
                break;
            case(REVERSE):
                cout<<i<<": "<<"REVERSE "<<hand[i].color<<"   ";
                break;
            case(WILD):
                cout<<i<<": "<<"WILD   ";
                break;
            case(WILD4):
                cout<<i<<": "<<"WILD-DRAW-4   ";
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
    vector<Card> deck;      //The Entire Deck of Cards
    Card discard;           //Discard Pile
    int players;            //Number of players
    int curPlyr=0;          //current player
    bool canPlay;           //does player have a valid card to play
    char cont;              //input to continue
    int cardChc;            //card choice
    
    //Get # of Players
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

    //Setup Cards:
    filDeck(deck);                  //Fill the deck
    shuffle(deck);                  //Shuffle the deck
    hands=deal(deck, players);      //Deal Player hands
    discard=(deck.back());          //Create discard pile
    deck.pop_back();                //Remove that card from the deck
            
    //Get Player Names:
    string name;
    cin.ignore();
    for(int i=0; i<players; i++){
        cout<<"Enter Player "<<i+1<<"'s Name: ";
        getline(cin, name);
        hands[i].player=name;
    }
    
    for(int i=0; i<deck.size(); i++){//Fill Draw Pile
        draw.push_back(deck[i]);
    }
    for(int i=0; i<draw.size(); i++){//Remove those cards from the deck
        deck.pop_back();
    }
    
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
    
    
    //clean up
    delete []hands;
}

//Set the current player at the start of the turn
int setPlyr(Card discard, int curPlyr, int players){
    int addSign;    //Positive or negative for play direction
    bool rev=false; //Flag that indicates when play direction has switched
    
    //If Reverse is played
    if(discard.type==REVERSE){
        if(players==2) curPlyr++;   //Special Case For Two Players
        else rev=!rev;              //Switch the play direction
    } 

    //Set sign to indicate play direction
    if(rev) addSign=-1;      //If reverse is active, sign is negative
    else    addSign=1;       //If reverse is not active, sign is positive
    
    //Skip w/ Two Players Special Case

    
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
bool valPlay(Card card, Card discard){
    bool valid; //play is valid=true
    //Number Card is played
    if(card.type==NUMBER){
        //Card played matches discard color or number
        if(card.color==discard.color
                ||card.num==discard.num){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard color or number
        else valid=false;//Set Valid to False
    }
    //Special Card is played
    if(card.type!=NUMBER){
        //Card played matches discard type or color
        if(card.type==discard.type
                ||card.color==discard.color){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard type or color
        else valid=false;//Set Valid to False
    }

    //Return valid status of card played
    return valid;
}

//Determines whether a player can play any card in their hand
bool valPlay(vector<Card> cards, Card discard){
    bool valid=false; //Player has a card that can be played=true
    
    for(int i=0; i<cards.size(); i++){
        //Check Number Cards
        if(cards[i].type==NUMBER){
            //If player has a card with the same color or number
            if(cards[i].color==discard.color||cards[i].num==discard.num){
                valid=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
        //Check Special Cards
        if(cards[i].type!=NUMBER){
            if(cards[i].color==discard.color||cards[i].type==discard.type){
                valid=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
    }
    
    //Return valid status of player's hand
    return valid;
}

//Add Cards to players hand when draw two or wild draw four are played
//Change Color when Wilds are played
void prcCard(vector<Card> &cards, vector<Card> &draw, Card &discard){
    char colChc;
    
    switch(discard.type){ //Switch on card type
        case(DRAW2):      //Draw Two
            for(int i=0; i<2; i++){ 
                cards.push_back(draw.back());//Add Two Cards to Player's hand
                draw.pop_back();             //Remove those cards from draw pile 
            }
                 
            break;
        case(WILD):
            cout<<"Choose A Color (r,g,b,y): ";//Change discard color
            cin>>colChc;
            discard.color=colChc;
             break;
        case(WILD4):    //Wild Draw Four
            for(int i=0; i<4; i++){
                cards.push_back(draw.back());//Add Four Cards to player's hand
                draw.pop_back();             //Remove those cards from draw pile        
            }
            cout<<"Choose A Color (r,g,b,y): ";//Change discard color
            cin>>colChc;
            discard.color=colChc;      
            break;
    }
}

