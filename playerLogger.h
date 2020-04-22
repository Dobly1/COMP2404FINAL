#ifndef PLAYERLOGGER_H
#define PLAYERLOGER_H

#include "Character.h"
#include "LList.h"

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
    -int emCaveYSize
        -The size in units of the Emerald cave from the beggining Y coordinate

Member Functions:
    -playerLogger(int,int,int)
        -The default constructor for the class, takes in the size of the map, and the emerald locations
    -void keepRunning(bool&)
        -Decides whether to keep the game runnning, and changes the bool depending
            -Looks at, if the players are alive or standing in the winning position
    -void subscribe(Character*&)
        -Subscribes a new player to the playerLogger and adds it to the list of players
    -getWinner(Character*&)
        -After a game is finished this function returns the first player to be standing in the winning position
        If no one wins it returns Null in the parameter

*/


class playerLogger
{
    public:
    //Needs to Know: Winning Location
    playerLogger(int=24,int=1,int=3);
    
    //So the program can decide to keep running
    void keepRunning(bool&);
    void keepRunning2(bool&);

    //Adds a player to the logger
    void subscribe(Character*&);

    //Returns winner if neccessary, null otherwise
    void getWinner(Character*&);
    void getWinner2(Character*&);

    private:
    LList<Character> players2;
    int emCaveX;
    int emCaveYStart;
    int emCaveYSize;

};


#endif