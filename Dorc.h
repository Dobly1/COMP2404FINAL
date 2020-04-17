#ifndef DORC_H
#define DORC_H

#include "Fighter.h"

/*
Class: Dorc
Author: Callum M

Purpose:
    -A derivation of the fighter class, so it has all the same movement behaviour and base health
    -Contains all the attributes and functions of Character and Fighter classes

Member Functions:
    -Dorc(int,int)
        -A constructor to initalize a dorc at a specific position and generate a random strength value in the proper range

*/


class Dorc:public Fighter
{
    public:
    Dorc(int=0,int=0);
    

};




#endif