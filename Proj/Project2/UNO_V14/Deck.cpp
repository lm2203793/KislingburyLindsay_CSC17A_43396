
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "Deck.h"
#include "Type.h"

//constructor
Deck::Deck(int players){
    filDeck();  
    hands=new vector<Card>[players];
    for(int i=0; i<players; i++){
        deal(hands[i]);
    }
    setDscrd();
    filDraw();
}
//fill the deck
void Deck::filDeck(){
    deck.push_back(Card(NUMBER,0,'r',"red",0));
    deck.push_back(Card(NUMBER,0,'g',"green",0));
    deck.push_back(Card(NUMBER,0,'b',"blue",0));
    deck.push_back(Card(NUMBER,0,'y',"yellow",0));
    //One through Nine: 2 of each color per number
    for(int i=0; i<2; i++){
        for(int j=1; j<=9; j++){
            deck.push_back(Card(NUMBER,j,'r',"red",j));
            deck.push_back(Card(NUMBER,j,'g',"green",j));
            deck.push_back(Card(NUMBER,j,'b',"blue",j));
            deck.push_back(Card(NUMBER,j,'y',"yellow",j));
        }
    }
    //Add Action Cards
    //Skip: 2 of each color
    for(int j=0; j<2; j++){
        deck.push_back(Card(SKIP,-1,'r',"red",20));
        deck.push_back(Card(SKIP,-1,'g',"green",20));
        deck.push_back(Card(SKIP,-1,'b',"blue",20));
        deck.push_back(Card(SKIP,-1,'y',"yellow",20));
    }
    //Reverse: 2 of each color
    for(int j=0; j<2; j++){
        deck.push_back(Card(REVERSE,-2,'r',"red",20));
        deck.push_back(Card(REVERSE,-2,'g',"green",20));
        deck.push_back(Card(REVERSE,-2,'b',"blue",20));
        deck.push_back(Card(REVERSE,-2,'y',"yellow",20));
    }
    //Draw Two: 2 of each color
    for(int j=0; j<2; j++){
        deck.push_back(Card(DRAW2,-3,'r',"red",20));
        deck.push_back(Card(DRAW2,-3,'g',"green",20));
        deck.push_back(Card(DRAW2,-3,'b',"blue",20));
        deck.push_back(Card(DRAW2,-3,'y',"yellow",20));
    }
    //Wild: 4
    for(int j=0; j<4; j++) deck.push_back(Card(WILD,-4,'X',"X",50));
    //Wild Draw Four: 4
    for(int j=0; j<4; j++) deck.push_back(Card(WILD4,-5,'X',"X",50));  

    
}
//shuffle the deck
void Deck::shuffle(){
    int size=deck.size();
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0; i<size-1; i++) {
        int j=i+rand()%(size-i);
        iter_swap(deck.begin()+i, deck.begin()+j);
   }
    cout<<"shuffled deck: "<<endl;
    for(int i=0; i<size; i++){
        cout<<deck[i]<<endl;
    }
}
//swap

//Discard
void Deck::setDscrd(){
    discard=deck.back();     //Flip the last card over to start discard pile
    deck.pop_back();         //Remove that card from the deck
}
//fill draw pile
void Deck::filDraw(){
    for(int i=0; i<deck.size(); i++)
        draw.push_back(deck[i]);
    //Remove cards added to the draw pile from the deck
    for(int i=0; i<draw.size(); i++)
        deck.pop_back();
}
//deal a hand
void Deck::deal(vector<Card> &hand){
    for(int i=0; i<7; i++){
        hand.push_back(deck[i]);
    }
    //remove those cards from the deck
    for(int i=0; i<7; i++){
        deck.pop_back();
    }
}
//Take a card from draw pile
void Deck::drawCard(int plyr){
    Card add=draw.back();
    hands[plyr].push_back(add);
    draw.pop_back(); 
}


//Change discard
void Deck::chngDscrd(Card disc){
    discard=disc;
}




void Deck::showCard(int plyr, int index){
    Card card=hands[plyr][index];
    //Display the card player drew
    cout<<"You Drew: ";
    cout<<card;    
}


//Show Player's hand
void Deck::showHnd(int plyr){
    for(int i=0; i<hands[plyr].size(); i++){//Loop on Player's hand size
        cout<<right;
        cout<<setw(3)<<i<<setw(2)<<": ";
        cout<<left;
        cout<<hands[plyr][i];
        if((i+1)%2==0)cout<<endl;
    }
    cout<<endl;
}


//Play a card
Card Deck::playCard(int plyr, int index){
    Card card=hands[plyr][index];  //hold the card chosen
    //Take Played Card Out of Player's Hand
    hands[plyr].erase(hands[plyr].begin()+index);
    return card;
}

void Deck::prcCard(int curPlyr){
    char colChc;
    bool error=false;
    switch(discard.getType()){ //Switch on card type
        case(DRAW2)://Draw Two
            for(int i=0; i<2; i++){ 
                deck.drawCard(curPlyr); //Add two cards to players hand
            }                        //and Remove them from draw pile
            break;
        case(WILD)://Wild
            do{//Input Validation
                cout<<"\nChoose A Color (r,g,b,y): "; 
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
                deck.drawCard(curPlyr); //Add Four Cards to player's hand    
            }                        //and Remove them from draw pile
            do{
                cout<<"\n Choose A Color (r,g,b,y): ";//Get Player Color Choice
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
