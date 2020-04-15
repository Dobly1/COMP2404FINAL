#include "playerLogger.h"

playerLogger::playerLogger(int x, int y, int size):emCaveX(x),emCaveYStart(y),emCaveYSize(size)
{
    //Nothing here :(
}

void playerLogger::subscribe(Character*& c)
{
    players.push_back(c);
}

void playerLogger::keepRunning(bool& returnVal)
{
    list<Character*>::iterator it;

    //Start off with a value of false, and only true 
    returnVal = false;

    int x,y;

    for(it = players.begin(); it != players.end(); ++it)
    {
        //Check if players are alive first and formost
        if((*it)->isAlive())
            returnVal = true;

        //Check if anyone has reached the victory line
        (*it)->getPos(x,y);

        //If someone has reached the emerald then we should immdieatly end the game
        if( x == emCaveX && ( y >= emCaveYStart && y <= (emCaveYStart + emCaveYSize-1)) && (*it)->isAlive() )
        {
            returnVal = false;
            return;
        }
    }        
}

void playerLogger::getWinner(Character*& winner)
{
    list<Character*>::iterator it;

    winner = NULL;

    int x,y;

    for(it = players.begin(); it != players.end(); ++it)
    {    
        //Check if anyone has reached the victory line
        (*it)->getPos(x,y);

        //If someone has reached the emerald then we should immdieatly end the game
        if( x == emCaveX && ( y >= emCaveYStart && y <= (emCaveYStart + emCaveYSize-1)) && (*it)->isAlive() )
        {
            winner = (*it);
            return;
        }
    } 
}