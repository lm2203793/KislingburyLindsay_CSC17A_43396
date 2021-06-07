/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: UNO V13
 *          //redid everything. now it works better. also classes make sense
 * Created on June 2, 2021, 8:07 PM
 */
//System Libraries
#include <iostream> //I/O Library
#include <cstdlib>  //C Standard Library
#include <vector>   //Vector Library
#include <string>   //String Library
#include <fstream>  //File Stream Library
//User Libraries
#include "Deck.h"   //Deck Class
#include "Player.h" //Player Class
using namespace std;//Standard Name space
//Function Prototypes
void prcCard(Player *, Deck &, Card &);             //Process Card
bool unoFlag(const vector<Card> *, bool);           //Uno Status 
void uno(Player *, Deck &, char, bool);             //Uno Actions
bool valPlay(Player *, Deck &, int);                //Validate Play
int setPlyr(Card &, int, int);                      //Set Current Player
void wrtScr(Player *, int);                         //Write Scores To File 
void rdScr();                                       //Display Scores From File

//Execution Begins Here!
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
    
 //  rdScr();
    
    //Get # of Players:
    cout<<"How many Players?: ";
    cin>>numPlyrs;
    cin.clear();
    cin.ignore();
    plyrs=new Player[numPlyrs];
    for(int i=0; i<numPlyrs; i++){
        string name;
        cout<<"Enter Player "<<(i+1)<<"'s Name: ";
        getline(cin, name);
        plyrs[i].set(i,name);
        cout<<plyrs[i].getName()<<endl;
        for(int j=0; j<7; j++){
            Card temp=deck.dealCrds();
            plyrs[i].recCrd(temp);
        }
    }
    
    
    
    

    //play game
    do{//Main Game Loop
            //Set pointer to current player
            plyrPtr=&(plyrs[curPlyr]);
            //Store hand size
            plyrPtr->setHnSz();
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
                    deck.chngDisc(plyrPtr->getPcrd(deck.getDis()));
                    trnOver=true;
                }
               else if(!cPlay){//Draw A Card if no valid cards in your hand
                    do{
                        bool validate=false;
                        cout<<"\nNo Valid Card to Play!"<<endl;
                        cout<<"Enter any key to continue"<<endl;
                        cin>>cont;
                        //Draw A Card
                        //Add a card to players hand, returns if that card is valid
                        plyrPtr->recCrd(deck.dealCrds()); 
                        validate=plyrPtr->valLstCrd(deck.getDis());
                        cout<<"You Drew: ";
                        plyrPtr->shoLstCrd();
                        cout<<endl;
                        if(validate){
                            //Play The Card
                            cout<<"Enter any key to Play it"<<endl;
                            cin>>cont;
                            //Play the card just drawn and set discard
                            deck.chngDisc(plyrPtr->playTop()); 
                            cPlay=true;
                            trnOver=true;
                        }
                    }while(!cPlay);
                }
                //If a player has 0 cards
                if(plyrPtr->getHndSz()==0){
                    //Set the winner
                    plyrPtr->setWin();
                    //Store Scores in structure
                    for(int i=0; i<numPlyrs; i++){
                        plyrs[i].setScr();
                    }
                    //Display End Game Message
                    cout<<"+***************************************+"<<endl;
                    cout<<"\t\tEND GAME!!"<<endl;
                    cout<<plyrPtr->getName()<<" WINS!!!!"<<endl;
                    for(int i=0; i<numPlyrs; i++){
                        plyrs[i].prntScr();
                    }
                    cout<<"+***************************************+"<<endl;
                    //End Game
                    endgame=true;
                }
            }while(!trnOver);
        //Set the current player
        curPlyr=setPlyr(deck.getDis(), curPlyr, numPlyrs);
    }while(!endgame);
    //Write scores to game structure
    wrtScr(plyrs, numPlyrs);
    //clean up
    delete []plyrs;
    
    return 0;
}
//****************************************************************************//
//                      Function Definitions                                  //

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


//Process Special Cards
void prcCard(Player *plyr,Deck &deck, Card &discard){
    char colChc;        //Hold Player Color Choice
    bool error=false;   //Input Validation
    //Switch on card type
    switch(discard.getType()){ 
        case(DRAW2)://Draw Two
            for(int i=0; i<2; i++){ 
                plyr->recCrd(deck.dealCrds()); //Add two cards to players hand
            }                                  //and Remove them from draw pile
            break;
        case(WILD)://Wild
            do{//Input Validation
                cout<<"Choose A Color (r,g,b,y): "; 
                cin>>colChc;        //Get Player Color Choice
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
                plyr->recCrd(deck.dealCrds());//Add Four Cards to player's hand    
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
            colChc=tolower(colChc);    //Ensure that color choice is lowercase
            discard.setColor(colChc);  //Change the color of discard 
            break;
    }
}

//Uno actions
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
            plyr->recCrd(deck.dealCrds()); //Add two cards to players hand
        }                       //and remove them from draw pile
        cout<<endl;                        
        plyr->showHnd();        //Show player's hand
        plyr->setUno(false);    //unoFlag=false
    }
}
//Write Scores To file
void wrtScr(Player *plyrs, int numPlyrs){
    GmScore temp;   //Hold players scores
    fstream scrs;   //Fstream object
    scrs.open("scores.txt", ios::app); //Open scores file
    scrs<<"Players: ";                 
    for(int i=0; i<numPlyrs; i++){    //Write names of all players for this game
        temp=plyrs[i].getScr();
        scrs<<temp.nm;
        if(i!=numPlyrs-1) scrs<<", ";
    }
    scrs<<"\n";
    for(int i=0; i<numPlyrs; i++){   //Write the winner and loser
        temp=plyrs[i].getScr();
        if(temp.win) scrs<<"Winner: ";
        else scrs<<"Loser: ";
        scrs<<temp.nm<<endl;
    }
    scrs<<"\n";
   for(int i=0; i<numPlyrs; i++){    //Write each player's largest hand
        temp=plyrs[i].getScr();
        scrs<<temp.nm<<"'s Largest Hand: "<<temp.lrgHnd<<endl;
    }
    scrs<<"\n";
    scrs.close();                   //Close scores File
}

//Read Scores From File
void rdScr(){
    string line;    //Hold each line of input
    fstream scrs;   //Fstream object
    scrs.open("scores.txt"); //Open scores file
    while (getline(scrs,line)){ //Read in each line until end
        cout << line << "\n";   //Print the line
    }
    scrs.close();               //Close scores File
}