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
    -Seeker(PathFinding*, std::string, int, int, char)
        -The constructor used to create a seeker with all the basic information needed as well as the PathFinding object
         that seekers need for their basic functionality
    -virtual ~Seeker()
        -The virtual destructor that is needed as path is a dynamically allocated object and needs to be freed when
         a seeker is removed, has to be virtual so Character constructor isn't called
    -virtual void move(int,int)
        -The overriden move function defines how a seeker moves, in this situation it uses path to get a direction that
         it should move in, and then pause moving in the X-direction when the player is within 2 places to ensure that
         a collision occurs.

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