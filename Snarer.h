#ifndef SNARER_H
#define SNARER_H

#include "Seeker.h"

/*
Class: 
Author: Callum M

Purpose:
    -

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