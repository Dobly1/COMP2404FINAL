#ifndef SEEKER_H
#define SEEKER_H

#include "PathFinding.h"
#include "Character.h"

/*
Class: Seeker 
Author: Callum M

Purpose:
    -Seeker is a class of monster that have a variety of abilities and seek out a player, so instead of moving
    randomly they go directly towards a player
    -They're characters so they have all the lovely data members and functions that come with that

Data Members:
    -PathFinding* path
        -This instance of the path finding object contains a Player that the seeker is looking for, it is used to get a direction to move in

Member Functions:
    -Seeker(PathFinding*)

*/

class Seeker:public Character
{
    public:
    Seeker(PathFinding*, std::string = "Seeker", int = 0, int = 0, char = 'S');
    virtual ~Seeker();

    virtual void move(int,int);
    
    private:
    PathFinding* path;

};

#endif