/* 
 * File:   Game.h
 * Author: Lindsay Kislingbury
 * Purpose: UNO V10
 * Created on June 1, 2021, 9:36 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Deck.h"
#include "Player.h"
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {

    Deck deck;
    Player plyr(1, deck.deal());
    plyr.getCard(2);
    
  
    
    
    return 0;
}

