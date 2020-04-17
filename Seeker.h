#ifndef SEEKER_H
#define SEEKER_H

#include "PathFinding.h"
#include "Character.h"

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

class Seeker:public Character
{
    public:
    Seeker(PathFinding*, std::string = "Seeker", int = 0, int = 0, char = 'S');
    ~Seeker();

    virtual void move(int,int);
    
    private:
    PathFinding* path;

};

#endif