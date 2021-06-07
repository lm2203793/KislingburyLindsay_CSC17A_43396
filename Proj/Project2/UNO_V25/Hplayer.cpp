/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Player.h"
#include "Hplayer.h"
#include "Type.h"
using namespace std;

Card Hplayer::getPcrd(Card disCrd){
    int cardChc;
    Card temp;
    bool error=false;         //Input val flag 
    
    do{                 //Input Validation Loop 
       error=false;     //Reset Input Validation Flag
       cin.clear();
       cin.ignore();
       cout<<"What card do you want to play?"<<endl;
       cin>>cardChc;
       if(cardChc<0||cardChc>hand.size()||!cin||cin.fail()){//Validate Play
           error=true;
           cout<<"Invalid Choice!"<<endl;
       }
       else{
            temp=hand[cardChc];
            if(valPlay(disCrd, temp)){
                hand.erase(hand.begin()+cardChc);
                return temp;
            }
            else{
                cout<<"Not a Valid Card!"<<endl;
                error=true;
            }
       }
    }while(!cin||cin.fail()||error);
}
