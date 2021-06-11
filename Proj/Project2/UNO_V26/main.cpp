/* 
 * File:   main.cpp
 * Author: Lindsay Kislingbury
 * Purpose: UNO V13
 * FINAL VERSION 
 * Created on June 2, 2021, 8:07 PM
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib>  //C Standard Library
#include <vector>   //Vector Library
#include <string>   //String Library
#include <fstream>  //File Stream Library
#include <typeinfo> //TypeId Library
//User Libraries    
#include "Deck.h"    //Deck Class
#include "Player.h"  //Player Class
#include "Hplayer.h" //human player
#include "Cplayer.h" //computer player
using namespace std; //Standard Name space

//Function Prototypes
void prcCard(Player *, Deck &, Card &);     //Process Draw Cards
bool unoFlag(const vector<Card> *, bool);   //Uno Status 
void uno(Player *, Deck &, char, bool);     //Uno Actions
bool valPlay(Player *, Deck &, int);        //Validate Play
int setPlyr(Card &, int, int);              //Set Current Player
void wrtScr(Player **, int);                //Write Scores To File 
void rdScr();                               //Display Scores From File
void plyGame();                             //Main Game

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char strtChc;           //Start menu choice   
    bool error;             //Input Validation
    do{//Main Program Loop
        do{
            //Display Menu Options
            cout<<"UNO!"<<endl;
            cout<<"1: Play Game\n2: View Scores\nQ: Quit"<<endl;
            cin>>strtChc;
            strtChc=toupper(strtChc);
            //Input Validation
            if(strtChc=='1'||strtChc=='2'||strtChc=='Q') 
                error=false;
            else{
                error=true;
                cout<<"Invalid Choice!"<<endl;
            }
            cin.clear();
        }while(!cin||cin.fail()||error);
        switch(strtChc){ //Switch on Start Menu Choice
            case '1'://Case 1
                    plyGame();//Play Game
                break;
            case '2'://Case 2
                   rdScr();//Show Scores
                break;
            case 'Q'://Case Q
                cout<<"Exiting Program";
                break;
        }
    }while(strtChc!='Q');

    return 0;
}
//****************************************************************************//
//                      Function Definitions                                  //
//MAIN GAME
void plyGame(){
    int             numPlyrs,  //Number of players
                    curPlyr,   //Current player
                    cardChc;   //Card choice
    char            cont,      //User input to continue after message
                    unoChc;    //Player choice to call uno or play a card
    bool            unoFlag,   //Flag, if player called uno
                    cPlay,     //Flag, if player has a playable card
                    endgame,   //Flag, if game is running endgame=false
                    trnOver,   //Flag, if turn is over=true 
                    error,     //Input Validation Error Checking 
                    tryAgn;
    Deck            deck;      //Deck object
    Player         *plyrPtr;   //Pointer to individual player
    Player         **plyrs;    //Pointer to array of players
  

    //Initialize Variables
    numPlyrs=0, curPlyr=0, cardChc=0;
    endgame=false, error=false, cPlay=false, unoFlag=false, trnOver=false;

    //SETUP GAME
    //Input # of Players:
    tryAgn=true;   //Input Validation
    while(tryAgn){
        cout<<"How many Players? (Up to 4): ";
        cin>>numPlyrs;
        if(numPlyrs>0&&numPlyrs<=4&&cin&&!cin.fail()){
            tryAgn=false;
        }
        else{
            cin.clear();
            cin.ignore();
            cout<<"Invalid!"<<endl;
        }
    }
    //Allocate memory for array of Players
    plyrs=new Player*[numPlyrs];
    for(int i=0; i<numPlyrs; i++){//Loop on # of players
        char botChc;
        tryAgn=true;
        while(tryAgn){
            cout<<"Player "<<(i+1)<<": Human or Bot? (h or b): ";
            cin>>botChc;     //Input human or bot choice
            if(botChc=='b'||botChc=='h'&&cin&&!cin.fail()){
                tryAgn=false;
            }
            else{
                cin.clear();
                cin.ignore();
                cout<<"Invalid!"<<endl;
            }
        }
        if(botChc=='h'){ //If choice is human
            Hplayer *temp=new Hplayer;//Allocate memory for an Hplayer object
            plyrs[i]=temp;         //Set pointer in plyrs at i to Hplayer object
        }
        else if(botChc=='b'){ //If choice is bot
            int difChc;
            Cplayer *temp=new Cplayer;//Allocate memory for a Cplayer object
            plyrs[i]=temp;        //Set pointer in plyrs at i to Hplayer object
            tryAgn=true;
            while(tryAgn){
                cout<<"\nDifficulty?\n1: Dumb Bot    2: Lucky Bot    "
                        <<"3: Smart Bot\nEnter 1, 2 or 3: "; 
                cin>>difChc;          //Input difficulty level 
                if(difChc<0||difChc>3||!cin||cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Invalid!"<<endl;
                }
                else tryAgn=false;
            }
            temp->setHrd(difChc); //Set cPlayer object difficulty level
        }
        string name;
        cout<<"Enter Player "<<(i+1)<<"'s Name: "; 
        cin.clear();
        cin.ignore();
        getline(cin, name);           //Input player name
        plyrs[i]->set(i,name);
        for(int j=0; j<7; j++){       //Loop on Hand size, 7
            Card temp=deck.dealCrds();//Deal a card to a temporary Card object
            plyrs[i]->recCrd(temp);   //Pass that card to the player's hand
        }
    }
    
    //PLAY GAME!
    do{//Main Game Loop
            //Set pointer to current player
            plyrPtr=plyrs[curPlyr];
            //Store hand size
            plyrPtr->setHnSz();
            //Process special cards played that affect current player
            prcCard(plyrPtr, deck, deck.getDis()); 
            cout<<"\n+----------------------------------------+"<<endl;
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
            if(typeid(*(plyrPtr))==typeid(Hplayer)){ //If player is Hplayer obj
                //Display message, prompt for uno choice
                cout<<"Enter u To Call UNO or any other key to continue: "<<endl;
                cin>>unoChc;
            }
            else{  //If player is Cplayer obj
                if(plyrPtr->getUno()){ //If uno status is true
                    unoChc='u';        //bot calls uno
                }
                else{ //If uno status is false
                    unoChc='a';
                    cout<<plyrPtr->getName()<<" doesn't call uno."<<endl; //msg
                }
            }
            //Uno actions
            uno(plyrPtr, deck, unoChc, cPlay);
            do{//Play Card Loop
                cin.clear();
                if(cPlay){//If can play status is true
                    //Play A Card
                    deck.chngDisc(plyrPtr->getPcrd(deck.getDis()));
                    trnOver=true; //Turn is over
                }
                else if(!cPlay){//If can play status is false
                    do{//While can play status is false
                        bool validate=false; //Set validate to false
                        if(typeid(*(plyrPtr))==typeid(Hplayer)){ //If human
                            cout<<"\nNo Valid Card to Play!"<<endl; //msg
                            cout<<"Enter any key to continue"<<endl;
                            cin>>cont;
                        }
                        else{ //If bot
                            cout<<plyrPtr->getName()
                                    <<" has no valid card to play!"<<endl;//msg
                        }
                        //Add a card to players hand
                        plyrPtr->recCrd(deck.dealCrds()); 
                        //Return validate 
                        validate=plyrPtr->valLstCrd(deck.getDis());
                        //Display card drawn
                        cout<<plyrPtr->getName()<<" Drew: ";
                        plyrPtr->shoLstCrd();
                        cout<<endl;
                        if(validate){ //If validate is true
                            if(typeid(*(plyrPtr))==typeid(Hplayer)){ //If human
                                cout<<"Enter any key to Play it"<<endl; //msg
                                cin.clear();
                                cin.ignore();
                                cin>>cont;
                            }
                            //Play the card just drawn and set discard
                            deck.chngDisc(plyrPtr->playTop()); 
                            cPlay=true;  //Set can play to true
                            trnOver=true;//Set turnOver to true
                        }
                    }while(!cPlay);
                }
                if(plyrPtr->getHndSz()==0){//If a player has 0 cards
                    plyrPtr->setWin();     //Set winner
                    //Store Scores in structure
                    for(int i=0; i<numPlyrs; i++){
                        plyrs[i]->setScr();
                    }
                    //Display End Game Message
                    cout<<"\n+***************************************+"<<endl;
                    cout<<"\t\tEND GAME!!"<<endl;
                    cout<<plyrPtr->getName()<<" WINS!!!!"<<endl;
                    for(int i=0; i<numPlyrs; i++){
                        plyrs[i]->prntScr();
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
}
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


//Process Draw cards
void prcCard(Player *plyr,Deck &deck, Card &discard){
    //Switch on card type
    switch(discard.getType()){ 
        case(DRAW2)://Draw Two
            for(int i=0; i<2; i++){ 
                plyr->recCrd(deck.dealCrds()); //Add two cards to players hand
            }                                  //and Remove them from draw pile
            break;
        case(WILD4)://Wild Draw Four
            for(int i=0; i<4; i++){          
                plyr->recCrd(deck.dealCrds());//Add Four Cards to player's hand    
            }                                 //and Remove them from draw pile
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
void wrtScr(Player **plyrs, int numPlyrs){
    GmScore temp;   //Hold players scores
    fstream scrs;   //Fstream object
    scrs.open("scores.txt", ios::app); //Open scores file
    scrs<<"+-------------------------------+"<<endl;
    scrs<<"           GAME SCORE:          \n";
    scrs<<"Players: ";                 
    for(int i=0; i<numPlyrs; i++){    //Write names of all players for this game
        temp=plyrs[i]->getScr();
        scrs<<temp.nm;
        if(i!=numPlyrs-1) scrs<<", ";
    }
    scrs<<"\n";
    for(int i=0; i<numPlyrs; i++){   //Write the winner and loser
        temp=plyrs[i]->getScr();
        if(temp.win) scrs<<"Winner: ";
        else scrs<<"Loser: ";
        scrs<<temp.nm<<endl;
    }
    scrs<<"\n";
   for(int i=0; i<numPlyrs; i++){    //Write each player's largest hand
        temp=plyrs[i]->getScr();
        scrs<<temp.nm<<"'s Largest Hand: "<<temp.lrgHnd<<endl;
    }
    scrs<<"+-------------------------------+"<<endl;
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