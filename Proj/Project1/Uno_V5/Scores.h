/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scores.h
 * Author: linds
 *
 * Created on May 13, 2021, 3:28 PM
 */



#ifndef SCORES_H
#define SCORES_H
#include <string>

struct GameScrs{
    int             gmNum;
    int             gmScr;
    int             lrgHnd;
    vector<int>     hndSzs;
};

struct Scores{
    string              player;
    int                 nWins,
                        nLoses,
                        highScr,
                        avgScr,
                        nGames,
                        highHnd;
    
};


#endif /* SCORES_H */

