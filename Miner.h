#ifndef MINER_H
#define MINER_H

#include "PathFinding.h"
#include "Seeker.h"

/*
Class: 
Author: Callum M

Purpose:
    -Provide a standard definiton of what a Miner type monster is
    -It is derived from Seeker and thus seeks out the player when it moves and contains all of Seekers attributes

Data Members:
    -It has no unique data members that aren't contained already in Seeker

Member Functions:
    -Miner(PathFinding*,int,int)
        -The deault constructor to create a Miner with a new PathFinding object and X and Y information provided as well
*/

class Miner:public Seeker
{
    public:
    Miner(PathFinding*,int,int);
    
};




#endif