#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "random.h"

/*
Class: Player
Author: Callum M

Purpose:
    -Represents a player entity in the game
    -Allows complete customization of the character's stats to make Character creation easier
    -Overrides the move function so players can move in the right direction

Data Members:
    -No unique data members, they're all inherited from Character

Member Functions:
    -Player(std::string,int,int,int,int,char)
        -The default Player constructor that allows most information to be provided, only the Y position is randomly generated as per the specs
    -virtual void move(int,int)
        -The overrided move function moves the player to the right every turn and a random Y direction, if it hits the upper or lower border then
         it places them adjacent, and it keeps moving them till they either die or reach the cave entrance  

*/

class Player:public Character
{
    public:         
        //(Name, Strength, Armour, Health, xPos, yPos, Avatar)
        Player(std::string = "Default", int = 10, int = 10, int = 10, int = 0, char = 'P');
        virtual void move(int,int);
};



#endif