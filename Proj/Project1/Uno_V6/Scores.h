/* 
 * File:   Scores.h
 * Author: Lindsay Kislingbury
 * Purpose: Structure to hold end game scores
 * Created on May 13, 2021, 3:28 PM
 */

#ifndef SCORES_H
#define SCORES_H

struct Scores{
    char            winner[25]; //Name of the game winner
    int             numHnds;    //Total number of hands played 
    int             lrgHnd;     //Single largest hand played
    int             score;      //Winner score
    int             numPlyrs;   //Number of players 
};


#endif /* SCORES_H */

