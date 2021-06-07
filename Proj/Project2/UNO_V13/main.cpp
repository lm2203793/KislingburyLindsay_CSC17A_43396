/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: UNO V13
 *          Does not run, classes are a mess
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
void prcCard(Player *, Deck &, Card &); //Process Card
bool unoFlag(const vector<Card> *, bool);                       //Uno Status 
void uno(Player *, Deck &, char, bool);
bool valPlay(Player *, Deck &, int);
int setPlyr(Card &, int, int);
void mkPlyrs(Deck &, int, Player *);
int main(int argc, char** argv) {
   
    int             numPlyrs,  //Number of players
                    curPlyr,   //Current player
                    cardChc;   //Card choice
    char            cont,      //User input to continue after message
                    unoChc;    //Player choice to call uno or play a card
    bool            unoFlag,   //Flag, if player called uno
                    cPlay,     //Flag, if player has a playable card
                    endgame,   //Flag, if game is running endgame=false
                    trnOver,   //Flag, if turn is over=true 
                    error;
    
    Deck           deck;
    Player         *plyrPtr;
    Player         *plyrs;
    
    
    //Initialize Variables
    numPlyrs=0, curPlyr=0, cardChc=0;
    endgame=false, error=false, cPlay=false, unoFlag=false, trnOver=false;
    
    
    //Get # of Players:
    bool tryAgn=true;
    while(tryAgn){
        cout<<"How many Players? (Up to 4):";
        cin>>numPlyrs;
        if(numPlyrs<0||numPlyrs>4){
            cout<<"Invalid!"<<endl;
            cin>>numPlyrs;
        }
        else
            tryAgn=false;
    }
    plyrs=new Player[numPlyrs];
    for(int i=0; i<numPlyrs; i++){
        string name;
        cout<<"Enter Player "<<(i+1)<<"'s Name: ";
        cin>>name;
        plyrs[i].set(i,name);
        plyrs[i].deal(deck);
    }
    //fill the draw pile
    deck.filDraw();

    //play game
    do{//Main Game Loop
            //Set pointer to current player
            plyrPtr=&(plyrs[curPlyr]);
            //Process special cards played that affect current player
            prcCard(plyrPtr, deck, deck.getDis()); 
            cout<<"+----------------------------------------+"<<endl;
            cout<<"\t"<<plyrPtr->getName()<<"'s TURN!"<<endl;
            //Check if the player can play a card
            cPlay=plyrPtr->cPlyStat(deck.getDis());
            //Check if the player can call uno
            plyrPtr->unoStat(cPlay);
            //Display the current discard
            cout<<"Discard: ";
            cout<<deck.getDis()<<endl;
            //Display current player's hand
            plyrPtr->showHnd();
            //Display message, ask if player wants to call uno
            cout<<"Enter u To Call UNO or any other key to continue: "<<endl;
            //Get uno choice
            cin>>unoChc;
            //Uno actions
            uno(plyrPtr, deck, unoChc, cPlay);
            do{//Play Card Loop
                cin.clear();
               if(cPlay){  //Play A Card
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
                   if(valPlay(plyrPtr,deck, cardChc)){
                       plyrPtr->playCard(cardChc, deck);              //play card
                       trnOver=true;
                   }
                   else{
                       cout<<"Not a Valid Card!"<<endl;
                       trnOver=false;
                   }
                }
               else if(!cPlay){//Draw A Card if no valid cards in your hand
                    do{
                        cout<<"\nNo Valid Card to Play!"<<endl;
                        cout<<"Enter any key to continue"<<endl;
                        cin>>cont;
                        //Draw A Card
                        plyrPtr->recCrd(deck); //Add a card to players hand
                        cout<<"You Drew: ";
                        plyrPtr->shoLcrd();
                        cout<<endl;
                        //Check If The Card Just Drawn Can Be Played
                        bool can=valPlay(plyrPtr,deck,plyrPtr->getHndSz());
                        if(can){
                            //Play The Card
                            cout<<"Enter any key to Play it"<<endl;
                            cin>>cont;
                            plyrPtr->playIt(deck);
                            cPlay=true;
                            trnOver=true;
                        }
                    }while(!cPlay);
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
            if(deck.getDrSz()<10){
                deck.filDeck();                 //Fill the deck
                deck.filDraw();
                deck.shuffle();                 //Shuffle th e deck
            }
        curPlyr=setPlyr(deck.getDis(), curPlyr, numPlyrs);
    }while(!endgame);

    //clean up
    delete []plyrs;
    return 0;
}
//Function Definitions
//Set the current player
int setPlyr(Card &discard, int curPlyr, int players){
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
bool valPlay(Player *plyr, Deck &deck, int cardChc){
    Type pType=plyr->getType(cardChc);     //Hold player's card type
    Type dType=deck.getDisT();  //Hold discard card type
    char pCol=plyr->getCol(cardChc);    //Hold player's card color
    char dCol=deck.getdisC();   //Hold discard card color
    int  pNum=plyr->getNum(cardChc);    //Hold player's card number
    int  dNum=deck.getDiscN();    //Hold discard card number 
    //Number Card is played
    if(pType==NUMBER){
        //Card played matches discard color or number
        if(pCol==dCol||pNum==dNum){
            return true;
        }
        //Card played does not match discard color or number
        else return false;
    }
    //Special Card is played
    if(pType==SKIP||pType==REVERSE||pType==DRAW2){
        //Card played matches discard type or color
        if(pType==dType||pCol==dCol){
            return true;
        }
        //Card played does not match discard type or color
        return false;
    }
    //Wild is always valid
    if(pType==WILD||pType==WILD4)
        return true;

}



//PROCESS SPECIAL CARDS
void prcCard(Player *plyr, Deck &deck, Card &discard){
    char colChc;
    bool error=false;
    switch(discard.getType()){ //Switch on card type
        case(DRAW2)://Draw Two
            for(int i=0; i<2; i++){ 
                plyr->recCrd(deck);            //Add two cards to players hand
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
                plyr->recCrd(deck);//Add Four Cards to player's hand    
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
void uno(Player *plyr, Deck &deck, char unoChc, bool cPlay){
    bool uno=plyr->getUno();    //hold player uno status
    if(unoChc=='u'){//If Player calls Uno
        if(uno)//If Player has Uno
            cout<<"UNO!!!!"<<endl;//Display message
        else{//If Player does not have Uno
            if(plyr->getHndSz()>2){//If Player has > two cards
                cout<<"You still have "<<plyr->getHndSz()
                    <<" cards! NO UNO!"<<endl;//Display message
                }
            if(!cPlay){//If Player has no playable cards
                cout<<"You don't have a playable card!"
                        <<"NO UNO!"<<endl;//Display message
            }
        }
    }
    else if(uno&&unoChc!='u'){ //If Player doesn't call uno and has uno
        cout<<"You didn't call UNO! Draw 2 cards!"<<endl; //Message
        for(int i=0; i<2; i++){  //Draw 2 Cards
            plyr->recCrd(deck); //Add two cards to players hand
        }                                  //and remove them from draw pile
        cout<<endl;                        
        plyr->showHnd();
        plyr->setUno(false);          //unoFlag=false
    }
}

