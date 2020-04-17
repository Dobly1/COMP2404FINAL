#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
#include "random.h"

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


class Fighter:public Character
{
    public:
    //Fighter(name,health,avatar)
    Fighter(std::string="Fighter",int=10,int=10,char='F');
    virtual void move(int,int);

    private:
    

};


#endif