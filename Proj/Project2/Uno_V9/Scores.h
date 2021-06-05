/* 
 * File:   Scores.h
 * Author: Lindsay Kislingbury
 * Purpose: Structure to hold end game scores
 * Created on June 1, 2021, 5:15 PM
 */

#ifndef SCORES_H
#define SCORES_H

class Scores{
private:
    int            gmScr;   //Ending Game Score
    int            lrgHnd,  //Largest Hand 
                   numHnds; //Number of Hands Played
    bool           winner;  //Hold Win Status
    vector<int>    hndSzs;  //Hold the size of every hand played
    
    ///GAME SCORES
    char            winner[25]; //Name of the game winner
    int             numHnds;    //Total number of hands played 
    int             lrgHnd;     //Single largest hand played
    int             score;      //Winner score
    int             numPlyrs;   //Number of players 
public:
    
};


#endif /* SCORES_H */

