/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: UNO V12 start building classes
 *          Card, Deck and Player classes created
 * Created on June 2, 2021, 8:07 PM
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Deck.h"
#include "Player.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    int             numPlyrs,   //Number of players
                    curPlyr,   //Current player
                    cardChc;   //Card choice
    char            cont,      //User input to continue after message
                    chc;       //Player choice to call uno or play a card
    bool            unoFlag,   //Flag, if player called uno
                    endgame,   //Flag, if game is running endgame=false
                    canPlay,   //Flag if player has a playable card 
                    trnOver,   //Flag, if turn is over=true 
                    error;
    
    Deck            deck;
    Player          *players;
    
    
    //Initialize Variables
    numPlyrs=0, curPlyr=0, cardChc=0;
    endgame=false, error=false, canPlay=false, unoFlag=false, trnOver=false;
    
    //Get # of Players:
    cout<<"How many Players?: ";
    cin>>numPlyrs;
    players=new Player[numPlyrs];
    for(int i=0; i<numPlyrs; i++){
        string name;
        cout<<"Enter Player "<<(i+1)<<"'s Name: ";
        cin>>name;
        players[i].set(i,deck.deal(),name);
    }
    for(int i=0; i<numPlyrs; i++){
        cout<<players[i].getName()<<" "<<players[i].getNum()<<endl;
    }
    //create draw and discard
    deck.setDscrd();
    deck.filDraw();
    
    do{//Main Game Loop
        do{//Player Turn Loop1
            //Process special cards played that affect current player
            prcCard(handPtr, draw, discard); 
            cout<<"+----------------------------------------+"<<endl;
            cout<<"\t"<<hands[curPlyr].player<<"'s TURN!"<<endl;
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
                if(unoFlag)//If Player has Uno
                    cout<<"UNO!!!!"<<endl;//Display message
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
                    cout<<endl;
                    showHnd(handPtr);       //Display Hand
                    unoFlag=false;          //unoFlag=false
                }
            do{//Play Card Loop
                cin.clear();
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
                   //Validate Play
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
                        cout<<"\nNo Valid Card to Play!"<<endl;
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
                //If a player has 0 cards
                if(hands[curPlyr].data.size()==0){
                    //Set the winner
                    hands[curPlyr].winner=true;
                    //Calculate Winner's Score
                    calcScr(hands,players,curPlyr);
                    //Calculate largest hand for both players
                    lrgHnd(hands, players);
                    //Display End Game Message
                    cout<<"+***************************************+"<<endl;
                    cout<<"\t\tEND GAME!!"<<endl;
                    cout<<hands[curPlyr].player<<" WINS!!!!"<<endl;
                    cout<<hands[curPlyr].player<<"'s SCORE: ";
                    cout<<hands[curPlyr].gmScr<<endl;
                    cout<<"+***************************************+"<<endl;
                    //End Game
                    endgame=true;
                }
            }while(!trnOver);
            //If the deck is running low, shuffle and fill deck
            if(deck.size()<10){
                deck=filDeck();                 //Fill the deck
                shuffle(deck,discard);          //Shuffle the deck
            }
        }while(error);//input validation
        curPlyr=setPlyr(discard, curPlyr, players);
    }while(!endgame);

 
    return 0;
}

