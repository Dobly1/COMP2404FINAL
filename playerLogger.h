#ifndef PLAYERLOGGER_H
#define PLAYERLOGER_H

#include "Character.h"
#include <list>

using namespace std;

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