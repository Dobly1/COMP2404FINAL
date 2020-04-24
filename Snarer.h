#ifndef SNARER_H
#define SNARER_H

#include "Seeker.h"

/*
Class: Snarer 
Author: Callum M

Purpose:
    -Snarer is a class of monster that doesn't actually do damage, but instead it "snares" the player keeping
    them in their current location for 1 move
    -It's represented by an s on the map
    -It inherits everything that Seeker contains

Data Members:
    -Snarer inherits all data members from Seeker and has no unique one's of it's own

Member Functions:
    -Snarer(PathFinding*,int,int)
        -The default constructor to create a Snarer object with a PathFinding object and x and y information
    -virtual void hit(Character*)
        -It overrides hit as instead of doing damage, it snares the player and stops them for moving for a turn
         so it made sense to change the behaviour

*/


class Snarer:public Seeker
{
    public:
        Snarer(PathFinding*, int, int);
        virtual void hit(Character*);

};

#endif