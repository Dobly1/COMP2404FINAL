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
    -

Member Functions:
    -

*/


class Snarer:public Seeker
{
    public:
    Snarer(PathFinding*, int, int);
    virtual void hit(Character*);

};

#endif