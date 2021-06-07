/* 
 * File:   main.cpp
 * Author: Lindsay
 * Purpose: UNO VERSION 6: FINAL VERSION
 * Created on June 1, 2021, 5:15 PM
 */

//System Libraries
#include <cstdlib>  //C Standard Library
#include <iostream> //I/O Library
#include <iomanip>  //Format Library
#include <vector>   //Vector Library
#include <ctime>    //Time Library
#include <fstream>  //I/O File Stream
#include <string>   //String Library
using namespace std;

//User Libraries
enum Type{NUMBER,SKIP,REVERSE,
            DRAW2,WILD,WILD4};       //Card Types
#include "Player.h"                  //Player and Card Structures
#include "Scores.h"                  //Scores Structure


//Function Prototypes
//GamePlay Functions

//void shuffle(vector<Card> &, Card &);           //SHUFFLE AND CREATE DISCARD PILE
Player *deal(vector<Card> &, int);              //DEAL HANDS
void drawCrd(vector<Card> *, vector<Card> &);   //DRAW CARD
void playCrd(vector<Card> *, Card &, int);      //PLAY A CARD w/ card choices
void playCrd(vector<Card> *, Card &);           //PLAY A CARD card just drawn
void showHnd(vector<Card> *);                   //DISPLAY PLAYER'S HAND
void showCrd(const Card);                       //DISPLAY A CARD
bool valPlay(vector<Card> *, Card);             //DETERMINE PLAYABLE CARD
bool valPlay(Card, Card);                       //DETERMINE CARD PLAYED IS VALID
void play();                                    //PLAY GAME MAIN FUNCTION
int setPlyr(Card, int, int);                    //SET THE CURRENT PLAYER             
void prcCard(vector<Card>*,vector<Card>&,Card&);//PROCESS SPECIAL CARDS
bool uno(vector<Card> *, bool);                 //UNO STATUS
//Scoring Functions
void calcScr(Player *, int, int);               //CALCULATE WINNER'S SCORE
void lrgHnd(Player *, int );                    //CALCULATE LARGEST HAND
//Functions For Writing To File
Scores *fillScrs(Player *, int);                //FILL SCORES STRUCTURE
void wrtBin(Scores *, int);                     //WRITE TO BINARY FILE  
void showScrs();                                //DISPLAY PAST SCORES

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
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
                    play();//Play Game
                break;
            case '2'://Case 2
                   showScrs();//Show Scores
                break;
            case 'Q'://Case Q
                cout<<"Exiting Program";
                break;
        }
    }while(strtChc!='Q');

    return 0;
}
//Function Definitions
/*****************************************************************************/
/*                            GAMEPLAY                                        */
//PLAY GAME MAIN FUNCTION
void play(){
    //Declare Variables
    Player          *hands;    //Pointer to an array of player hand vectors
    vector<Card>    *handPtr;  //Pointer to current player's hand   
   // vector<Card>    draw,      //Draw Pile
   //                 deck;      //The Entire Deck of Cards
   // Card            discard;   //Discard Pile
   // int             players,   //Number of players
   //                 curPlyr,   //Current player
   //                 cardChc;   //Card choice
    char            cont,      //User input to continue after message
                    chc;       //Player choice to call uno or play a card
    bool            unoFlag,   //Flag, if player called uno
                    endgame,   //Flag, if game is running endgame=false
                    error,     //Flag for input validation
                    canPlay,   //Flag if player has a playable card 
                    trnOver;   //Flag, if turn is over=true
    Scores          *scores;   //Hold end game scores
    
    //Initialize Variables
    players=0, curPlyr=0, cardChc=0;
    endgame=false, error=false, canPlay=false, unoFlag=false, trnOver=false;
    
    //Get # of Players:
    do{
        cout<<"How many players? (2 to 10 Players): ";
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
    cout<<endl;
    
    //Setup Cards:
    deck=filDeck();                 //Fill the deck
    shuffle(deck,discard);          //Shuffle the deck
    hands=deal(deck, players);      //Allocate Memory and deal Player hands
    
    //Get Player Names:
    cin.ignore();                           //Clear buffer
    for(int p=0; p<players; p++){           //Loop on # of players
        do{
            string name;
            cout<<"Enter Player "<<p+1<<"'s Name: ";
            getline(cin, name);               //Get name
            if(name.length()>25){
                cout<<"Error! Name must be less than 25 characters"<<endl;
                cin.clear();
                cin.ignore();
                error=true;
            }
            hands[p].player=name;
        }while(error);
    }

    //Fill Draw Pile
    for(int i=0; i<deck.size(); i++)
        draw.push_back(deck[i]);
    //Remove cards added to the draw pile from the deck
    for(int i=0; i<draw.size(); i++)
        deck.pop_back();
    
    do{//Main Game Loop
        do{//Player Turn Loop
            hands[curPlyr].numHnds++;
            hands[curPlyr].hndSzs.push_back(hands[curPlyr].hand.size());
            //Set pointer to current player hand
            handPtr=&(hands[curPlyr].hand); 
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
                    if(hands[curPlyr].hand.size()>2){//If Player has > two cards
                        cout<<"You still have "<<hands[curPlyr].hand.size()
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
                       if(cardChc<0||cardChc>hands[curPlyr].hand.size()-1
                               ||!cin||cin.fail()){
                           error=true;
                           cout<<"Invalid Choice!"<<endl;
                       }
                   }while(!cin||cin.fail()||error);
                   //Validate Play
                   if(valPlay(hands[curPlyr].hand[cardChc], discard)){
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
                if(hands[curPlyr].hand.size()==0){
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
    
    //Fill Scores
    scores=fillScrs(hands, players);
    
    //Write scores to file
   wrtBin(scores, players);

    //clean up
    delete []hands;
}



//DEAL HANDS
Player *deal(vector<Card> &deck, int players){
    //Allocate memory for array of player hands
    Player *hands=new Player[players];

    //Deal player the last 7 cards in the shuffled deck
    for(int p=0; p<players; p++){
        for(int i=deck.size()-1; i>deck.size()-8; i--)
            hands[p].hand.push_back(deck[i]);
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
        case(NUMBER): cout<<add.num<<" "<<add.colName<<" "; break;
        case(SKIP): cout<<"SKIP "<<add.colName<<endl; break;
        case(REVERSE): cout<<"REVERSE "<<add.colName<<endl; break;
        case(DRAW2): cout<<"DRAW-2 "<<add.colName<<endl; break;
        case(WILD): cout<<"WILD "<<endl; break;
        case(WILD4): cout<<"WILD-DRAW-4 "<<endl; break;
    }       
}
//PLAY A CARD with card choices
void playCrd(vector<Card> *cards, Card &discard, int cardChc){
    Card card;  //Temporary card variable to hold the card chosen
    //Player Chooses a Card
    card=cards->at(cardChc); 
    //Put Played Card on Top of Discard Pile
    discard=card;
    //Take Played Card Out of Player's Hand
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
void showHnd(vector<Card> *cards){
    for(int i=0; i<cards->size(); i++){//Loop on Player's hand size
        cout<<right;
        cout<<setw(3)<<i<<setw(2)<<": ";
        cout<<left;
        //If the card is a number card, display number and color
        if(cards->at(i).type==NUMBER){
            cout<<setw(2)<<"[  "<<left<<setw(2)<<cards->at(i).num<<right<<setw(6)
                    <<cards->at(i).colName<<setw(3)<<"   ]";
        }
        //Else display type and color
        else{     
            if(cards->at(i).type==SKIP){
                cout<<left<<setw(1)<<"["<<setw(7)<<"SKIP"<<right<<setw(6)
                        <<cards->at(i).colName<<setw(1)<<"]";
            }
            else if(cards->at(i).type==REVERSE){
                cout<<left<<setw(1)<<"["<<setw(7)<<"REVERSE"<<right<<setw(6)
                        <<cards->at(i).colName<<setw(1)<<"]";
            }
            else if(cards->at(i).type==DRAW2){
                cout<<left<<setw(1)<<"["<<setw(7)<<"DRAW-2"<<right<<setw(6)
                        <<cards->at(i).colName<<setw(1)<<"]";
            }
            else if(cards->at(i).type==WILD)
                cout<<"[    WILD     ]";
            else if(cards->at(i).type==WILD4)
                cout<<"[  WILD-DRAW-4]";
        }
        if((i+1)%2==0)cout<<endl;
    }
    cout<<endl;
}

//SET THE CURRENT PLAYER
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
    //Skip
    if(discard.type==SKIP)  //If Skip is played, skip a player
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
    //Wild is always valid
    if(card.type==WILD||card.type==WILD4)
        valid=true;

    //Return valid status of card played
    return valid;
}

//DETERMINE WHETHER PLAYER HAS A PLAYABLE CARD
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

//PROCESS SPECIAL CARDS
void prcCard(vector<Card> *cards, vector<Card> &draw, Card &discard){
    char colChc;
    bool error=false;
    switch(discard.type){ //Switch on card type
        case(DRAW2)://Draw Two
            for(int i=0; i<2; i++){ 
                cards->push_back(draw.back());//Add Two Cards to Player's hand
                draw.pop_back();             //Remove those cards from draw pile 
            }   
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
            colChc=tolower(colChc);//Ensure that color choice is lowercase
            discard.color=colChc;  //Change the color of discard 
            //Set the name of discard to reflect new color 
            discard.colName=(colChc=='r')?"red":
                            (colChc=='g')?"green":
                            (colChc=='b')?"blue":"yellow";
            break;
        case(WILD4)://Wild Draw Four
            for(int i=0; i<4; i++){          
                cards->push_back(draw.back());//Add Four Cards to player's hand
                draw.pop_back();             //Remove those cards from draw pile        
            }
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
            discard.color=colChc;  //Change the color of discard
            //Set the name of discard to reflect new color 
            discard.colName=(colChc=='r')?"red":
                            (colChc=='g')?"green":
                            (colChc=='b')?"blue":"yellow";
            break;
    }
}

//UNO STATUS
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
//CALCULATE WINNER'S SCORE
void calcScr(Player *hands, int players, int curPlyr){ 
    int score=0;    //Hold total score
    for(int p=0; p<players; p++){//Loop on # of players
        if(p!=curPlyr){//If not the winner     
            for(int h=0; h<hands[p].hand.size(); h++){ //Loop on hand size
                score+=hands[p].hand[h].points; //Add all card points
            }
        }
    }
    //Store total score
    hands[curPlyr].gmScr=score;
}

//CALCULATE LARGEST HAND
void lrgHnd(Player *hands, int players){
    int max=0;     //Hold max # of hands 
    for(int p=0; p<players; p++){
        max=0;     //Set Max to 0
        int size=hands[p].hndSzs.size(); //Store # of hands for loop
        for(int h=0; h<size; h++){       //Loop on # of hands
            if(max<hands[p].hndSzs[h]){  //If max is less than handsize
                max=hands[p].hndSzs[h];  //Store handsize in max
            }
            hands[p].lrgHnd=max;         //Store max in largest hand
        }
    }
}

//FILL SCORES STRUCTURE
Scores *fillScrs(Player *hands, int players){
    Scores *scores=new Scores; //Allocate Memory for Scores Structure
     int numHnds=0;            //Number of hands played
     int lrgHnd;               //Largest hand for any player
    
    //Store # of players
     scores->numPlyrs=players;
    //Store Winner's Name and Score
    for(int p=0; p<players; p++){   //Loop on # of players
        if (hands[p].winner==true){ //If player is the winner
            //Store winner's name
            for(int i=0; i<hands[p].player.size(); i++){
                scores->winner[i]=hands[p].player[i];
            }
            //Store Winning Score
            scores->score=hands[p].gmScr;
        }
    }
    
    //Store Number of Hands Played For All Players
    for(int p=0; p<players; p++)   //Loop on # of Players
        numHnds+=hands[p].numHnds; //Add # of hands from each player
    //Store # of Hands Played
    scores->numHnds=numHnds;
    
    //Store Largest Hand of the Game
    for(int p=0; p<players; p++){   //Loop on # of players
        if(hands[p].lrgHnd>lrgHnd)  //If largest hand of player is > current max
            lrgHnd=hands[p].lrgHnd; //max=player's largest hand
    }
    scores->lrgHnd=lrgHnd;          //Store max largest hand 
    
    return scores;
}

//WRITE TO BINARY FILE  
void wrtBin(Scores *scores, int players){
    fstream in; //fstream object
    //Open binary file for output and append
    in.open("scores.dat", ios::app|ios::out|ios::binary);
    //Write Winner's Name
    in.write(scores->winner,25);
    //Write Other Game Data
    in.write(reinterpret_cast<char *>(&scores->lrgHnd),sizeof(int));
    in.write(reinterpret_cast<char *>(&scores->numHnds),sizeof(int));
    in.write(reinterpret_cast<char *>(&scores->numPlyrs),sizeof(int));
    in.write(reinterpret_cast<char *>(&scores->score),sizeof(int));
    //Close File
    in.close();
}

//DISPLAY PAST SCORES
void showScrs(){
    int counter=0; //Counter for Records read
    Scores scores; //Hold Scores as they are read
    fstream out;   //fstream object
    
    //Open binary file for input
    out.open("scores.dat", ios::in|ios::binary);
    //Read Winner's Name
    out.read(scores.winner,25);
    //Read Other Game Data
    out.read(reinterpret_cast<char *>(&scores.lrgHnd),sizeof(int));
    out.read(reinterpret_cast<char *>(&scores.numHnds),sizeof(int));
    out.read(reinterpret_cast<char *>(&scores.numPlyrs),sizeof(int));
    out.read(reinterpret_cast<char *>(&scores.score),sizeof(int));
    
    cout<<"\t\tPrevious Game Scores!"<<endl;
    while(!out.eof()){ //Continue until end of the file is reached
        //Print Game Data
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"Game #"<<counter+1<<endl;
        cout<<"Winner: "<<scores.winner<<endl;
        cout<<"Largest Hand: "<<scores.lrgHnd<<endl;
        cout<<"Number of Hands Played: "<<scores.numHnds<<endl;
        cout<<"Number of Players: "<<scores.numPlyrs<<endl;
        cout<<"Winner's Score: "<<scores.score<<endl;
        //Continue reading hand
        out.read(scores.winner,25);
        out.read(reinterpret_cast<char *>(&scores.lrgHnd),sizeof(int));
        out.read(reinterpret_cast<char *>(&scores.numHnds),sizeof(int));
        out.read(reinterpret_cast<char *>(&scores.numPlyrs),sizeof(int));
        out.read(reinterpret_cast<char *>(&scores.score),sizeof(int));
        cout<<"+----------------------------------------------+"<<endl;
        //Increment Counter
        counter++;   
    }
}
