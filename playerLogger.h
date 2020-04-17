#ifndef PLAYERLOGGER_H
#define PLAYERLOGER_H

#include "Character.h"
#include <list>

using namespace std;

/*
Class: 
Author: Callum M

Purpose:
    -Player logger is a logger that keeps track of players and sends any useful information such as winning back to the game
    -It also decides whether or not a program should keep running or end dependig if htere are any winners

Data Members:
    -list<Character*> players
        -This is a list of all the players contained in the game, they are subscribed when they are created
    -int emCaveX
        -The X location of the emerald cave entrance
    -int emCaveYStart
        -The beginning to the entrance of the emerald cave Y location
    -int 

Member Functions:
    -

*/


class playerLogger
{
    public:
    //Needs to Know: Winning Location
    playerLogger(int=24,int=1,int=3);
    
    //So the program can decide to keep running
    void keepRunning(bool&);

    //Adds a player to the logger
    void subscribe(Character*&);

    //Returns winner if neccessary, null otherwise
    void getWinner(Character*&);

    private:
    list<Character*> players;   
    int emCaveX;
    int emCaveYStart;
    int emCaveYSize;

};


#endif