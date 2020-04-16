#include "PathFinding.h"

PathFinding::PathFinding(list<Character*> entities)
{
    //Randomly find a player
    int start = random(entities.size()-1);

    list<Character*>::iterator it = entities.begin();

    //Iterate it forward a random number of times to ensure random selection
    for(int i = 0; i < start; i++)
        ++it;

    while(1)
    {
        //See if current object is a player
        if( !(*it)->isFightable() )
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

}

//Send which direction to go to the new seeker class
void PathFinding::getDirection(int& curX, int& curY, int& newDirec, int& moveX)
{
    int trackedX, trackedY;

    cout << "Currently Tracking: " << tracked->getAvatar() << endl;

    tracked->getPos(trackedX, trackedY);

    //If the tracked player skips past the tracker we don't care about direction
    if(trackedX > curX)
    {
        newDirec = 0;
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