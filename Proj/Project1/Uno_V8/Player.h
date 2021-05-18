/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hands.h
 * Author: linds
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

