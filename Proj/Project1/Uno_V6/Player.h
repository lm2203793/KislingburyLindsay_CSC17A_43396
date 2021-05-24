
/* 
 * File:   Hands.h
 * Author: Lindsay Kislingbury
 * Purpose: Structures for handling player data
 *          Card, Player
 *
 * Created on May 8, 2021, 3:15 PM
 */

#ifndef HANDS_H
#define HANDS_H

struct Card{
    Type            type;    //Type of Card
    short           num;     //Number 
    char            color;   //Color
    string          colName; //Color Name
    int             points;  //Points
};


struct Player{
    vector<Card>   data;    //Hand of Cards
    string         player;  //Player Name
    int            gmScr;   //Ending Game Score
    int            lrgHnd,  //Largest Hand 
                   numHnds; //Number of Hands Played
    bool           winner;  //Hold Win Status
    vector<int>    hndSzs;  //Hold the size of every hand played
};

#endif /* HANDS_H */

