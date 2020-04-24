#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
#include "random.h"

/*
Class: Fighter
Author: Callum M

Purpose:
    -Fighter provides an implementation of the move function to allow me to create different kinds of fighters all with the same behaviour
     and similar stats.
    -It is used as the parent class for Borc, Porc, and Dorc

Data Members:
    -All of it's data members are inherited from Character

Member Functions:
    -Fighter(name, int, int, char)
        -A default constructor to create a new fighter with a specified name, x and y position, and an avatar
    -virtual void move(int,int)
        -The overloaded move function, it moves the fighter one space left every turn until either the fighter dies or reaches the left edge (or the game ends)
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