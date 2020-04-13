#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "random.h"


class Player:public Character
{

    public:         
           //(Name, Strength, Armour, Health, xPos, yPos, Avatar)
    Player(std::string = "Default", int = 10, int = 10, int = 10, int = 0, char = 'P');
    virtual void move(int,int);

    private:
    //




};



#endif