/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Player.h"
#include "Type.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Player.h"
#include "Cplayer.h"
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
        case 1: //completely random
            int index;
            index=rand()%valCrds.size();
            temp=hand[index];
            hand.erase(hand.begin()+index);
            break;
        case 2:
            int coin;
            coin=rand()%1;
            if(coin==1){
                
            }
            break;
    }
}

void Cplayer::something(vector<int> valCrds){
    int sysNums[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<valCrds.size(); i++){
        switch(hand[valCrds[i]].getType()){
            case NUMBER:
                sysNums[valCrds[i].getNum()]++;
                break;
            case 1:
                break;
            case DRAW2:
                break;     
        }
    }
}
