#ifndef PORC_H
#define PORC_H

#include "Fighter.h"

/*
Class: Porc
Author: Callum M

Purpose:
    -Porc creates a new Porc that is a fighter with a certain amount of strength
    -It inherits everything from Fighter

Data Members:
    -No unique data members, other than those inherited from Fighter

Member Functions:
    -Porc(int,int)
        -Just the default constructor to create a Porc with a strength in the required range

*/

class Porc:public Fighter
{
    public:
        Porc(int=10,int=0);

};


#endif