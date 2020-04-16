#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <list>
#include "Character.h"
#include "Player.h"
#include "random.h"

using namespace std;

class PathFinding
{
    public:
    PathFinding(list<Character*>);

    void getDirection(int&,int&,int&,int&);

    private:
    Character* tracked;





};

#endif