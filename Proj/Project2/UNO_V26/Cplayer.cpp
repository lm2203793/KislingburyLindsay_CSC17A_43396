/* 
 * File:   Card.h
 * Author: Lindsay Kislingbury
 * Purpose: Cplayer Member Functions
 * Created on June 5, 2021, 4:12 PM
 */
#include "Card.h"
#include "Player.h"
#include "CPlayer.h"
#include "Type.h"
#include <vector>
using namespace std;

//Overloaded version of getPcrd
Card Cplayer::getPcrd(Card &disCrd){
    Card temp;             //Card object to return
    vector<int> valCrds;   //Valid card indexes
    int vecSz=0;           //Size of valid card vector
    //Fill vector with valid cards
    for(int i=0; i<hand.size(); i++){
        if(valPlay(disCrd,hand[i])){
            valCrds.push_back(i);
            vecSz++;
        }
    }
    switch(hardNum){ //Switch on difficulty
        case 1: //Dumb Bot (completely random choices)
            int index;
            index=rand()%valCrds.size(); //Index is random
            temp=hand[valCrds[index]];   //Set temp to a random valid card
            hand.erase(hand.begin()+valCrds[index]); //Remove from hand
            break;
        case 2: //Lucky Bot (Best color choice or symbol choice)
            int coin;
            coin=rand()%2+1; //Choose based on color or symbol on coin flip
            if(coin==1){ //If 1, choose best card based on symbol (# and type)
                int sScrs[14]={0};//Hold the value of each valid card
                scoreSym(sScrs);  //Calculate the values based on symbol
                int smax=scrCrdsN(valCrds, sScrs, vecSz); //Find the best card
                int index=valCrds[smax]; 
                temp=hand[index]; //Set temp to the best card in hand
                int erase=valCrds[smax];
                hand.erase(hand.begin()+erase); //Remove that card from hand
            }
            else{ //If 2, choose best card based on color
                int cScrs[4]={0};//Hold the value of each valid card
                scoreClr(cScrs); //Calculate the values based on color
                int cmax=scrCrdsC(valCrds, cScrs, vecSz); //Find the best card
                int index=valCrds[cmax];
                temp=hand[index]; //Set temp to the best card in hand
                int erase=valCrds[cmax];
                hand.erase(hand.begin()+erase); //Remove that card from hand
            }
            break; 
        case 3: //Smart Bot (Best choice based on color AND symbol)
            int sScrs[14]={0};  //Hold the value of each valid card by symbol
            scoreSym(sScrs);    //Calculate the value based on symbol
            int cScrs[4]={0};   //Hold the value of each valid card by color
            scoreClr(cScrs);    //Calculate the value based on color
            int amax=sCrdsA(sScrs, cScrs, valCrds, vecSz); //Find the best card
            index=valCrds[amax];
            temp=hand[index];  //Set temp to the best card in hand
            int erase=valCrds[amax];
            hand.erase(hand.begin()+erase); //Remove that card from hand
            break;
    }
    
    //Set wild color
    char wCol;
    wCol=chsWild();        //Choose best wild color
    temp.setColor(wCol);   //Set color of temp card object
    cout<<name<<" plays "; //Display choice
    cout<<temp;           
    return temp;           //Return temp Card object
}

//Assigns a value to each playable card in the player's hand
//Number, type, and color
int Cplayer::sCrdsA(int sScrs[], int cScrs[], vector<int> valCrds, int vecSz){
    int allTots[vecSz]; 
    //Get all symbol card values
    for(int i=0; i<valCrds.size(); i++){
        Type type=hand[valCrds[i]].getType();
         if(type!=NUMBER){ //Switch on card type
            switch(type){
                case DRAW2: 
                    allTots[i]=sScrs[11]; //value to totals
                    break;
                case SKIP:
                    allTots[i]=sScrs[12];
                    break;
                case REVERSE:
                    allTots[i]=sScrs[13];
                    break;
                case WILD: //only play as last resort
                case WILD4:
                    allTots[i]=0;
                    break;
            }
       }
       else{
           allTots[i]=sScrs[hand[valCrds[i]].getNum()];
        }
    }
    //get all color totals
    for(int i=0; i<valCrds.size(); i++){
    char col=hand[valCrds[i]].getColor();
    switch(col){
        case 'r':
            allTots[i]+=cScrs[0];
            break;
        case 'g':
            allTots[i]+=cScrs[1];
            break;
        case 'b':
            allTots[i]+=cScrs[2];
            break;
        case 'y':
            allTots[i]+=cScrs[3];
            break;
        case 'X':
            allTots[i]+=0;
            break;
    }
    int amax;
    for(int i=0; i<vecSz; i++){
        if(allTots[i]>amax){
            amax=i;
        }
    }
    return amax;
}
    
    
    
}

//pick a wild color
char Cplayer::chsWild(){
    int temp[4]={0}; //Hold card values
    //Loop on hand size, increment each color that appears in the hand
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].getColor()){ //Switch on color
            case 'r':
                temp[0]++;
                break;
            case 'g':
                temp[1]++;
                break;
            case 'b':
                temp[2]++;
                break;
            case 'y':
                temp[3]++;
                break;
        }
    }
    //Find max value
    int cmax=0; 
    for(int i=0; i<4; i++){
        if(temp[i]>cmax){
            temp[i]=cmax;
        }
    }
    char rChar; //Hold color that appears most in hand
    rChar=(cmax==0)?'r':
          (cmax==1)?'g':
          (cmax==2)?'b':'y';
    //Return best color
    return rChar;
}

//Assigns a value to each symbol(# or type)
void Cplayer::scoreSym(int sScrs[]){
    //Increment value +2 for each type in hand, prefer these
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].getType()){ //Switch on type
            case NUMBER:
                sScrs[hand[i].getNum()]++;
                break;
            case DRAW2:
                sScrs[11]+=2;      
                break;     
            case SKIP:
                sScrs[12]+=2;
                break;
            case REVERSE:
                sScrs[13]+=2;
        }
    }
}
//Assigns a value to each color
void Cplayer::scoreClr(int cScrs[]){
    //Increment value for each color in hand
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].getColor()){//Switch on color
            case 'r':
                cScrs[0]++;
                break;
            case 'g':
                cScrs[1]++;
                break;
            case 'b':
                cScrs[2]++;
                break;
            case 'y':
                cScrs[3]++;
                break;
        }
    }
    cout<<endl;
}
//Assigns a value to each playable card in the player's hand
//For number and type
 int Cplayer::scrCrdsN(vector<int> valCrds, int sScrs[], int vecSz){
    int symTots[vecSz]={0}; //Hold values for each symbol card in hand
    //Loop through valid cards, store the value for each symbol
    for(int i=0; i<valCrds.size(); i++){
        Type type=hand[valCrds[i]].getType();
         if(type!=NUMBER){ //If not a NUMBER type, store the value in sScrs
            switch(type){  //Switch on type
                case DRAW2:
                    symTots[i]=sScrs[11];
                    break;
                case SKIP:
                    symTots[i]=sScrs[12];
                    break;
                case REVERSE:
                    symTots[i]=sScrs[13];
                    break;
                case WILD: //Wild is 0, only play as last resort
                case WILD4:
                    symTots[i]=0;
                    break;
            }
       }
         else{ //If NUMBER type, store the face number 
            symTots[i]=sScrs[hand[valCrds[i]].getNum()];
        }
    } 
    //Find max symbol value
    int smax=0;
    for(int i=0; i<vecSz; i++){
        if(symTots[i]>smax){
            smax=i;
        }
    }
    return smax;
}

//Assigns a value to each playable card in the player's hand
//For color
int Cplayer::scrCrdsC(vector<int> valCrds, int cScrs[], int vecSz){
    int colTots[vecSz]={0}; //Hold values for each color card in hand
    //Loop through valid cards, store the value for each color
    for(int i=0; i<valCrds.size(); i++){
        char col=hand[valCrds[i]].getColor();
        switch(col){ //Switch on color
            case 'r':
                colTots[i]=cScrs[0];
                break;
            case 'g':
                colTots[i]=cScrs[1];
                break;
            case 'b':
                colTots[i]=cScrs[2];
                break;
            case 'y':
                colTots[i]=cScrs[3];
                break;
            case 'X':
                colTots[i]=0;
                break;
        }
    }
    //Find max color value
    int cmax=0;
    for(int i=0; i<vecSz; i++){
        if(colTots[i]>cmax){
            cmax=i;
        }
    }
    return cmax;
}
