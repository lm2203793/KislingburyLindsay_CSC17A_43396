/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Card.h"
#include "Player.h"
#include "CPlayer.h"
#include "Type.h"
using namespace std;

Card Cplayer::getPcrd(Card disCrd){
    Card temp;
    int vecSz=0;
    vector<int> valCrds;   //valid cards indexes
    for(int i=0; i<hand.size(); i++){
        if(valPlay(disCrd,hand[i])){
            valCrds.push_back(i);
            vecSz++;
        }
    }
    switch(hardNum){ //switch on difficulty
        case 1: //completely random valid card
            int index;
            index=rand()%valCrds.size();
            temp=hand[valCrds[index]];
            hand.erase(hand.begin()+valCrds[index]);
            break;
        case 2: //picks the card that matches most common color or symbol
            int coin;
            coin=rand()%1; //match on color or symbol on coin flip
            if(coin==1){
                int *sScrs;
                scoreSym(sScrs); //determine value of each symbol (# or special card) and store in array
                int *tots;
                scrCrdsN(valCrds, sScrs, tots, vecSz); //determine value of each valid card in the hand and store in array
                int smax=0; 
                //find max card value
                for(int i=0; i<sizeof(tots); i++){
                    if(tots[i]>smax){
                        smax=i;
                    }
                    temp=hand[valCrds[smax]]; //play the card with max value
                }
            }
            else{
                int *cScrs;
                scoreClr(cScrs); //determine value of each color and store in array
                int *tots;
                scrCrdsC(valCrds, cScrs, tots, vecSz); //determine value of each valid card in the hand and store in array
                int cmax=0; 
                //find max card value
                for(int i=0; i<sizeof(tots); i++){
                    if(tots[i]>cmax){
                        cmax=i;
                    }
                    temp=hand[valCrds[cmax]]; //play the card with max value
                }
            }
            break;
        case 3: //Super Smart! Plays either the most common color or number, whatever is better
            int *sScrs;
            scoreSym(sScrs); //determine value of each symbol (# or special card) and store in array
            int *cScrs;
            scoreClr(cScrs); //determine value of each color and store in array
            int *ctots;
            scrCrdsC(valCrds, cScrs, ctots, vecSz); //determine value of each valid card in the hand and store in array
            int *stots;
            scrCrdsN(valCrds, sScrs, stots, vecSz); //determine value of each valid card in the hand and store in array
            int ttots[sizeof(ctots)]={0}; //all totals
            //add the color and symbol totals to all totals
            for(int i=0; i<sizeof(ctots); i++){
                ttots[i]+=ctots[i];
                ttots[i]+=stots[i];
            }
            //find max score
            int max=0;
            for(int i=0; i<sizeof(ttots); i++){
                if(ttots[i]>max){
                    max=i;
                }
            }
            temp=hand[valCrds[max]]; //play the card with max value
            break;
    }
    cout<<name<<" plays ";
    cout<<temp;
    return temp;
}



//pick a wild color
char Cplayer::wildPic(){
    int temp[4]={0};
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].getColor()){
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
    int cmax=rand()%3;
    //find the max
    for(int i=0; i<4; i++){
        if(temp[i]>cmax){
            temp[i]=cmax;
        }
    }
    char rChar;
    rChar=(cmax==0)?'r':
          (cmax==1)?'g':
          (cmax==2)?'b':'y';
    
    return rChar;
}

//returns 
void Cplayer::scoreSym(int *sysNums){
    int temp[13]={0};
    sysNums=temp;
    for(int i=0; i<hand.size(); i++){
        //count symbols and store them in sysNums
        switch(hand[i].getType()){
            case NUMBER:
                sysNums[hand[i].getNum()]++;
                break;
            case DRAW2:
                sysNums[11]++;
                break;     
            case SKIP:
                sysNums[12]++;
                break;
            case REVERSE:
                sysNums[13]++;
        }
    }
}

void Cplayer::scoreClr(int *colNums){
    int temp[4]={0};
    colNums=temp;
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].getColor()){
            case 'r':
                colNums[0]++;
                break;
            case 'g':
                colNums[1]++;
                break;
            case 'b':
                colNums[2]++;
                break;
            case 'y':
                colNums[3]++;
                break;
        }
    }
}
//build a score for every in card in vector of valid cards
void Cplayer::scrCrdsN(vector<int> valCrds, int *scrsN, int *symTots, int vecSz){
    int temp[vecSz];
    symTots=temp;
    for(int i=0; i<valCrds.size(); i++){
        Type type=hand[valCrds[i]].getType();
         if(type!=NUMBER){
            switch(type){
                case DRAW2:
                    symTots[i]=scrsN[11];
                    break;
                case SKIP:
                    symTots[i]=scrsN[12];
                    break;
                case REVERSE:
                    symTots[i]=scrsN[13];
                    break;
                case WILD: //only play as last resort
                case WILD4:
                    symTots[i]=0;
                    break;
            }
       }
       else{
           symTots[i]=scrsN[hand[valCrds[i]].getNum()];
        }
    }
}

//build a score for every in card in vector of valid cards
void Cplayer::scrCrdsC(vector<int> valCrds, int *scrsC, int *colTots, int vecSz){
    int temp[vecSz];
    colTots=temp;
    for(int i=0; i<valCrds.size(); i++){
        char col=hand[valCrds[i]].getColor();
        switch(col){
            case 'r':
                colTots[i]=scrsC[0];
                break;
            case 'g':
                colTots[i]=scrsC[1];
                break;
            case 'b':
                colTots[i]=scrsC[2];
                break;
            case 'y':
                colTots[i]=scrsC[3];
                break;
            case 'X':
                colTots[i]=0;
                break;
        }
    }
}
