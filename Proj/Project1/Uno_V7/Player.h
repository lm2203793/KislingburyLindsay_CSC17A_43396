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
    Type            type;
    short           num;
    char            color;
    string          colName;
    int             points;
};

struct GameScrs{
    int             gmScr;
    int             lrgHnd;
    bool            winLoose=false;
    vector<int>     hndSzs;
};

struct Player{
    vector<Card>   data;     //hand of cards
    string         player;
    GameScrs       scores;
};

#endif /* HANDS_H */

