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
#include <string>
#include <vector>

struct Card{
    Type            type;
    short           num;
    char            color;
    string          colName;
};

struct Hands{
    vector<Card>   data;     //Data in the array
    string         player;
};

#endif /* HANDS_H */

