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
    vector<int> valCrds;   //valid cards indexes
    for(int i=0; i<hand.size(); i++){
        if(valPlay(disCrd,hand[i])){
            valCrds.push_back(i);
        }
    }
    switch(hardNum){ //switch on difficulty
        case 1: //completely random valid card
            int index;
            index=rand()%valCrds.size();
            temp=hand[index];
            hand.erase(hand.begin()+index);
            break;
        case 2: //picks the card that matches most common color or symbol
            int coin;
            coin=rand()%1; //match on color or symbol on coin flip
            if(coin==1){
               int max=findMaxN(valCrds);
               if(max>10){
                   switch(max){
                       case 11:
                           temp=hand[fndMchSym(DRAW2, valCrds)];
                           break;
                       case 12:
                           temp=hand[fndMchSym(SKIP, valCrds)];
                           break;
                       case 13:
                           temp=hand[fndMchSym(REVERSE, valCrds)];
                           break;
                       case 14:
                           temp=hand[fndWild(valCrds)];
                           break;
                   }
               }
               else{
                   temp=hand[fndMchSym(max, valCrds)];
               }
            }
            else{
                int max=fndMaxC(valCrds);
                switch(max){
                    case 0:
                        temp=hand[fndMtchC(valCrds, 'r')];
                        break;
                    case 1:
                        temp=hand[fndMtchC(valCrds, 'g')];
                        break;
                    case 2:
                        temp=hand[fndMtchC(valCrds, 'b')];
                        break;
                    case 3:
                        temp=hand[fndMtchC(valCrds, 'y')];
                        break;
                }
            }
            break;
        case 3: //Super Smart! Plays either the most common color or number, whatever is better
            int maxC=fndMaxC(valCrds); //most common color
            int maxN=findMaxN(valCrds); //most common number
            if(maxN>maxC){
                if(maxN>10){
                    switch(maxN){
                        case 11:
                            temp=hand[fndMchSym(DRAW2, valCrds)];
                            break;
                        case 12:
                            temp=hand[fndMchSym(SKIP, valCrds)];
                            break;
                        case 13:
                            temp=hand[fndMchSym(REVERSE, valCrds)];
                            break;
                        case 14:
                            temp=hand[fndWild(valCrds)];
                            break;
                    }
               }
               else{
                   temp=hand[fndMchSym(maxN, valCrds)];
                }
            }
            else{
                switch(maxC){
                case 0:
                    temp=hand[fndMtchC(valCrds, 'r')];
                    break;
                case 1:
                    temp=hand[fndMtchC(valCrds, 'g')];
                    break;
                case 2:
                    temp=hand[fndMtchC(valCrds, 'b')];
                    break;
                case 3:
                    temp=hand[fndMtchC(valCrds, 'y')];
                    break;
                }
            }
        break;
    }
    cout<<name<<" plays "<<endl;
    cout<<temp;
    return temp;
}

//find the most common symbol in the valid cards
int Cplayer::findMaxN(vector<int> valCrds){
    int sysNums[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<valCrds.size(); i++){
        //count symbols and store them in sysNums
        switch(hand[valCrds[i]].getType()){
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
    //get largest number in sysNums
    int max=0;
    for(int i=0; i<13; i++){
        if(sysNums[i]>max){
            max=sysNums[i];
        }
    }
    if(sysNums[max]==0){
        return 14;
    }
    return max;
}

//find matching number
int Cplayer::fndMchSym(int max, vector<int> valCrds){
    for(int i=0; i<valCrds.size(); i++){
        if(hand[valCrds[i]].getNum()==max){
            return valCrds[i];
        }
    }
}

//find matching type
int Cplayer::fndMchSym(Type type, vector<int> valCrds){
    for(int i=0; i<valCrds.size(); i++){
        if(hand[valCrds[i]].getType()==type){
            return valCrds[i];
        }
    }
}

//find a wild
int Cplayer::fndWild(vector<int> valCrds){
    for(int i=0; i<valCrds.size(); i++){
        if(hand[valCrds[i]].getType()==WILD||hand[valCrds[i]].getType()==WILD4){
            return valCrds[i];
        }
    }
} 

//find a matching color
int Cplayer::fndMaxC(vector<int> valCrds){
    int colNums[4]={0,0,0,0};
    for(int i=0; i<valCrds.size(); i++){
        switch(hand[valCrds[i]].getColor()){
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
    //get largest number in sysNums
    int max=0;
    for(int i=0; i<4; i++){
        if(colNums[i]>max){
            max=colNums[i];
        }
    }
    return max;  
}

//Find matching color
int Cplayer::fndMtchC(vector<int> valCrds, char max){
    for(int i=0; i<valCrds.size(); i++){
        if(hand[valCrds[i]].getColor()==max){
            return valCrds[i];
        }
    }
}