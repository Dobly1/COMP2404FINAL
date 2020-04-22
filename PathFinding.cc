#include "PathFinding.h"

PathFinding::PathFinding(list<Character*>& entities)
{
    //Randomly find a player
    int start = random(entities.size()-1);

    list<Character*>::iterator it = entities.begin();

    //Iterate it forward a random number of times to ensure random selection
    for(int i = 0; i < start; i++)
        ++it;

    //Make sure we haven't gone too far
    if(it == entities.end())
        it = entities.begin();

    int s = entities.size();

    for(int i = 0; i < s; i++)
    {
        if(it == entities.end())
            it = entities.begin();

        //See if current object is a player
        if( !(*it)->isFightable() && (*it)->isAlive() )
        {
            tracked = (*it);
            return;
        }

        //If we reach the end, go back to the start
        if(it == entities.end()){
            it = entities.begin();
            continue;
        }
            

        //Iterate forward
        ++it;        
    }

    //If for whatever reason the program doesn't find anyone to track (Shouldn't happen), ensures that tracked points to NULL
    tracked = NULL;

}

PathFinding::~PathFinding()
{
}

//Send which direction to go to the new seeker class
void PathFinding::getDirection(int& curX, int& curY, int& newDirec, int& moveX)
{
    if(tracked == NULL)
    {
        newDirec = 0;
        moveX = 0;
    }

    if( !tracked->isAlive() )
    {
        newDirec = 0;
        moveX = 0;
    }  

    int trackedX, trackedY;

    tracked->getPos(trackedX, trackedY);

    //If the tracked player skips past the tracker we don't care about direction
    if(trackedX > curX)
    {
        newDirec = 0;
        moveX = 0;
        return;
    }
        
    //Determine the Y
    if(trackedY > curY)
        newDirec = 1;

    if(trackedY < curY)
        newDirec = -1;

    if(trackedY == curY)
        newDirec = 0;


    if(trackedX - curX <=2 && trackedX - curX >= 0)
        moveX = 1;
    else
        moveX = 0;
    

}