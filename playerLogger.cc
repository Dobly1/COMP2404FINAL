#include "playerLogger.h"

playerLogger::playerLogger(int x, int y, int size):emCaveX(x),emCaveYStart(y),emCaveYSize(size)
{
    //Nothing here :(
}

void playerLogger::subscribe(Character*& c)
{
    //players.push_back(c);
    players2.add(c);
}

void playerLogger::keepRunning(bool& returnVal)
{
    int size = players2.getSize();

    returnVal = false;

    int x,y;

    for(int i = 0; i < size; i++)
    {
        Character* curPlayer = players2.get(i);

        if(curPlayer->isAlive())
            returnVal = true;

        curPlayer->getPos(x,y);

        if( x == emCaveX && ( y >= emCaveYStart && y <= (emCaveYStart + emCaveYSize-1)) && curPlayer->isAlive() )
        {
            returnVal = false;
            return;
        }

    }

}

void playerLogger::getWinner(Character*& winner)
{
    int size = players2.getSize();

    winner = NULL;

    int x,y;

    //Iterate over all characters for all possible win conditions
    for(int i = 0; i < size; i++)
    {
        Character* curPlayer = players2.get(i);

        curPlayer->getPos(x,y);

        //If someone has reached the emerald then we should immdieatly end the game
        if( x == emCaveX && ( y >= emCaveYStart && y <= (emCaveYStart + emCaveYSize-1)) && curPlayer->isAlive() )
        {
            winner = curPlayer;

            return;
        }
    }
}