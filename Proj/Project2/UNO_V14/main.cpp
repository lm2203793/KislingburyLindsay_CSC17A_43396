/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: UNO V13
 *          Working 
 * Created on June 2, 2021, 8:07 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
//User Libraries
#include "Deck.h"
#include "Player.h"
using namespace std;
//Function Prototypes
void prcCard(Player *, Deck, Card); //Process Card
bool unoFlag(const vector<Card> *, bool);                       //Uno Status
void showCrd(const Card);
void uno(Player *, Deck, char);
bool valPlay(const Card, const Card);
int setPlyr(const Card, int, int);

int main(int argc, char** argv) {
   
    int             numPlyrs,   //Number of players
                    curPlyr,   //Current player
                    cardChc;   //Card choice
    char            cont,      //User input to continue after message
                    unoChc;       //Player choice to call uno or play a card
    bool            unoFlag,   //Flag, if player called uno
                    cPlay,     //Flag, if player has a playable card
                    endgame,   //Flag, if game is running endgame=false
                    trnOver,   //Flag, if turn is over=true 
                    error;
    
    Deck           deck;
    Player         *plyrPtr;
    Player         *players;
    
    
    //Initialize Variables
    numPlyrs=0, curPlyr=0, cardChc=0;
    endgame=false, error=false, cPlay=false, unoFlag=false, trnOver=false;
    
    
    //Get # of Players:
    cout<<"How many Players?: ";
    cin>>numPlyrs;
    players=new Player[numPlyrs];
    for(int i=0; i<numPlyrs; i++){
        string name;
        cout<<"Enter Player "<<(i+1)<<"'s Name: ";
        cin>>name;
        players[i].set(i,deck.hands(),name);
    }
    
    //create draw and discard
    cout<<"DECK SIZE: "<<deck.getSize()<<endl;
    deck.setDscrd();
    deck.filDraw();
    cout<<"DISCARD: "<<deck.getDis()<<endl;
    
    Card test(NUMBER, 1, 'r', "red", 1);
    test.prtColn();

    //play game
    do{//Main Game Loop
            //Set pointer to current player
            plyrPtr=&(players[curPlyr]);
            //Process special cards played that affect current player
            prcCard(plyrPtr, deck, deck.getDis()); 
            cout<<"+----------------------------------------+"<<endl;
            cout<<"\t"<<plyrPtr->getName()<<"'s TURN!"<<endl;
            //Check if the player can play a card
            plyrPtr->cPlyStat(deck.getDis());
            //Check if the player can call uno
            plyrPtr->unoStat(cPlay);
            //Display the current discard
            cout<<"Discard: ";
            showCrd(deck.getDis());
            //Display current player's hand
            plyrPtr->showHnd();
            //Display message, ask if player wants to call uno
            cout<<"Enter u To Call UNO or any other key to continue: "<<endl;
            //Get uno choice
            cin>>unoChc;
            //Uno actions
            uno(plyrPtr, deck, unoChc);
            do{//Play Card Loop
                cin.clear();
               if(plyrPtr->getCply()){  //Play A Card
                   do{                  //Input Validation Loop 
                       error=false;     //Reset Input Validation Flag
                       cin.clear();
                       cin.ignore();
                       cout<<"What card do you want to play?"<<endl;
                       cin>>cardChc;
                       if(cardChc<0||cardChc>plyrPtr->getHndSz()-1
                               ||!cin||cin.fail()){
                           error=true;
                           cout<<"Invalid Choice!"<<endl;
                       }
                   }while(!cin||cin.fail()||error);
                   //Validate Play
                   if(valPlay(plyrPtr->getCrd(cardChc), deck.getDis())){
                       plyrPtr->playCard(cardChc);
                       trnOver=true;
                   }
                   else{
                       cout<<"Not a Valid Card!"<<endl;
                       trnOver=false;
                   }
                }
                else{//Draw A Card if no valid cards in your hand
                    do{
                        cout<<"\nNo Valid Card to Play!"<<endl;
                        cout<<"Enter any key to continue"<<endl;
                        cin>>cont;
                        //Draw A Card
                        plyrPtr->RecCrd(deck.drawCard()); //Add a card to players hand
                        //Check If The Card Just Drawn Can Be Played
                        bool can=valPlay(plyrPtr->getCrd(plyrPtr->getHndSz()),deck.getDis());
                        if(can){
                            //Play The Card
                            cout<<"Enter any key to Play it"<<endl;
                            cin>>cont;
                            plyrPtr->playCard(plyrPtr->getHndSz());
                            trnOver=true;
                        }
                    }while(!plyrPtr->getCply());
                }
                //If a player has 0 cards
                if(plyrPtr->getHndSz()==0){
                    //Set the winner
                    plyrPtr->setWin();
                    //Calculate Winner's Score
                  //!?!?!?!?!?  calcScr(hands,players,curPlyr);
                    //Calculate largest hand for both players
                  //?!?!?!?!  lrgHnd(hands, players);
                    //Display End Game Message
                    cout<<"+***************************************+"<<endl;
                    cout<<"\t\tEND GAME!!"<<endl;
                    cout<<plyrPtr->getName()<<" WINS!!!!"<<endl;
                  //?!?!?!?  cout<<hands[curPlyr].player<<"'s SCORE: ";
                 //?!?!?!   cout<<hands[curPlyr].gmScr<<endl;
                    cout<<"+***************************************+"<<endl;
                    //End Game
                    endgame=true;
                }
            }while(!trnOver);
            //If the deck is running low, shuffle and fill deck
            if(deck.getSize()<10){
                deck.filDeck();                 //Fill the deck
                deck.shuffle();                 //Shuffle the deck
            }
        curPlyr=setPlyr(deck.getDis(), curPlyr, numPlyrs);
    }while(!endgame);

    return 0;
}
//Function Definitions
//Display a Card
void showCrd(const Card card){
    Type type=card.getType();
    //If the card is a number card, display number and color
    if(type==NUMBER) cout<<card.getNum()<<" ";
    //Else display type and color
    else{
        switch(type){
            case(SKIP): cout<<"SKIP "; break;
            case(REVERSE): cout<<"REVERSE "; break;
            case(DRAW2): cout<<"DRAW-2 "; break;
            case(WILD): cout<<"WILD "; break;
            case(WILD4): cout<<"WILD-DRAW-4 "; break;
        }
    } 
    cout<<card.getColn()<<endl;
}

//Set the current player
int setPlyr(const Card discard, int curPlyr, int players){
    int addSign;    //Positive or negative for play direction
    bool rev=false; //Flag that indicates when play direction has switched
    Type type=discard.getType();
    
    //If Reverse is played
    if(type==REVERSE){
        if(players==2) curPlyr++;   //Special Case For Two Players
        else rev=!rev;              //Switch the play direction
    } 
    //Set sign to indicate play direction
    if(rev) addSign=-1;      //If reverse is active, sign is negative
    else    addSign=1;       //If reverse is not active, sign is positive
    //Skip
    if(type==SKIP)  //If Skip is played, skip a player
        curPlyr+=2*addSign;
    else curPlyr+=addSign;  
    //Wrap
    if(curPlyr<0) //If Current player is negative
        curPlyr=players+curPlyr; //wrap around to beginning
    if(curPlyr>players-1) //If current player > # of players
        curPlyr=curPlyr-players;//wrap around to beginning
    //Return the current player
    return curPlyr;
}

//DETERMINE IF CARD PLAYED IS VALID
bool valPlay(const Card card, const Card discard){
    Type pType=card.getType();      //Hold player's card type
    Type dType=discard.getType();   //Hold discard card type
    char pCol=card.getColor();      //Hold player's card color
    char dCol=discard.getColor();   //Hold discard card color
    int  pNum=card.getNum();        //Hold player's card number
    int  dNum=discard.getNum();     //Hold discard card number 
    bool valid;                     //play is valid=true
    //Number Card is played
    if(pType==NUMBER){
        //Card played matches discard color or number
        if(pCol==dCol||pNum==dNum){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard color or number
        else valid=false;//Set Valid to False
    }
    //Special Card is played
    if(pType==SKIP||pType==REVERSE||pType==DRAW2){
        //Card played matches discard type or color
        if(pType==dType||pCol==dCol){
            valid=true;//Set Valid to True
        }
        //Card played does not match discard type or color
        else valid=false;//Set Valid to False
    }
    //Wild is always valid
    if(pType==WILD||pType==WILD4)
        valid=true;
    //Return valid status of card played
    return valid;
}



//PROCESS SPECIAL CARDS
void prcCard(Player *plyr, Deck deck, Card discard){
    char colChc;
    bool error=false;
    switch(discard.getType()){ //Switch on card type
        case(DRAW2)://Draw Two
            for(int i=0; i<2; i++){ 
                plyr->RecCrd(deck.drawCard()); //Add two cards to players hand
            }                                  //and Remove them from draw pile
            break;
        case(WILD)://Wild
            do{//Input Validation
                cout<<"Choose A Color (r,g,b,y): "; 
                cin>>colChc;                 //Get Player Color Choice
                if(colChc=='r'||colChc=='g'||colChc=='b'||colChc=='y'){
                    error=false;
                }
                else{
                    cout<<"Invalid Choice!"<<endl;
                    cin.clear();
                    cin.ignore();
                    error=true;
                }
            }while(!cin||cin.fail()||error);
            colChc=tolower(colChc);    //Ensure that color choice is lowercase
            discard.setColor(colChc);  //Change the color of discard 

            break;
        case(WILD4)://Wild Draw Four
            for(int i=0; i<4; i++){          
                plyr->RecCrd(deck.drawCard());//Add Four Cards to player's hand    
            }                                 //and Remove them from draw pile
            do{
                cout<<"Choose A Color (r,g,b,y): ";//Get Player Color Choice
                cin.clear();
                cin.ignore();
                cin>>colChc;
                if(colChc=='r'||colChc=='g'||colChc=='b'||colChc=='y'){
                    cout<<"Invalid Choice!"<<endl;
                    error=false;
                }
                else error=true;
            }while(!cin||cin.fail()||error); 
            colChc=tolower(colChc);//Ensure that color choice is lowercase
            discard.setColor(colChc);  //Change the color of discard 
            break;
    }
}


//Uno
void uno(Player *plyr, Deck deck, char unoChc){
    bool uno=plyr->getUno();    //hold player uno status
    bool play=plyr->getCply();  //hold can play status
    if(unoChc=='u'){//If Player calls Uno
        if(uno)//If Player has Uno
            cout<<"UNO!!!!"<<endl;//Display message
        else{//If Player does not have Uno
            if(plyr->getHndSz()>2){//If Player has > two cards
                cout<<"You still have "<<plyr->getHndSz()
                    <<" cards! NO UNO!"<<endl;//Display message
                }
            if(!play){//If Player has no playable cards
                cout<<"You don't have a playable card!"
                        <<"NO UNO!"<<endl;//Display message
            }
        }
    }
    else if(uno&&unoChc!='u'){ //If Player doesn't call uno and has uno
        cout<<"You didn't call UNO! Draw 2 cards!"<<endl; //Message
        for(int i=0; i<2; i++){  //Draw 2 Cards
            plyr->RecCrd(deck.drawCard()); //Add two cards to players hand
        }                                  //and remove them from draw pile
        cout<<endl;                        
        plyr->showHnd();
        plyr->setUno(false);          //unoFlag=false
    }
}
