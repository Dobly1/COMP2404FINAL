#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <list>
#include "Character.h"
#include "Player.h"
#include "random.h"

using namespace std;

/*
Class: PathFinding
Author: Callum M

Purpose:
    -PathFinding objects keep track of a player and provide a direction to the player from a monster
    -It calculates which Y direction should be moved to get there
    -It stops monsters from moving in the X direction when they get within 2 blocks to ensure that the monster hits the player

Data Members:
    -Character* tracked
        -This is the character that this specific object is tracked,

Member Functions:
    -PathFinding(list<Character>&)
        -This is the constructor that takes in a list of Characters and randomly selects a player to be tracked
    -void getDirection(int&,int&,int&,int&)
        -This takes in a set of coordinates and returns which direction a character should move to meet the player

*/


class PathFinding
{
    public:
        PathFinding(list<Character*>&);
        ~PathFinding();
        void getDirection(int&,int&,int&,int&);

    private:
        Character* tracked;

};

#endif