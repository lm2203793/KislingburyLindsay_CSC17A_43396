/* 
 * File:   hPlayer.h
 * Author: Lindsay Kislingbury
 * Purpose: Hplayer Member Function Definitions
 * Created on June 5, 2021, 5:26 PM
 */
#include <iostream>
#include "Player.h"
#include "Hplayer.h"
#include "Type.h"
using namespace std;

//Overrides base class getPcrd function
//Plays a card with exception for bad input
Card Hplayer::getPcrd(Card &disCrd){
    int chc;            //Hold card choice        
    Card temp;          //Temp Card object to return
    int index;          //Index of card choice for temp card
    bool tryAgn=true;   //Input validation flag
    
    cin.clear();
    cin.ignore();
    //Input card choice
    cout<<"What card do you want to play?"<<endl; 
    cin>>chc;
    while(tryAgn){ //While tryAgn is true
        try{ 
            index=pCrd(disCrd, chc); //If card choice is valid set index
            tryAgn=false;            //set tryAgn to false 
        }
        catch(BadChc bad){ //If card choice is not valid, display message
            cout<<"Error: "<<bad.getChc()<<" is an invalid choice!"<<endl;
            cout<<"Enter the number that corresponds to your card choice: ";
            cin>>chc;     //Input card choice
        }
    } 
    
    //Set the Wild color
    char colChc;        //Hold Player Color Choice
    if(hand[index].getType()==WILD||hand[index].getType()==WILD4){
            colChc=chsWild();
            colChc=tolower(colChc);    //Ensure that color choice is lowercase
            hand[index].setColor(colChc);  //Change the color of discard 
    }
    
    temp=hand[chc]; //Set temp to hand at card choice index
    hand.erase(hand.begin()+chc); //Remove that card from the hand
    return temp;   //Return temp
}
//Returns the card to play
int Hplayer::pCrd(Card disCrd, int cardChc){
    int crdInd; //Hold card index to return 
    if(cin&&!cin.fail()){ //In cin is successful
        if(cardChc>=0&&cardChc<=hand.size()){//If it is a valid index
            if(valPlay(disCrd, hand[cardChc])){//If the card at index is valid
                crdInd=cardChc; //Set crdInd to card choice
                return crdInd;  //Return crdInd
            }
            else{ //If the card is not valid
                throw BadChc(cardChc); //Create BadChc object
            }
        }
        else{ //If it is not a valid index
            throw BadChc(cardChc); //Create BadChc object
       }
    }
    else{ //If cin fails
        cin.clear();    //Clear buffer
        cin.ignore();      
        throw BadChc(cardChc); //Create BadChc object
    }
}

char Hplayer::chsWild(){
    char colChc;
    bool error=false;
    do{
        cout<<"Choose A Color (r,g,b,y): "; 
        cin.clear();
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
    return colChc;
}