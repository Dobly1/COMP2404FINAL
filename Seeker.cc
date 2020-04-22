#include "Seeker.h"

Seeker::Seeker(PathFinding* p, std::string name, int x, int y, char av):Character(name, 0, 5, x, y, av, true),path(p)
{
}

Seeker::~Seeker()
{
    delete path;
}

void Seeker::move(int maxX, int maxY)
{


    //Don't move if you're dead
    if(!alive)
        return;

    int direcY, direcX;

    path->getDirection(xPos, yPos, direcY, direcX);


    //Move Seeker appropriately
    yPos += direcY;
    
    if(!direcX)
        xPos -= 1;


    //Check bounds
    if(xPos <= 0)
    {
        xPos = 0;
        kill();
    }
    if(xPos >= maxX)
        xPos = maxX-1;


    if(yPos <= 0)
        yPos = 0;

    if(yPos >= maxY)
        yPos = maxY -1;

}
