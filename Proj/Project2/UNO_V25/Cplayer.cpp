/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Card.h"
#include "Player.h"
#include "CPlayer.h"
#include "Type.h"
#include <vector>
using namespace std;

Card Cplayer::getPcrd(Card disCrd){
    Card temp;
    int vecSz=0;
    vector<int> valCrds;   //valid cards indexes
    cout<<"valid card indexes: ";
    for(int i=0; i<hand.size(); i++){
        if(valPlay(disCrd,hand[i])){
            valCrds.push_back(i);
            vecSz++;
        }
    }
    cout<<"valCrds: ";
    for(int i=0; i<valCrds.size(); i++){
        cout<<valCrds[i]<<" ";
    }
    cout<<endl;
    switch(hardNum){ //switch on difficulty
        case 1: //completely random valid card
            int index;
            index=rand()%valCrds.size();
            temp=hand[valCrds[index]];
            hand.erase(hand.begin()+valCrds[index]);
            break;
        case 2: //picks the card that matches most common color or symbol
            int coin;
            coin=rand()%2+1; //match on color or symbol on coin flip
            if(coin==1){
                int sScrs[14]={0};
                scoreSym(sScrs);     //determine value of each symbol (# or special card) and store in array
                int smax=scrCrdsN(valCrds, sScrs, vecSz); //determine value of each valid card in the hand and store in array
                cout<<"coin "<<coin<<endl;
                cout<<"symbol scores"<<endl;
                for(int i=0; i<14; i++){
                    cout<<sScrs[i]<<" ";
                }
                int index=valCrds[smax];
                temp=hand[index]; //play the card with max value
                int erase=valCrds[smax];
                cout<<"erase at index: "<<erase<<endl;
                hand.erase(hand.begin()+erase);
            }
            else{
                int cScrs[4]={0};
                scoreClr(cScrs); //determine value of each color and store in array
                int cmax=scrCrdsC(valCrds, cScrs, vecSz); //determine value of each valid card in the hand and store in array
                cout<<"coin "<<coin<<endl;
                cout<<"color scores"<<endl;
                for(int i=0; i<4; i++){
                    cout<<cScrs[i]<<" ";
                }
                int index=valCrds[cmax];
                temp=hand[index]; //play the card with max value
                int erase=valCrds[cmax];
                cout<<"erase at index: "<<erase<<endl;
                hand.erase(hand.begin()+erase);
            }
            break; 
        case 3: //Super Smart! Plays either the most common color or number, whatever is better
            int sScrs[14]={0};
            scoreSym(sScrs);     //determine value of each symbol (# or special card) and store in array
            int cScrs[4]={0};
            scoreClr(cScrs);    //determine value of each color and store in array
            int amax=sCrdsA(sScrs, cScrs, valCrds, vecSz);
            index=valCrds[amax];
            temp=hand[index]; //play the card with max value
            int erase=valCrds[amax];
            cout<<"symbol scores"<<endl;
                for(int i=0; i<14; i++){
                    cout<<sScrs[i]<<" ";
                }
            cout<<"color scores"<<endl;
                for(int i=0; i<4; i++){
                    cout<<cScrs[i]<<" ";
                }
            cout<<"erase at index: "<<erase<<endl;
            hand.erase(hand.begin()+erase);
            break;
    }
    cout<<name<<" plays ";
    cout<<temp;
    return temp;        
}

//choose best from symbols and colors
int Cplayer::sCrdsA(int sScrs[], int cScrs[], vector<int> valCrds, int vecSz){
    int allTots[vecSz]; 
    //get all symbol totals
    for(int i=0; i<valCrds.size(); i++){
        Type type=hand[valCrds[i]].getType();
         if(type!=NUMBER){
            switch(type){
                case DRAW2:
                    allTots[i]=sScrs[11];
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
    int cmax=0;
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
void Cplayer::scoreSym(int sScrs[]){
    for(int i=0; i<hand.size(); i++){
        //count symbols and store them in sScrs
        switch(hand[i].getType()){
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

void Cplayer::scoreClr(int cScrs[]){
    for(int i=0; i<hand.size(); i++){
        switch(hand[i].getColor()){
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
//build a score for every in card in vector of valid cards
 int Cplayer::scrCrdsN(vector<int> valCrds, int sScrs[], int vecSz){
    int symTots[vecSz]={0};
    for(int i=0; i<valCrds.size(); i++){
        Type type=hand[valCrds[i]].getType();
         if(type!=NUMBER){
            switch(type){
                case DRAW2:
                    symTots[i]=sScrs[11];
                    break;
                case SKIP:
                    symTots[i]=sScrs[12];
                    break;
                case REVERSE:
                    symTots[i]=sScrs[13];
                    break;
                case WILD: //only play as last resort
                case WILD4:
                    symTots[i]=0;
                    break;
            }
       }
       else{
           symTots[i]=sScrs[hand[valCrds[i]].getNum()];
        }
    } 
    cout<<"symbol totals: ";
    for(int i=0; i<vecSz; i++){
        cout<<symTots[i]<<" ";
    }
    cout<<endl;
    //find max card value
    
    int smax=0;
    for(int i=0; i<vecSz; i++){
        if(symTots[i]>smax){
            smax=i;
        }
    }
    cout<<"smax: "<<smax<<endl;
    return smax;
}

//build a score for every in card in vector of valid cards
int Cplayer::scrCrdsC(vector<int> valCrds, int cScrs[], int vecSz){
    int colTots[vecSz]={0};
    for(int i=0; i<valCrds.size(); i++){
        char col=hand[valCrds[i]].getColor();
        switch(col){
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
    //find max card value
    int cmax=0;
    for(int i=0; i<vecSz; i++){
        if(colTots[i]>cmax){
            cmax=i;
        }
    }
    cout<<"cmax: "<<cmax<<endl;
    return cmax;
}
