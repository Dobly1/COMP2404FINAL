#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
#include "random.h"

/*
Class: 
Author: Callum M

Purpose:
    -A direct derivation of Character class
    -Implements its own unique movement behaviour of pacing infront of the cave
    -In order to have the dragon instantly kill the player, I spawn it with all stats maxed at 999, effectively killing any player it comes in contact with

Data Members:
    -int direction
        -An int that is used to tell the dragon to either move up or down, and is upated when it reaches one of the cave borders, it is needed as a sort of
         memory so the dragon always knows which way to pace
    -int emCaveStart
        -The starting Y location of the emerald cave so the dragon knows where to guard
    -int emCaveSize
        -The size of the emerald cave, so the dragon knows how far from the top to pace

Member Functions:
    -Dragon(int,int,int,int)
        -Spawns the dragon at his initial starting location

*/


class Dragon:public Character
{

    public:
    Dragon(int=0, int=0, int=0, int=0);
    virtual void move(int,int);

    private:
    int direction;
    int emCaveStart;
    int emCaveSize;



};



#endif