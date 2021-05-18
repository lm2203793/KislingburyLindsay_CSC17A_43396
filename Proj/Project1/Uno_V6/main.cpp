/* 
 * File:   main.cpp
 * Author: linds
 * Purpose: UNO VERSION 5: ///// 
 * Created on May 13, 2021 3:28PM
 */

//System Libraries
#include <cstdlib>  //C Standard Library
#include <iostream> //I/O Library
#include <iomanip>  //Format Library
#include <vector>
#include <ctime>    //Time Library
#include <cctype>
#include <string>
using namespace std;


//User Libraries
enum Type{NUMBER,SKIP,REVERSE,DRAW2,WILD,WILD4}; //Card Types
struct Card{
    Type            type;
    short           num;
    char            color;
    string          colName;
};

struct Hands{
    vector<Card>   data;     //Data in the array
    string         player;
};
//Function Prototypes
//Game Setup:
vector<Card> filDeck();
void shuffle(vector<Card> &, Card &);
vector<Card> *deal(vector<Card> &);
//Play:
void drawCrd(vector<Card> *, vector<Card> &);
void playCrd(vector<Card> *, Card &, int);
void playCrd(vector<Card> *, Card &);
void showHnd(vector<Card> *);
void showCrd(const Card);
bool valPlay(vector<Card> *, Card);
bool valPlay(Card, Card);
void play();
int setPlyr(Card, int, int);
void prcCard(vector<Card> *, vector<Card> &, Card &);
bool uno(vector<Card> *, bool);


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
            else{
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
vector<Card> filDeck(){
    //Declare Variables:
    vector<Card> deck;      //Entire deck of cards
    
    //Add Number Cards 
    //4 Zero Cards: 1 of each color
    deck.push_back({NUMBER,0,'r',"RED"});
    deck.push_back({NUMBER,0,'g',"GREEN"});
    deck.push_back({NUMBER,0,'b',"BLUE"});
    deck.push_back({NUMBER,0,'y',"YELLOW"});
    //One through Nine: 2 of each color per number
    for(short i=1; i<=9; i++){
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'r',"RED"});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'g',"GREEN"});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'b',"BLUE"});
        for(int j=0; j<2; j++) deck.push_back({NUMBER,i,'y',"YELLOW"});
    }
    //Add Action Cards
    //Skip: 2 of each color
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'r',"RED"});
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'g',"GREEN"});
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'b',"BLUE"});
    for(int j=0; j<2; j++) deck.push_back({SKIP,-1,'y',"YELLOW"});
    //Reverse: 2 of each color
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'r',"RED"});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'g',"GREEN"});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'b',"BLUE"});
    for(int j=0; j<2; j++) deck.push_back({REVERSE,-2,'y',"YELLOW"});
    //Draw Two: 2 of each color
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'r',"RED"});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'g',"GREEN"});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'b',"BLUE"});
    for(int j=0; j<2; j++) deck.push_back({DRAW2,-3,'y',"YELLOW"});
    //Wild: 4
    for(int j=0; j<4; j++) deck.push_back({WILD,-4,'X'});
    //Wild Draw Four: 4
    for(int j=0; j<4; j++) deck.push_back({WILD4,-5,'X'});
    
    //Return filled deck
    return deck;
}

//SHUFFLE AND CREATE DISCARD PILE
void shuffle(vector<Card> &deck, Card &discard){
    //Shuffle Cards
    int size=deck.size();
    for(int i=0; i<size; i++) {
      int j=i+rand()%(size-i);
      swap(deck[i], deck[j]);
   }
    
    //Flip last card over to start discard pile
    size--;
    int counter=1;  //Counter for index of card to swap 
    if(deck.back().type!=NUMBER){ //If the last card is a special card
        //Continue swapping last card with the one above it until last 
        //card is not a special card
        while(deck[size].type!=NUMBER){ 
            swap(deck[size],deck[size-counter]);      
            counter++;
        }
    }
    discard=deck.back();  //Flip the last card over to start discard pile
    deck.pop_back();      //Remove that card from the deck
}

//DEAL HANDS
Hands *deal(vector<Card> &deck, int players){
    //Allocate memory for array of player hands
    Hands *hands=new Hands[players];

    //Deal player the last 7 cards in the shuffled deck
    for(int p=0; p<players; p++){
        for(int i=deck.size()-1; i>deck.size()-8; i--)
            hands[p].data.push_back(deck[i]);
        //Remove those cards from the deck
        for(int i=0; i<7; i++)
            deck.pop_back();
    }
    //Return pointer to array of player hands
    return hands;
}

//DRAW CARD
void drawCrd(vector<Card> *cards, vector<Card> &draw){
    //Declare temporary Card variable to hold card being added
    Card add=draw.back(); //Card to be added is the last card in draw pile
    
    //Add the card to player's hand
    cards->push_back(add);
    //Remove that card from the draw pile
    draw.pop_back();
    //Display the card player drew
    cout<<"You Drew: ";
    switch(add.type){
        case(NUMBER): cout<<add.num<<add.color; break;
        case(SKIP): cout<<"SKIP "<<add.color<<endl; break;
        case(REVERSE): cout<<"REVERSE "<<add.color<<endl; break;
        case(DRAW2): cout<<"DRAW-2 "<<add.color<<endl; break;
        case(WILD): cout<<"WILD "<<add.color<<endl; break;
        case(WILD4): cout<<"WILD-DRAW-4 "<<add.color<<endl; break;
    }       
   cout<<"    ";
}
//PLAY A CARD with card choices
void playCrd(vector<Card> *cards, Card &discard, int cardChc){
    Card card;  //Temporary card variable to hold the card chosen
    Card debug_card;//***DEBUG
    //Player Chooses a Card
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
        else card=cards->at(cardChc); 

        //Check If The Play Is Valid
            //Put Played Card on Top of Discard Pile
            discard=card;
            //Take Played Card Out of Player's Hand
            /////////////////////////DEBUG//////////////////////
            if(cardChc!=-1)
                cards->erase(cards->begin()+cardChc);
}

//PLAY A CARD play the card just drawn
void playCrd(vector<Card> *hand, Card &discard){
    //Put Played Card on Top of Discard Pile
    discard=hand->back();
    //Take Played Card Out of Player's Hand
    hand->pop_back();
}

//DISPLAY A CARD
void showCrd(const Card card){
    //If the card is a number card, display number and color
    if(card.type==NUMBER) cout<<card.num<<" "<<card.colName<<endl;
    //Else display type and color
    else{
        switch(card.type){
            case(SKIP): cout<<"SKIP "<<card.colName<<endl; break;
            case(REVERSE): cout<<"REVERSE "<<card.colName<<endl; break;
            case(DRAW2): cout<<"DRAW-2 "<<card.colName<<endl; break;
            case(WILD): cout<<"WILD "<<card.colName<<endl; break;
            case(WILD4): cout<<"WILD-DRAW-4 "<<card.colName<<endl; break;
        }
    }  
}

//DISPLAY PLAYER'S HAND
void showHnd(Hands *hand, int curPlyr){
    vector<Card> cards=hand[curPlyr].data;
    cout<<hand[curPlyr].player<<"'s Hand:"<<endl;
    int size=cards.size();
    for(int i=0; i<=size; i++){
        cout<<right<<setw(3)<<i<<": ";
        //If the card is a number card, display number and color
        if(cards[i].type==NUMBER) cout<<cards[i].num<<" "<<cards[i].colName<<"   ";
        //Else display type and color
        else{
            switch(cards[i].type){
                case(SKIP): cout<<"SKIP "<<cards[i].colName<<"   "; break;
                case(REVERSE): cout<<"REVERSE "<<cards[i].colName<<"   "; break;
                case(DRAW2): cout<<"DRAW-2 "<<cards[i].colName<<"   "; break;
                case(WILD): cout<<"WILD "<<cards[i].colName<<"   "; break;
                case(WILD4): cout<<"WILD-DRAW-4 "<<"   "; break;
            }
        }
    }
    cout<<endl;
}

void play(){
    //Declare Variables
    Hands           *hands;    //Pointer to an array of player hand vectors
    vector<Card>    *handPtr;  //Pointer to current player's hand   
    vector<Card>    draw,      //Draw Pile
                    deck;      //The Entire Deck of Cards
    Card            discard;   //Discard Pile
    int             players,   //Number of players
                    curPlyr,   //Current player
                    cardChc;   //Card choice
    char            cont,      //User input to continue after message
                    chc;       //Player choice to call uno or play a card
    bool            unoFlag,   //Flag, if player called uno
                    endgame,   //Flag, if game is running endgame=false
                    error,     //Flag for input validation
                    canPlay,   //Flag if player has a playable card 
                    trnOver;   //Flag, if turn is over=true
    string          name;      //Hold user input for player name
    
    //Initialize Variables
    players=0, curPlyr=0, cardChc=0;
    endgame=false, error=false, canPlay=false, unoFlag=false, trnOver=false;
    
    //Get # of Players:
    do{
        cout<<"How many players? (Up to 4)"<<endl;
        cin.clear();
        cin.ignore();
        error=false;                //Set error to False
        cin>>players;               //Get # of players 
        if(players<=10&&players>=2) //If >10 or <2
            error=false;                //error=false
        else{                       //else
            cout<<"Invalid!"<<endl;     //display message
            error=true;                 //error=true
        }
    }while(error||!cin||cin.fail());//continue until user enters valid # 
                       
    //Setup Cards:
    deck=filDeck();                 //Fill the deck
    shuffle(deck,discard);          //Shuffle the deck
    hands=deal(deck, players);      //Deal Player hands
            
    //Get Player Names:
    cin.ignore();                   //Clear buffer
    for(int i=0; i<players; i++){   //Loop on # of players
        cout<<"Enter Player "<<i+1<<"'s Name: ";
        getline(cin, name);         //Get name
        hands[i].player=name;       //Store name in player's hand
    }
    
    //Fill Draw Pile
    for(int i=0; i<deck.size(); i++){
        draw.push_back(deck[i]);
    }
    //Remove cards added to the draw pile from the deck
    for(int i=0; i<draw.size(); i++){
        deck.pop_back();
    }
    
    do{//Main Game Loop
        do{//Player Turn Loop
            //Set pointer to current player hand
            handPtr=&(hands[curPlyr].data); 
            //Process special cards played that affect current player
            prcCard(handPtr, draw, discard); 
            cout<<hands[curPlyr].player<<"'s TURN!"<<endl;
            //Check if the player can play a card
            canPlay=valPlay(handPtr,discard);
            //Check if the player can call uno
            unoFlag=uno(handPtr,canPlay);
            //Display the current discard
            cout<<"Discard: ";
            showCrd(discard);
            //Display current player's hand
            showHnd(handPtr);
            //Display message, ask if player wants to call uno
            cout<<"Enter u To Call UNO or any other key to continue: "<<endl;
            //Get uno choice
            cin>>chc;
            if(chc=='u'){//If Player calls Uno
                if(unoFlag){//If Player has Uno
                    cout<<"UNO!!!!"<<endl;//Display message
                }
                else{//If Player does not have Uno
                    if(hands[curPlyr].data.size()>2){//If Player has > two cards
                        cout<<"You still have "<<hands[curPlyr].data.size()
                            <<" cards! NO UNO!"<<endl;//Display message
                        }
                    if(!canPlay){//If Player has no playable cards
                        cout<<"You don't have a playable card!"
                                <<"NO UNO!"<<endl;//Display message
                    }
                }
            }
            else if(unoFlag&&chc!='u'){ //If Player doesn't call uno and has uno
                    cout<<"You didn't call UNO! Draw 2 cards!"<<endl; //Message
                    for(int i=0; i<2; i++)  //Draw 2 Cards
                        drawCrd(handPtr,draw);
                    unoFlag=false;          //unoFlag=false
                }
            do{//Play Card Loop
                cin.clear();
                if(unoFlag&&chc!='u'){
                    cout<<"You didn't call UNO! Draw 2 cards!"<<endl;
                    for(int i=0; i<2; i++) drawCrd(handPtr,draw);
                    unoFlag=false;
                }
               if(canPlay){//Play A Card
                   do{                  //Input Validation Loop 
                       error=false;     //Reset Input Validation Flag
                       cin.clear();
                       cin.ignore();
                       cout<<"What card do you want to play?"<<endl;
                       cin>>cardChc;
                       if(cardChc<0||cardChc>hands[curPlyr].data.size()-1
                               ||!cin||cin.fail()){
                           error=true;
                           cout<<"Invalid Choice!"<<endl;
                       }
                   }while(!cin||cin.fail()||error);

                   //validate play here
                   if(valPlay(hands[curPlyr].data[cardChc], discard)){
                       playCrd(handPtr, discard, cardChc);
                       trnOver=true;
                   }
                   else{
                       cout<<"Not a Valid Card!"<<endl;
                       trnOver=false;
                   }
                }
                else{//Draw A Card if no valid cards in your hand
                    do{
                        cout<<"No Valid Card to Play!"<<endl;
                        cout<<"Enter any key to continue"<<endl;
                        cin>>cont;
                        //Draw A Card
                        drawCrd(handPtr, draw);
                        //Check If The Card Just Drawn Can Be Played
                        canPlay=valPlay(handPtr, discard);
                        if(canPlay){
                            //Play The Card
                            cout<<"Enter any key to Play it"<<endl;
                            cin>>cont;
                            playCrd(handPtr, discard);
                            trnOver=true;
                        }
                    }while(!canPlay);
                }
                if(hands[curPlyr].data.size()==0){
                    cout<<"END GAME!!"<<endl;
                    cout<<hands[curPlyr].player<<" WINS!!!!"<<endl;
                    endgame=true;
                }
            }while(!trnOver);  
        }while(error);//input validation
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
    if(card.type==SKIP||card.type==REVERSE||card.type==DRAW2){
        //Card played matches discard type or color
        if(card.type==discard.type
                ||card.color==discard.color){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard type or color
        else valid=false;//Set Valid to False
    }
    if(card.type==WILD||card.type==WILD4){
        valid=true;
    }

    //Return valid status of card played
    return valid;
}

//Determines whether a player can play any card in their hand
bool valPlay(vector<Card> *cards, Card discard){
    bool valid=false; //Player has a card that can be played=true
    
    //Loop on size of player's hand
    for(int i=0; i<cards->size(); i++){
        //Check Number Cards
        if(cards->at(i).type==NUMBER){
            //If player has a card with the same color or number
            if(cards->at(i).color==discard.color||cards->at(i).num==discard.num){
                valid=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
        //Check Special Cards
        if(cards->at(i).type!=NUMBER){
            if(cards->at(i).color==discard.color||cards->at(i).type==discard.type){
                valid=true; //Set Valid to True
                break;      //Stop Looking
            }
        }
        if(cards->at(i).type==WILD||cards->at(i).type==WILD4){
            valid=true;
            break;
        }
    }
    
    //Return valid status of player's hand
    return valid;
}

//Add Cards to players hand when draw two or wild draw four are played
//Change Color when Wilds are played
void prcCard(vector<Card> *cards, vector<Card> &draw, Card &discard){
    char colChc;
    
    switch(discard.type){ //Switch on card type
        case(DRAW2):      //Draw Two
            for(int i=0; i<2; i++){ 
                cards->push_back(draw.back());//Add Two Cards to Player's hand
                draw.pop_back();             //Remove those cards from draw pile 
            }
                 
            break;
        case(WILD):     //Wild
            cout<<"Choose A Color (r,g,b,y): ";//Change discard color
            cin>>colChc;
            colChc=tolower(colChc);
            discard.color=colChc;
             break;
        case(WILD4):    //Wild Draw Four
            for(int i=0; i<4; i++){          
                cards->push_back(draw.back());//Add Four Cards to player's hand
                draw.pop_back();             //Remove those cards from draw pile        
            }
            cout<<"Choose A Color (r,g,b,y): ";//Player chooses new discard color
            cin>>colChc; 
            colChc=tolower(colChc);
            discard.color=colChc;      
            break;
    }
}

bool uno(vector<Card> *cards, bool canPlay){
    bool unoFlag; //Flag, player has uno=true
    
    if(cards->size()==2){    //If player has two cards
        if(canPlay)         //If player has a playable card
            unoFlag=true;   //Set UNO flag to true
        else                //If player doesn't have a playable card
            unoFlag=false;  //Set UNO flag to false
    }
    else                    //If player doesn't have two cards
        unoFlag=false;      //Set UNO flag to false

    return unoFlag;
}
/*****************************************************************************/
/*                               SCORES                                       */
